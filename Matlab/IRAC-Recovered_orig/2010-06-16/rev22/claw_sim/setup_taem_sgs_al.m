
% set defaults for tables for applications where TAEM is not used
% or tables are loaded on-the-fly
if(isempty(HACcase))
    
    BAI_version = get_value('BAI_version','onerror',5);
    
    BAI_root = fullfile('..','BAI') ;
    
    switch(BAI_version)
        case 0
            BAI_dir = fullfile(BAI_root,'version0') ;
        case 3
            BAI_dir = fullfile(BAI_root,'version2') ;
        case 4
            BAI_dir = fullfile(BAI_root,'version3') ;
        case 5
            BAI_dir = fullfile(BAI_root,'version5') ;
    end
    
    % set real HACcase
    HACcase = get_value('HACcase') ;
    
    % default sizes allow on-the-fly TAEM traj load
    %         tbl_eow_size = 2048 ; % value prior to version 5
    tbl_eow_size = 4000 ; % this should agree with size(ref_trajectory,1)
    tbl_X_size = 1048 ; % this should agree with NintAL set in BAI code

    % if not using TAEM, or using on-the-fly, set default values for tables
    % required by the sim
    if(isempty(HACcase) || (isnumeric(HACcase) && ~HACcase))
        if(isinf(assertion_time))
            tbl_eow_size = 2 ;
            tbl_X_size = 2 ;
        else
            if(isempty(HACcase))
                assertion_time = inf ;
                warning('HACcase is empty, setting assertion_time to inf')
            else
                config.pos_cmd_fw = zeros(tbl_eow_size,5) ;
            end
        end

        tbl_eow = [1:tbl_eow_size]' ;
        tbl_pos_eow = zeros(tbl_eow_size,3) ;
        tbl_vel_eow = zeros(tbl_eow_size,3) ;
        tbl_acc_eow = zeros(tbl_eow_size,3) ;
        vel_ff_fw = zeros(tbl_eow_size,4) ;
        pos_ff_fw = zeros(tbl_eow_size,4) ;
        tbl_X = [1:tbl_X_size]' ;
        tbl_vel_X = zeros(tbl_X_size,3) ;
        tbl_acc_X = zeros(tbl_X_size,3) ;
        tbl_hofX = zeros(tbl_X_size,1) ;
        eow_boundary = 0 ;
        sinA = 0 ;
        cosA = 1 ;
        N_rwy = 0 ;
        E_rwy = 0 ;

        return
    end
    
    % for lack of anything better, use t_taem_sw as t_taem_ic below
    t_taem_ic = t_taem_sw ;
    
end

switch(HACcase)
    case 0
        ref_trajectory = [] ;
        last_error = [] ;
        load(fullfile(BAI_dir,'ref_trajectory'))
        if(isempty(ref_trajectory))
            if(isempty(last_error))
                error('unexplained error in ref_trajectory.mat') ;
            else
                disp('Error encountered during TAEM Guidance computation:')
                rethrow(last_error)
            end
        end
    otherwise
        if(ischar(HACcase))
            try
                load(fullfile(BAI_dir),HACcase)
            catch
                error('cannot load HACcase file: %s', HACcase)
            end
        else
            error('HACcase = %d does not exist', HACcase)
        end
end

rwyAZ_rad = rwyAZ / constants.r2d ;
cosA = cos(rwyAZ_rad) ;
sinA = sin(rwyAZ_rad) ;

if(BAI_version == 5)
    % Note: columns in version 5 are:
    % time, velmag, gamma, rwyAZ_rad - chi, hAGL, X, Y, qbar, Mach, phi, AoA, iphase,
    % Z, lat, lon, geoalt, X_ECEF, Y_ECEF, Z_ECEF
    
    % trim ref_trajectory to designated size of eow tables
    ref_trajectory = ref_trajectory(1:tbl_eow_size,:) ;
else
    ifix = 2000 ;
    if(ref_trajectory(ifix,6) < ref_trajectory(ifix-1,6))
        % fix transition from SGS to AL where X is not monotonic
        ref_trajectory(ifix,6) = ref_trajectory(ifix-1,6) + ...
            ( ref_trajectory(ifix,1) - ref_trajectory(ifix-1,1) ) * ...
            ( ref_trajectory(ifix+1,6) - ref_trajectory(ifix-1,6) ) / ...
            ( ref_trajectory(ifix+1,1) - ref_trajectory(ifix-1,1) ) ;
    end
end

% ref_trajectory data mapping
tmp_time = ref_trajectory(:,1) ;
ref_velmag = ref_trajectory(:,2) ;
ref_gamma = ref_trajectory(:,3) ;
ref_chi = rwyAZ_rad - ref_trajectory(:,4) ; % reference "psi" is relative to runway, counter-clockwise
ref_hAGL = ref_trajectory(:,5) ;
ref_X = ref_trajectory(:,6) ;
ref_Y = ref_trajectory(:,7) ;

ix_tmax = max(find(tmp_time)) ;
if(isempty(ix_tmax))
    warning('invalid trajectory in ref_trajectory array')
    keyboard
end

% extend time by replicating landing time to end of vector
tmp_time(ix_tmax+1:end) = tmp_time(ix_tmax) ;

% shift by time at which TAEM was initiated (for time based feed forward fws)
ref_time = tmp_time + t_taem_ic ;

% convert runway relative velocities to NEh velocities
tmp_Nd = ref_velmag .* cos(ref_gamma) .* cos(ref_chi) ;
tmp_Ed = ref_velmag .* cos(ref_gamma) .* sin(ref_chi) ;
tmp_hd = ref_velmag .* sin(ref_gamma) ;
tmp_vel = [ tmp_Nd tmp_Ed tmp_hd ] ;

% compute NEh accelerations by numerically differentiating NEh velocities
% only compute up to end of trajectory at ix_tmax, setting the rest of the
% array to zero (since we don't have a valid time after ix_tmax)
tmp_acc = zeros(size(tmp_vel)) ;
tmp_acc(1:ix_tmax,:) = [diff(tmp_vel(1:ix_tmax,:))./repmat(diff(tmp_time(1:ix_tmax)),1,3); zeros(1,3)] ;

% compute runway offset in NE coordinates
N_origin = 0 ;
E_origin = 0 ;
latlonh_IC = get_value('latlonh_IC') ;
lat_origin = latlonh_IC(1) ;
lon_origin = latlonh_IC(2) ;

N_rwy = N_origin + (mod(( rwyLLA(1)/constants.r2d - lat_origin )+pi,2*pi)-pi) * constants.earth_radius ;
E_rwy = E_origin + (mod(( rwyLLA(2)/constants.r2d - lon_origin )+pi,2*pi)-pi) * constants.earth_radius * cos(lat_origin) ;

% convert runway relative positions to NEh positions
tmp_N = N_rwy + cosA * ref_X + sinA * ref_Y ;
tmp_E = E_rwy + sinA * ref_X - cosA * ref_Y ;
tmp_h = ref_hAGL + rwyLLA(3) ;
tmp_pos = [ tmp_N tmp_E tmp_h ] ;

% compute energy/weight (eow) for each trajectory point
tmp_eow = ref_velmag.^2 / ( 2 * constants.g ) + tmp_h ;

% make tmp_eow strictly monotonic at the end
tmp_eow(ix_tmax+1:end) = tmp_eow(ix_tmax)-cumsum(ones(length(tmp_eow)-ix_tmax,1)) ;

% sort position, velocity, and acceleration trajectories by eow, and store
% as eow tables
[tbl_eow, tmp_eow_idx] = sort(tmp_eow) ;
tbl_pos_eow = tmp_pos(tmp_eow_idx,:) ;
tbl_vel_eow = tmp_vel(tmp_eow_idx,:) ;
tbl_acc_eow = tmp_acc(tmp_eow_idx,:) ;

% table for X as independent variable
% Note: Nint0 is the index of the start of steep descent
% N and E are computed in Simulink diagram as functions of X:
% N = rwy_N + cosA*X
% E = rwy_E + sinA*X

if(BAI_version == 5)
    ix = ix_tmax - tbl_X_size + 1 : ix_tmax ;
else
    ix = Nint0+1:size(ref_trajectory,1) ;
end

tbl_X = ref_X(ix) ;
tbl_hofX = tmp_h(ix) ;
tbl_vel_X = tmp_vel(ix,:) ;
tbl_acc_X = tmp_acc(ix,:) ;

eow_boundary = tmp_eow(ix(1)) ;

% set a variable used as a table in powerpoint charts
tmp_tbl1_ref_traj_ppt = ref_trajectory([1 end],:)' ;
tmp_tbl2_ref_traj_ppt = [ tbl_pos_eow([end 1],3)' ; tbl_eow([ end 1 ])' ; ...
    tmp_Nd([1 end])' ; tmp_Ed([1 end])' ; tmp_hd([1 end])' ] ;

pos_ff_fw = [ ref_time tmp_vel ] ;
vel_ff_fw = [ ref_time tmp_acc ] ;

% override default pos_cmd_fw
pos_cmd_fw = [ ref_time tmp_pos ] ;
pos_cmd_fw = pos_cmd_fw*[ 1 0 0 0 0 ; 0 1 0 0 0 ; 0 0 1 0 0 ; 0 0 0 0 1 ] ; % insert zero beta cmd in column 4

% set config variable to override default behavior
config.pos_cmd_fw = pos_cmd_fw ;