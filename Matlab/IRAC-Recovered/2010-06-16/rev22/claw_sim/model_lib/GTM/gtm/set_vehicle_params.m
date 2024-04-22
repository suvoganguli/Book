function vehicle_params = set_vehicle_params(vehicle_params)

% vehicle parameters for GTM model
% internal model is in the airplane frame

global MACH config          % config added by suvo

set_body_frame('airplane') ;

%% GTM Data

disp('Loading GTM gtm mass properties')
myaddpath

if config.do_quicktrim
    disp('Doing a quick trim');     % loads MWS_new into workspac which is 
                                    % trimmed at fcase1 (see set_trim.m) 
    fcase = get_value('fcase') ;
    switch(fcase)
        case 1
            load MWS_fcase1;                                   
        otherwise
            error('Bad fcase');
    end
    MWS = MWS_new;                          
    gtm_model = config.model_name;      % from setup_gtm                            
    load_system(gtm_model);             % alternate option: open_system
    
else
    setup_gtm  % creates MWS and loads into model workspace
    MWS = grabmws(gtm_model);    
    disp('In set_vehicle_params.m: need to revisit this - 6/17/10');
end    

% weight
weight = MWS.w0 ;

% inertias in airplane reference frame
% MWS.Inertia0 = [Ixx Iyy Izz Ixz Ixy Iyz]
inertia = reshape(MWS.Inertia0([1,5,4,5,2,6,4,6,3]),3,3);  
r_cg    = MWS.cg_pos0;  % CP

massprops.mass = weight/get_value('g','constants') ;
massprops.inertia = inertia ;
massprops.r_cg = r_cg ;

vehicle_params.mass_IC = massprops.mass ;

% max propellant values
vehicle_params.mass_maxprop = massprops.mass ;
vehicle_params.r_cg_maxprop = massprops.r_cg ;
vehicle_params.inertia_maxprop = massprops.inertia ;

% no propellant values
vehicle_params.mass_noprop = massprops.mass ;
vehicle_params.r_cg_noprop = massprops.r_cg ;
vehicle_params.inertia_noprop = massprops.inertia ;

% aero properties
disp('Loading GTM gtm aero model')
aero = MWS; %rmfield(MWS,{});

% control limits
% aero.vane_min = -30*ones(1,MACH.num_u_aero) ;
% aero.vane_max = 30*ones(1,MACH.num_u_aero) ;
% aero.vanedot_max = 50*ones(1,MACH.num_u_aero) ;

avg_throtdot_max = 50; % earlier 70 - 1/22/10

aero.vane_min    = [-30 -20 -30 -12  0 -100] ;           % elev ail rud stab elevgain throt_diff
aero.vane_max    = [+30 +20 +30  +4 +1 +100] ;           % elev ail rud stab elevgain throt_diff 
aero.vanedot_max = 300*ones(1,MACH.num_u_aero) ;         % all are 300 deg/sec
aero.vanedot_max(5) = avg_throtdot_max;

aero.throt_min = 0*ones(1,MACH.num_u_throt) ;
aero.throt_max = 100*ones(1,MACH.num_u_throt) ;
aero.throtdot_max = avg_throtdot_max*ones(1,MACH.num_u_throt) ;

% ---- 10/27/09 --- steve/suvo ---

switch(vehicle_params.model_use_type)
    case 'obac'
        vehicle_params.dt_fault = MACH.dt;
        aero.elev_gain_fw = get_value('elev_gain_obac_fw','onerror',[0  1]);
    case 'trac'
        vehicle_params.dt_fault = get_value('dtsim','base');
        aero.elev_gain_fw = get_value('elev_gain_trac_fw','onerror',[0  1]);
end

% ------------

vehicle_params.aero = aero;


%% 
% Note: The following is provided for reference and continuity.
% Rotor dynamics are not used for this vehicle.
%
% [2009-02-20 SGP] WARNING!  While the values for all examples are correct,
% the comments about 'spin_direction' convention have been wrong in the past.
% Spin direction is defined as positive in the body z direction, resulting
% in a right-hand rule definition of angular momentum.
% spin_direction = -1 for 29i OAV, FCS Class I, AVID BDIMAV
% spin_direction = +1 for t-MAV
%
% compute gain from RPM to rotor angular momentum
% spin_direction = 0 ;
% irotor = zeros(3) ; % slug-ft^2
% vehicle_params.rpm2hrotor = irotor*[ 0; 0; 2*pi/60*spin_direction ] ;

% accelerometer locations
% as currently implemented, this is relative to cg location in the body frame
vehicle_params.r_accel = [ 0 0 0 ] ; % ft

% with default Isp = 1, throt_to_ff of weight will give thrust to weight
% ratio of one.
vehicle_params.throt_to_ff = weight ;

set_trim

