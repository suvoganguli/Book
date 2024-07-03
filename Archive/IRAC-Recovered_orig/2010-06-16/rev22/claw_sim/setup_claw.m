% NOTE: simulation only parameters have all been moved to the script setup_sim.

% the following variables can be used in m-functions called from Simulink
clear global MACH
global MACH

disp('setting MACH parameters')

% clear any previous definition of OBAC and TRAC
clear trac_params obac_params

% NOTE: All constant definitions have been moved to setup_constants, which
% is called by doit before setup_claw (so that they can be used in doit)

try
    get_value('vehicle_type') ;
catch
    error('error in vehicle specification, or no vehicle defined')
end

% these are parameters in the MACH control law

MACH.dt = get_value('dt');

% gain to enforce norm(quat) == 1 (used in geted)
% [2009-03-11 SGP] Should the quaternion norm feedback be taken out of
% geted (which is used in the EOM for both trac and obac), and used only
% during state integration?
MACH.K_quaterr = get_value('K_quaterr') ;

% number of states and state index definitions
MACH.num_x = 13;
MACH.pqr_idx = 1:3 ;
MACH.uvw_idx = 4:6 ;
MACH.NEh_idx = 7:9 ;
MACH.quat_idx = 10:13 ;

% To support pseudo surface commands and analysis, surface ganging
% is defined as follows:
%
% u_aero = MACH.mixer*[da; de; dr]
% [da; de; dr] = MACH.gang*u_aero
%
% where
%
% MACH.gang = pinv(MACH.mixer);

vane_names = get_value('vane_names') ;
vane_units = repstr(get_value('vane_units'),length(vane_names)) ;
MACH.mixer = get_value('mixer') ;
MACH.gang = pinv(MACH.mixer) ;

% MACH.att_angles gives the names of the angles in control order.
% MACH.att_in_order selects angles from control order to {x, y, z} order.
% MACH.att_out_order selects angles from {x, y, z} order to control order.

% [1 2 3] is "standard" order (x,y axis for control; z specified)
% For tiltcam, this is (tilta,tiltb) for control
% For ypr_bank, this is (phi,theta) for control (bank to turn)
% For mba_bank, this is (mu,alpha) for control (bank to turn)
% [3 2 1] is "inverted" order (z,y axis for control; x specified)
% For ypr_skid, this is (psi,theta) for control (skid to turn)
% For mba_skid, this is (beta,alpha) for control (skid to turn)
    
MACH.att_out_order = [1 2 3; 1 2 3; 3 2 1; 1 2 3; 3 2 1] ;
MACH.att_in_order = [1 2 3; 1 2 3; 3 2 1; 1 2 3; 3 2 1] ;
MACH.att_angles = {
    'tilta', 'tiltb', 'cam'
    'phi', 'theta', 'psi'
    'psi', 'theta', 'phi'
    'mu', 'alpha', 'beta'
    'beta', 'alpha', 'mu'
    } ;

% configure att control
% att_type_fw designates the type of attitude transformation
% (see the "att2dc" and "dc2att" blocks in utility_lib
% for detailed definitions of transformations
% [2009-01-09 SGP] this should really be in setup_sim.m, but some of the
% CLAW initialization depends on initial attitude type, MACH.att_type

att_type_fw = get_value('att_type_fw') ;
att_type_fw_size = size(att_type_fw) ;
if(length(att_type_fw_size) == 2 && ...
        att_type_fw_size(1) >= 1 && ...
        att_type_fw_size(2) == 2 && ...
        att_type_fw(1,1) == 0)
else
    error('att_type_fw(1,1) must be zero') ;
end

[tf, loc] = ismember(att_type_fw(:,2),att_type_numbers) ;
if(prod(double(tf)))
    disp(sprintf('Primary att_type = %s', att_type_names{loc(1)})) ;
    MACH.att_type =  att_type_fw(1,2) ;
else
    disp('bad att_type referenced in att_type_fw:')
    for i = 1:length(tf)
        if(~tf(i))
            disp(sprintf('time = %g, att_type = %g', att_type_fw(i,1), att_type_fw(i,2)))
        end
    end
    error('')
end

% configure control surfaces

% throttle
use_throt = get_value('use_throt') ;
if(use_throt <= 1)
    throt_names = { 'throt' } ;
    MACH.throt_mixer = 1 ;
else
    throt_names = cellstr(num2str([1:use_throt]','throt%1d'))' ;
    MACH.throt_mixer = ones(1,use_throt) ;
end
throt_units = repstr(get_value('throt_units'),length(throt_names)) ;

% tvc (thrust vector control)
use_tvc = get_value('use_tvc')*(use_throt > 0) ;

if(use_tvc <= 1)
    tvc_names = { 'tvc_m', 'tvc_n' } ;
else
    tvc_names = vertcat(cellstr(num2str([1:use_tvc]','tvc%1d_m')),cellstr(num2str([1:use_tvc]','tvc%1d_n')))';
end
tvc_units = repstr(get_value('tvc_units'),length(tvc_names)) ;

% configure rcs (reaction control system)
MACH.rcs_select = get_value('rcs_select','onerror',[]) ;
if(isempty(MACH.rcs_select))
    % no rcs requested
    % currently, the diagram needs at least one rcs input, so use
    % a value of '0' to fake one, and set the use_rcs flag to false
    MACH.rcs_select = [0] ;
    use_rcs = 0 ;
else
    use_rcs = get_value('use_rcs','onerror',1)  ;
end
rcs_names = cellstr(num2str(MACH.rcs_select','rcs%02d'))' ;
rcs_units = repstr(get_value('rcs_units'),length(rcs_names)) ;

% number of inputs and input index definitions
MACH.num_u_aero = length(vane_names) ;
MACH.num_u_throt = length(throt_names) ;
MACH.num_u_tvc = length(tvc_names) ;
MACH.num_u_rcs = length(rcs_names) ;
MACH.num_u = MACH.num_u_aero + MACH.num_u_throt + MACH.num_u_tvc + MACH.num_u_rcs;
MACH.u_names = {} ;
MACH.u_units = {} ;
MACH.vane_idx = 1:MACH.num_u_aero ;
MACH.u_names = horzcat(MACH.u_names, vane_names);
MACH.u_units = horzcat(MACH.u_units, vane_units);
MACH.throttle_idx = [1:MACH.num_u_throt] + length(MACH.u_names) ;
MACH.u_names = horzcat(MACH.u_names, throt_names);
MACH.u_units = horzcat(MACH.u_units, throt_units);
MACH.tvc_idx = [1:MACH.num_u_tvc] + length(MACH.u_names) ;
MACH.u_names = horzcat(MACH.u_names, tvc_names);
MACH.u_units = horzcat(MACH.u_units, tvc_units);
MACH.rcs_idx = [1:MACH.num_u_rcs] + length(MACH.u_names) ;
MACH.u_names = horzcat(MACH.u_names, rcs_names);
MACH.u_units = horzcat(MACH.u_units, rcs_units);

MACH.u_idx = cell2struct(num2cell(1:MACH.num_u),MACH.u_names,2);

% define number of controls for each loop
MACH.pqr_u_idx = [ MACH.vane_idx MACH.tvc_idx MACH.rcs_idx ] ;
MACH.pqr_num_u = length(MACH.pqr_u_idx) ;
MACH.att_num_u = 3 ;
MACH.vel_num_u = 2 + length(MACH.throttle_idx) ;
MACH.pos_num_u = 3 ;

% define OBAC model
try
    obac_params = define_model('obac', get_value('obac_model_type')) ;   
catch
    rethrow(lasterror);
end

% compute initial conditions

% if obac model has its own x_trim, use it
% otherwise, set num_x using length of x_obac_IC
if(isfield(obac_params,'x_trim'))
    x_obac_IC = obac_params.x_trim ;
end

if(length(x_obac_IC) ~= MACH.num_x)
    error('length of x_obac_IC (%d) not equal to MACH.num_x (%d)', length(x_obac_IC), MACH.num_x);
end

% if obac model has its own u_trim, use it
if(isfield(obac_params,'u_trim'))
    u_obac_IC = obac_params.u_trim ;
end

if(length(u_obac_IC) ~= MACH.num_u)
    error('length of u_obac_IC (%d) not equal to MACH.num_u (%d)', length(u_obac_IC), MACH.num_u) ;
end

wind_trim = zeros(3,1) ;
u_obac_IC = [ u_obac_IC; wind_trim ] ;

% Set control input initial conditions
vanes_trim_IC = u_obac_IC(MACH.vane_idx) ;
throttle_trim_IC = u_obac_IC(MACH.throttle_idx) ;
tvc_trim_IC = u_obac_IC(MACH.tvc_idx) ;
rcs_trim_IC = u_obac_IC(MACH.rcs_idx) ;

% Set da, de, dr commands for pre-engage
tmp = MACH.gang * vanes_trim_IC ;
da_trim_IC = tmp(1) ;
de_trim_IC = tmp(2) ;
dr_trim_IC = tmp(3) ;

orientation = get_orientation(x_obac_IC) ;

% Set initial angular rates.  Used to set initial conditions
% for controller and ideal rate response computation
% and to set appropriate inputs for check out of rate loops.
% Note: angular rate trim values other than zero are untested and
% discouraged.
pqr_trim_IC = [ 0 0 0 ]' ;
MACH_pqr_IC = pqr_trim_IC ;

% Set initial quaternions and Euler angles.  Used to set initial conditions
% for controller and ideal attitude response computation,
% and to set appropriate inputs for check out of attitude loops.
quat_trim_IC = orientation.quat' ;
MACH_quat_IC = quat_trim_IC ;
att_trim_IC = orientation.att' ;
dc_L2W_IC = orientation.dc_L2W ;

% set internal sources of commanded angles
tiltcam_cmd_fw = get_value('tiltcam_cmd_fw','onerror',[0 q2euler(MACH_quat_IC,att_type.tiltcam)']) ;
rpy_cmd_fw = get_value('rpy_cmd_fw','onerror',[0 q2euler(MACH_quat_IC,att_type.ypr_skid)']) ;
mab_cmd_fw = get_value('mab_cmd_fw','onerror',[0 q2euler(MACH_quat_IC,att_type.mba_bank)']) ;

% Set NEh velocities.  Used to set initial conditions
% for controller and ideal velocity response computation,
% and to set appropriate inputs for check out of velocity loops.
MACH_vel_IC = orientation.NdEdhd' ;
Nd_trim_IC = MACH_vel_IC(1) ;
Ed_trim_IC = MACH_vel_IC(2) ;
hd_trim_IC = MACH_vel_IC(3) ;
V_trim_IC = orientation.Vchigam(1) ;
chi_trim_IC = orientation.Vchigam(2) ;
gamma_trim_IC = orientation.Vchigam(3) ;

% Set NEh positions.  Used to set initial conditions
% for controller and ideal position response computations,
% and to set appropriate inputs for check out of position loops.
 % Note: this made need modification if pos loop is ground relative
MACH_pos_IC = x_obac_IC(MACH.NEh_idx) ;
N_trim_IC = MACH_pos_IC(1) ;
E_trim_IC = MACH_pos_IC(2) ;
h_trim_IC = MACH_pos_IC(3) ;

% initial conditions for various delay states
MACH_throttle_IC = throttle_trim_IC ;
MACH_pqr_u_IC = [ vanes_trim_IC; tvc_trim_IC; rcs_trim_IC ] ;
MACH_vel_uold_IC = [ MACH_quat_IC; MACH_throttle_IC ];
MACH_U_nom_IC = zeros(MACH.num_u,1) ;
MACH_U_nom_IC(MACH.pqr_u_idx) = MACH_pqr_u_IC ;
MACH_U_nom_IC(MACH.throttle_idx) = MACH_throttle_IC ;
MACH_mass_IC = obac_params.mass_IC ;

% define perturbations for Bmat computations
MACH.pqr_u_pert = repval(get_value('pqr_u_pert'),MACH.pqr_num_u) ;

MACH.vel_u_pert = get_value('vel_u_pert');
switch(length(MACH.vel_u_pert))
    case 1
        % use same pert for angles and all throts
        MACH.vel_u_pert = repval(MACH.vel_u_pert,MACH.vel_num_u) ;
    case 3
        % use specified perts for angles, and single throt pert for all throts
        MACH.vel_u_pert = [MACH.vel_u_pert(1:2) repval(MACH.vel_u_pert(3),MACH.vel_num_u-2)] ;
    case MACH.vel_num_u
        % all perts are specified
    otherwise
        error('Inconsistent specification for MACH.vel_u_pert = %s', mat2str(MACH.vel_u_pert))
end

% configuration parameters that effect runtime behavior of generated code
use_wind_est = get_value('use_wind_est') ;
use_nav = get_value('use_nav') ;
use_throt_estimate = get_value('use_throt_estimate') ;
use_cam_as_camcmd = get_value('use_cam_as_camcmd') ;
reset_camcmd_on_entry = get_value('reset_camcmd_on_entry') ;
compute_all_vel_cols = get_value('compute_all_vel_cols') ;
compute_all_rate_cols = get_value('compute_all_rate_cols') ;
use_variable_mass = get_value('use_variable_mass') ;
use_preference_schedule = get_value('use_preference_schedule') ;
preference_schedule_name = get_value('preference_schedule_name') ;
use_limit_schedule = get_value('use_limit_schedule') ;
limit_schedule_name = get_value('limit_schedule_name') ;
use_NdEdh_pos = get_value('use_NdEdh_pos') ;
enforce_fuel = get_value('enforce_fuel','onerror',use_variable_mass) ;
vel_cmd_ramp_time = get_value('vel_cmd_ramp_time') ;
use_eow_as_iv = get_value('use_eow_as_iv') ;
use_pos_fltpath_lim = get_value('use_pos_fltpath_lim') ;
use_auto_att_type = get_value('use_auto_att_type','onerror',0) ;

% linearize about selected trim condition to get rate Bmat
set_models('xdot_obac')
[Ao,Bo] = getAB(x_obac_IC, u_obac_IC) ;
MACH_pqr_Bmat_IC = Bo(MACH.pqr_idx,MACH.pqr_u_idx) ;

% initialization of velocity Bmat
set_models('vel_loop_Bmat')
vel_dnom = [att_trim_IC([1 2]); throttle_trim_IC]';
d_in = vel_dnom; sim('vel_loop_Bmat'); MACH_vel_cvdnom_IC = yout;
vel_perts = diag(MACH.vel_u_pert);
MACH_vel_Bmat_IC = zeros(length(MACH_vel_cvdnom_IC),MACH.vel_num_u);
for i = 1:length(vel_perts)   
    d_in = vel_dnom + vel_perts(i,:) ;
    sim('vel_loop_Bmat') ;
    MACH_vel_Bmat_IC(:,i) = (yout-MACH_vel_cvdnom_IC)' ;
end
MACH_vel_Bmat_IC = MACH_vel_Bmat_IC*inv(vel_perts) ;
% MACH_vel_cvdnom_IC should be included in the vel loop integrator to remove
% the component of vel_cvdnom which results from zeroing the rate surfs
% instead of using their trim values.  To eliminate this term, set to zero
% in the config struct.
MACH_vel_cvdnom_IC = repval(get_value('vel_cvdnom_IC','onerror',MACH_vel_cvdnom_IC),length(MACH_vel_cvdnom_IC))' ;

% this is where we should (eventually) return if using clawsf, but only
% after squirreling away required values that can be reloaded
% if(get_value('use_clawsf'))
%     return
% end

% start parameters for the control law
% Everything below this line should consist of IC independent parameters
% -------------------------------------------------------------------------

% define effector limits and rate limits

% rate loop effector limits and rate limits
MACH.pqr_u_pref = set_named_values(MACH.u_names(MACH.pqr_u_idx),'array','get_value','pqr_u_pref') ;

vane_min = repval(get_value('vane_min','insert',obac_params.aero),MACH.num_u_aero) ;
vane_max = repval(get_value('vane_max','insert',obac_params.aero),MACH.num_u_aero) ;
vanedot_max = repval(get_value('vanedot_max','insert',obac_params.aero),MACH.num_u_aero) ;

if(use_tvc)
    tvc_min = repval(get_value('tvc_min'),MACH.num_u_tvc) ;
    tvc_max = repval(get_value('tvc_max'),MACH.num_u_tvc) ;
else
    tvc_min = MACH.pqr_u_pref(ismember(MACH.pqr_u_idx,MACH.tvc_idx)) ;
    tvc_max = tvc_min ;
end
tvcdot_max = repval(get_value('tvcdot_max'),MACH.num_u_tvc) ;

if(use_rcs)
    rcs_min = repval(get_value('rcs_min'),MACH.num_u_rcs) ;
    rcs_max = repval(get_value('rcs_max'),MACH.num_u_rcs) ;
else
    rcs_min = MACH.pqr_u_pref(ismember(MACH.pqr_u_idx,MACH.rcs_idx)) ;
    rcs_max = rcs_min ;
end
rcsdot_max = repval(get_value('rcsdot_max'),MACH.num_u_rcs) ;

MACH.pqr_u_llim = [ vane_min tvc_min rcs_min] ;
MACH.pqr_u_ulim = [ vane_max tvc_max rcs_max] ;
MACH.pqr_u_urlim = [ vanedot_max tvcdot_max rcsdot_max ] ;
MACH.pqr_u_lrlim = -MACH.pqr_u_urlim ;

% throttle limits and rate limits
MACH.vel_u_pref = repval(get_value('vel_u_pref'),MACH.vel_num_u) ;

if(use_throt)
    throt_min = repval(get_value('throt_min'),MACH.num_u_throt) ;
    throt_max = repval(get_value('throt_max'),MACH.num_u_throt) ;
else
    throt_min = MACH.vel_u_pref(3:end) ;
    throt_max = throt_min ;
end

MACH.vel_throt_llim = throt_min ;
MACH.vel_throt_ulim = throt_max ;
MACH.vel_throt_urlim = repval(get_value('throtdot_max'),MACH.num_u_throt) ;
MACH.vel_throt_lrlim = -MACH.vel_throt_urlim ;

% Set the nominal values for various limits using the design limits
MACH.u_ulim(MACH.pqr_u_idx) = MACH.pqr_u_ulim ;
MACH.u_llim(MACH.pqr_u_idx) = MACH.pqr_u_llim ;
MACH.u_urlim(MACH.pqr_u_idx) = MACH.pqr_u_urlim ;
MACH.u_lrlim(MACH.pqr_u_idx) = MACH.pqr_u_lrlim ;
MACH.u_ulim(MACH.throttle_idx) = MACH.vel_throt_ulim ;
MACH.u_llim(MACH.throttle_idx) = MACH.vel_throt_llim ;
MACH.u_urlim(MACH.throttle_idx) = MACH.vel_throt_urlim ;
MACH.u_lrlim(MACH.throttle_idx) = MACH.vel_throt_lrlim ;

MACH.u_pref = zeros(1,MACH.num_u) ;
MACH.u_pref(MACH.pqr_u_idx) = MACH.pqr_u_pref ;

MACH.pqr_wght_u_pref = set_named_values(MACH.u_names(MACH.pqr_u_idx),'array','get_value','pqr_wght_u_pref') ;
MACH.pqr_wght_u_pref_high = MACH.pqr_wght_u_pref*1000 ;
MACH.wght_u_pref = zeros(1,MACH.num_u) ;
MACH.wght_u_pref(MACH.pqr_u_idx) = MACH.pqr_wght_u_pref ;

% [2009-08-05 SGP] nothing should use the static component rate limits
% anymore; remove them to make sure
MACH = rmfield(MACH,'pqr_u_urlim') ;
MACH = rmfield(MACH,'pqr_u_lrlim') ;
MACH = rmfield(MACH,'vel_throt_urlim') ;
MACH = rmfield(MACH,'vel_throt_lrlim') ;

% Configure control loops

% define number of controlled variables for each loop
MACH.pqr_num_cv = 3 ;
MACH.att_num_cv = 4 ;
MACH.vel_num_cv = 3 ;
MACH.pos_num_cv = 3 ;

% Each vehicle has a 'set_loop_gains' m-script that may be used to
% select a consistent set of gains determined by the value 'gain_set'

% General comments about gain values
% - Kc is computed from Ki using the inline function Ki2Kc (below)
% - Kaw and Ki_trim are zeroed if Ki is zero

% neglecting the integral path in the P+I 
% gives a loop gain (i.e., the high frequency gain)
% of K_trim*fc*Kb*Binv
% for the euler integration to be good at high freq,
% the loop gain*DT <= 0.4
% solving for K_trim gives
% K_trim <= 0.4/(fc*Kb*DT)*B
MACH.trim_loop_gain = 0.04 / MACH.dt ;

gain_set = get_value('gain_set') ;

if(isempty(gain_set))
    use_all_gain_sets = 1 ;
    gain_set = 1 ;
else
    use_all_gain_sets = 0 ;
    if(length(gain_set) > 1)
        error('gain_set must be a single integer, or empty (indicated all gain_sets included)')
    end
end
    
MACH_gain_mat = [] ;
gain_var_struct = [] ;
while(~isempty(gain_set))
    
    pqr_kbnom = [] ;
    set_loop_gains

    if(isempty(pqr_kbnom))
        if(use_all_gain_sets)
            if(gain_set > 0)
                gain_set = 0 ;
                continue ;
            else
                error('no gain sets were found in set_loop_gains') ;
            end
        else
            error('specified gain_set (%d) not found in set_loop_gains', gain_set) ;
        end
    else            
        MACH_pqr_Kb = repval(pqr_kbnom,MACH.pqr_num_cv) ;
        MACH_pqr_Ki = repval(pqr_fi,MACH.pqr_num_cv) ;
        MACH_pqr_Kf = repval(pqr_ff,MACH.pqr_num_cv) ;
        MACH_pqr_Kaw = repval(pqr_kaw,MACH.pqr_num_cv) ;
        MACH_att_Kb = repval(att_kbnom,MACH.att_num_cv) ;
        MACH_att_Ki = repval(att_fi,MACH.att_num_cv) ;
        MACH_att_Kf = repval(att_ff,MACH.att_num_cv) ;
        MACH_att_Kaw = repval(att_kaw,MACH.att_num_cv) ;
        MACH_vel_Kb = repval(vel_kbnom,MACH.vel_num_cv) ;
        MACH_vel_Ki = repval(vel_fi,MACH.vel_num_cv) ; 
        MACH_vel_Kf = repval(vel_ff,MACH.vel_num_cv) ; 
        MACH_vel_Kaw = repval(vel_kaw,MACH.vel_num_cv) ;
        MACH_pos_Kb = repval(pos_kbnom,MACH.pos_num_cv) ;
        MACH_pos_Ki = repval(pos_fi,MACH.pos_num_cv) ;
        MACH_pos_Kf = repval(pos_ff,MACH.pos_num_cv) ;
        MACH_pos_Kaw = repval(pos_kaw,MACH.pos_num_cv) ;
    end
    
    if(use_all_gain_sets && gain_set > 0)
        gain_set_next = gain_set + 1 ;
    else
        gain_set_next = [] ;
    end

    % create data structures with packed gain info
    if(isempty(gain_var_struct))
        gain_var_struct = whos('-regexp','^MACH_(pos|vel|att|pqr)_(Kb|Ki|Kaw|Kf)$') ;
        gain_var_struct = rmfield(gain_var_struct,setdiff(fieldnames(gain_var_struct),{'name','size'})) ;
    end
    
    this_gain_mat = eval(['[' sprintf(' %s',gain_var_struct.name) ']']) ;
    if(gain_set == 0)
        MACH_gain_mat = vertcat(this_gain_mat, MACH_gain_mat) ;
    else
        MACH_gain_mat = vertcat(MACH_gain_mat, this_gain_mat) ;
    end
    
    gain_set = gain_set_next ;
end

% set gain for att feed forward filter
MACH_att_fb = get_value('MACH_att_fb','onerror',0) ;

if(get_value('use_clawsf'))
    return
end

% current clawsf does not require anything below this line
% -------------------------------------------------------------------------

% select_cmd_array specifies the command source for each of the 4 loops
% 0 implies command current, i.e. set CV command to the current measured value fo the CV
% 1 implies direct or manual pilot inputs are used to set the CV commands
% 2 implies that the CV is being commanded by an outer loop

% [2009-05-27 SGP] att loops have been changed so that the command
% interface is uniformly attitude commands instead of quaternions.  This
% allow mixed attitude commands to be defined.  Row 5 may be set to zero to
% specify the use of the current quaternion to command the quaternion
% directly (without being converted to and from attitude commands).  Any
% value for row 5 other than zero causes rows 6 through 8 to be used as
% individual attitude selectors.

MACH.select_cmd_array = [
 %   man  rate   att   vel   pos   way
      0     1     2     2     2     2  % row  1: rate p
      0     1     2     2     2     2  % row  2: rate q
      0     1     2     2     2     2  % row  3: rate r
      0     1     2     2     2     2  % row  4: rate throt
      0     0     1     2     2     2  % row  5: att not current
      0     0     1     2     2     2  % row  6: att att1
      0     0     1     2     2     2  % row  7: att att2
      0     0     1     2     2     2  % row  8: att att3
      0     1     1     2     2     2  % row  9: att throt
      0     0     0     1     2     2  % row 10: vel Nd
      0     0     0     1     2     2  % row 11: vel Ed
      0     0     1     1     1     2  % row 12: vel cam 
      0     0     0     1     2     2  % row 13: vel hd
      0     0     0     0     1     2  % row 14: pos N
      0     0     0     0     1     2  % row 15: pos E
      0     0     1     1     1     2  % row 16: pos cam
      0     0     0     0     1     2  % row 17: pos h
] ;

if(use_NdEdh_pos)
    % use NdEdh cmd instead of NEh cmd in pos mode
    MACH.select_cmd_array([10 11 14 15],5) = [1 1 0 0] ;
end

if(use_cam_as_camcmd)
    % this used to have a different implementation, but we realized that it
    % was the same as command current for cam in the vel loop
    MACH.select_cmd_array(12,4) = 0 ;
end

% parameters related to 'state estimation' block

% gains for the navigation complementary filter
MACH.K_velpos = get_value('K_velpos') ;

% the numerical values come from Houston April 2003 report on wind estimator
% MACH.est_w_Kuvw =  2* [ -0.1474 -0.0248  -1.6996 ] ; % baseline gains
% MACH.est_w_Kuvw =  [ -10.5 -10.5 -14.5 ] ; % new estimator gains poles @ -5 rad/s
MACH.est_w_Kuvw = [ -13.25 -13.25 -19.5 ] ; % new estimator gains poles @ -5 rad/s
MACH.est_w_Kaw = [ 2 2 2 ] ;
% MACH.est_w_ulim = [  30  30  1 ] ;
% MACH.est_w_llim = [ -30 -30 -1 ] ;
MACH.est_w_ulim = [  40  40  1 ] ;
MACH.est_w_llim = [ -40 -40 -1 ] ;
MACH.est_w_urlim = [ 0.5 0.5 0.5 ] ;
MACH.est_w_lrlim = -MACH.est_w_urlim ;

% angular rate limits for rate and att mode 
p_max = get_value('p_max') ;
q_max = get_value('q_max') ;
r_max = get_value('r_max') ;

% pqr pqr pqr pqr pqr pqr pqr pqr pqr pqr pqr pqr pqr pqr pqr pqr pqr pqr

MACH.pqr_num_u_smn = MACH.num_u_aero + MACH.num_u_tvc ;
MACH.pqr_u_smn_idx = [1:MACH.pqr_num_u_smn] ;
MACH.pqr_u_rcs_idx = [1:MACH.num_u_rcs] + length(MACH.pqr_u_smn_idx);

MACH.pqr_wght_cv_type = get_value('pqr_wght_cv_type') ;
MACH.pqr_wght_cv = get_value('pqr_wght_cv') ;
if(strcmp(MACH.pqr_wght_cv_type, 'wght_cv_diag'))
    MACH.pqr_wght_cv = repval(MACH.pqr_wght_cv,MACH.pqr_num_cv) ;
end

% set rate limit on (active) position limit changes
% set to 'inf' to allow position limits to override MACH.pqr_u_rlim
% otherwise, set to MACH.pqr_u_rlim to allow command to attempt to follow
% position limit changes with normal rlim constraint.
% default is to allow limit changes at the rate limit for each surface
% MACH.pqr_u_limit_urlim = get_value('pqr_u_urlim','onerror',MACH.pqr_u_urlim) ;
% MACH.pqr_u_limit_lrlim = get_value('pqr_u_lrlim','onerror',MACH.pqr_u_lrlim) ;

% set threshold for use of rcs
rcs_cvddes_thresh = get_value('rcs_cvddes_thresh') ;

% set threshold for rcs efficiency
rcs_efficiency_thresh = get_value('rcs_efficiency_thresh') ;

if(use_rcs)
    [rcs_cmd_all, cvddes_actual, total_norm, component_norm] = rcs_efficiency(obac_params);
%     MACH.pqr_rcs_use = find(total_norm./component_norm >= rcs_efficiency_thresh) ;
    MACH.pqr_rcs_use = double(total_norm./component_norm >= rcs_efficiency_thresh);
else
    MACH.pqr_rcs_use = zeros(2^MACH.num_u_rcs-1,1);
end

if(use_preference_schedule)
    setup_preference_schedule
end
use_preference_schedule_fw = get_value('use_preference_schedule_fw','onerror',[0 use_preference_schedule]) ;

if(use_limit_schedule)
    setup_limit_schedule
end

aero_surf_qbar_on = get_value('aero_surf_qbar_on') ;
aero_surf_qbar_off = get_value('aero_surf_qbar_off') ;

% att att att att att att att att att att att att att att att att att att

MACH.att_u_ulim = [ p_max q_max r_max ] ; % rad/sec
MACH.att_u_llim = -MACH.att_u_ulim ;

% Z-axis accel limits due to pitch rate command
% Actual value of att_u_llim(2) used is -az_ulim/max(u,-az_ulim/MACH.att_u_llim(2))
% Actual value of att_u_ulim(2) used is -az_llim/max(u,-az_llim/MACH.att_u_ulim(2))
MACH.az_llim = get_value('az_llim') ; 
MACH.az_ulim =  get_value('az_ulim') ; 

MACH.att_fe = get_value('att_fe') ;

% vel vel vel vel vel vel vel vel vel vel vel vel vel vel vel vel vel vel

MACH.vel_wght_u_pref = repval(get_value('vel_wght_u_pref'),MACH.vel_num_u) ;
MACH.vel_wght_cv_type = get_value('vel_wght_cv_type') ;
MACH.vel_wght_cv = get_value('vel_wght_cv') ;
if(strcmp(MACH.vel_wght_cv_type, 'wght_cv_diag'))
    MACH.vel_wght_cv = repval(MACH.vel_wght_cv,MACH.vel_num_cv) ;
end
MACH.vel_wght_fltpath = repval(get_value('vel_wght_fltpath'),MACH.vel_num_cv) ;

% velocity loop angle limits
att_min = get_value('att_min','struct',att_type_names) ;
att_max = get_value('att_max','struct',att_type_names) ;

MACH.vel_att_llim = nan(length(att_type_numbers),2) ;
MACH.vel_att_ulim = MACH.vel_att_llim ;
for i = 1:length(att_type_numbers)
    MACH.vel_att_llim(att_type_numbers(i),:) = att_min.(att_type_names{i}) ;
    MACH.vel_att_ulim(att_type_numbers(i),:) = att_max.(att_type_names{i}) ;
end

% [2009-03-05 SGP] these should really be scheduled with att_type in a
% similar manner to vel_att_ulim and vel_att_llim
MACH.vel_att_urlim = [ p_max q_max ] ;
MACH.vel_att_lrlim = -MACH.vel_att_urlim ;

MACH.K_pn = get_value('K_pn') ; % gains for proportional nav control

% pos pos pos pos pos pos pos pos pos pos pos pos pos pos pos pos pos pos

% pos mode command limits
MACH.pos_u_ulim = get_value('pos_u_ulim') ;
MACH.pos_u_llim = get_value('pos_u_llim','onerror',-MACH.pos_u_ulim) ;
MACH.pos_fltpath_u_ulim = get_value('pos_fltpath_u_ulim') ;
MACH.pos_fltpath_u_llim = get_value('pos_fltpath_u_llim','onerror',-MACH.pos_fltpath_u_ulim) ;

% the following are not required if we are configured for an S-function CLAW
if(~get_value('use_clawsf'))
    this_dir = pwd ;
    addpath(fullfile(this_dir,'claw_lib'));
    addpath(fullfile(this_dir,'claw_lib','smn_sfunc'));

    % define smn_sfunc and its output dimension
    MACH.smn_sfunc_name = 'smn_sfunc_gam_mpass_epsposdef';
    try
        sim('get_smn_sfunc_output_dim')
    catch
        try
            smn_sfunc_output_dim = get_value('smn_sfunc_output_dim') ;
        catch
            error('cannot execute %s and smn_sfunc_output_dim is not set', MACH.smn_sfunc_name) ;
        end
    end
    
    pqr_num_u_max = smn_sfunc_output_dim - 1 ;

    if(MACH.pqr_num_u > pqr_num_u_max)
        error('number of rate controls (%d) larger than currently allowed (%d) by smn_sfunc\nreduce the number of controls or rebuild smn_sfunc with larger maximum', MACH.pqr_num_u, pqr_num_u_max) ;
    end
    
    % parameters for bang-bang controller
    setup_bb
end

% set u_backtrim for pre-takeoff condition
% [2009-03-04 SGP] this should be revisited if we ever use the 'pre_takeoff_sw' again
MACH.pre_takeoff_u_backtrim(MACH.pqr_u_idx) = MACH.pqr_u_pref ;
MACH.pre_takeoff_u_backtrim(MACH.throttle_idx) = get_value('throt_takeoff','onerror',1) ;
