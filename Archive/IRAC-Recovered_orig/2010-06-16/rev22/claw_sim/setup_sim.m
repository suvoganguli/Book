% START OF SIMULATION INITIALIZATION

% everything from here on down should be required only for simulation
% we should probably break this out in a separate script [2003-03-18 SGP]

disp('setting simulation related values')
%sim_name = get_value('sim_name');

% definition of TRAC
try
    if config.obac_eq_trac
        trac_params = obac_params;
        trac_params.model_use_type = 'trac';
        trac_params.model_name = 'gtm-trac';
    else
        trac_params = define_model('trac', get_value('trac_model_type','onerror',obac_params.model_type)) ;   
    end
catch
    rethrow(lasterror);
end

% set continuous state integration and noise generation sample time
dtsim = get_value('dtsim') ;

% initial value of mode for simulation
mode = get_value('mode') ;
if(ischar(mode))
    mode = modes.(mode) ;
end

engage_time = get_value('engage_time') ;

mode_fw = get_value('mode_fw','onerror',[]) ;
if(isempty(mode_fw))
    mode_fw = [ 0 modes.direct ; engage_time mode ] ;
else
    mode_fw_size = size(mode_fw) ;
    
    % if there is only one row, and it doesn't have a time value of 0,
    % add an initial value of modes.direct 
    if(length(mode_fw_size) == 2 && ...
            all(mode_fw_size == [1 2]) && ...
            mode_fw(1,1) ~= 0)
        mode_fw = [ 0 modes.direct ; mode_fw ] ;
        mode_fw_size = size(mode_fw) ;
    end
    
    % check for format compliance
    if(length(mode_fw_size) == 2 && ...
            mode_fw_size(1) >= 2 && ...
            mode_fw_size(2) == 2 && ...
            mode_fw(1,1) == 0 && ...
            mode_fw(1,2) == modes.direct)
    else
        error('mode_fw(1,1) must be zero, mode_fw(1,2) must be modes.direct') ;
    end
    
    engage_time = mode_fw(2,1) ;
    mode = mode_fw(2,2) ;
end

[tf, loc] = ismember(mode_fw(:,2),mode_numbers) ;
if(all(tf))
    disp(sprintf('Primary mode = %s', mode_names{loc(2)})) ;
else
    disp('bad modes referenced in mode_fw:')
    for i = 1:length(tf)
        if(~tf(i))
            disp(sprintf('time = %g, mode = %g', mode_fw(i,1), mode_fw(i,2)))
        end
    end
    error('')
end

% set initial LLh position
% Note: any altitude offset should be in the altitude state IC!
latlonh_IC = get_value('latlonh_IC') ;

if(isfield(config,'command_time'))
    command_time = config.command_time ;
else
    command_time = engage_time + 2.0 ;
end

% delay nav_ok signal true to at least the second sample during simulation
nav_enable_fw = [ 0 0 ; MACH.dt 1 ] ;

% stick_limit_lower = -Inf ; % no lower limit on stick for simulation
% stick_limit_upper = Inf ; % no upper limit on stick for simulation
% stick_limit_lower = 0 ; % simulate real radio control lower limit
% stick_limit_upper = 1 ; % simulate real radio control upper limit
% vehicle_id_sim = 1 ; % value of vehicle_id for simulation

% if trac model has its own x_trim, use it
% otherwise, set use x_obac_IC as x_trac_IC, and set num_x accordingly
if(isfield(trac_params,'x_trim'))
    x_trac_IC = trac_params.x_trim ;
else
    x_trac_IC = x_obac_IC;
    trac_params.num_x = length(x_trac_IC);
end

% parameters that effect vehicle state integration
integrate_state_sim = 1 ; % 0 => hold state at IC, 1 => normal state integration
integrate_start_time_sim = 0 ; % time to start state integration
use_xdot_ground = zeros(1,length(x_trac_IC));
% use_xdot_ground([MACH.uvw_idx MACH.NEh_idx]) = 1; % turn off all attitude related derivatives when h < 0
% use_xdot_ground([MACH.uvw_idx(3) MACH.NEh_idx(3)]) = 1; % turn off all non-altitude related derivatives when h < 0
% use_xdot_ground = 1 ; % use all state derivatives as computed in ground effect model

% set default min and max times for mkplt
tmin = 0 ;
tmax = inf ;

% set values that effect sim termination
tsim_max = get_value('tsim_max') ;
angular_rate_stop = get_value('angular_rate_stop') ;
altitude_stop = get_value('altitude_stop') ;
energy_stop = get_value('energy_stop') ;

% miscellaneous switches (see set_MACH_def.m for explanations)
use_wind_meas_sim = get_value('use_wind_meas_sim') ;
use_held_aero_obac_fw = get_value('use_held_aero_obac_fw') ;
use_held_aero_trac_fw = get_value('use_held_aero_trac_fw', 'onerror', use_held_aero_obac_fw) ;
use_full_surf_cmd = get_value('use_full_surf_cmd') ;
use_cam_rate_cmd_fw = get_value('use_cam_rate_cmd_fw') ;
use_att_rate_cmd_fw = get_value('use_att_rate_cmd_fw') ;
enable_bb_fw = get_value('enable_bb_fw') ;
enable_homing_fw = get_value('enable_homing_fw') ;
gain_set_fw = get_value('gain_set_fw') ;
accel_submode_fw = get_value('accel_submode_fw') ;
use_Vchigam_fw = get_value('use_Vchigam_fw') ;
use_hm_actuators = get_value('use_hm_actuators') ;

% define nominal limits for surfaces
clear full_surf_params

% use design params for obac
full_surf_params.obac.llim = MACH.u_llim ;
full_surf_params.obac.ulim = MACH.u_ulim ;
full_surf_params.obac.lrlim = MACH.u_lrlim ;
full_surf_params.obac.urlim = MACH.u_urlim ;

% use obac params for trac as a default
full_surf_params.trac = full_surf_params.obac ;

% set preference values for obac
full_surf_params.obac.pref = MACH.u_pref ;
full_surf_params.obac.pref_wght = MACH.wght_u_pref ;

% set torque limits for trac to be arbitrarily large
full_surf_params.trac.utlim = repmat(realmax('double'),1,MACH.num_u) ;
full_surf_params.trac.ltlim =  -full_surf_params.trac.utlim ;

fail_surfs = get_value('fail_surfs') ;
full_surf_limits_fw = get_full_surf_params([], full_surf_params, fail_surfs) ;

% [2009-08-07 SGP] surface locking is now done within the 'fail_surfs'
% framework
%
% configure full surf locking
% the initial use of this capability is to allow locking of some surfaces
% (like throt) at their initial values, but it generalizes by setting
% elements of llim and ulim to the full_surf_cmd value for any time window.
% lock_full_surf = get_value('lock_full_surf') ;
% 
% % convert grouped surface 'allaero', 'alltvc', and 'allrcs' to equivalent surfaces
% if(any(ismember({'allaero', 'aero'}, lock_full_surf)))
%     lock_full_surf = setdiff(lock_full_surf, {'allaero', 'aero'}) ;
%     lock_full_surf = union(lock_full_surf, MACH.u_names(MACH.vane_idx)) ;
% end
% if(any(ismember({'alltvc', 'tvc'}, lock_full_surf)))
%     lock_full_surf = setdiff(lock_full_surf, {'alltvc', 'tvc'}) ;
%     lock_full_surf = union(lock_full_surf, MACH.u_names(MACH.tvc_idx)) ;
% end
% if(any(ismember({'allrcs', 'rcs'}, lock_full_surf)))
%     lock_full_surf = setdiff(lock_full_surf, {'allrcs', 'rcs'}) ;
%     lock_full_surf = union(lock_full_surf, MACH.u_names(MACH.rcs_idx)) ;
% end
% if(any(ismember({'allthrot', 'throt'}, lock_full_surf)))
%     lock_full_surf = setdiff(lock_full_surf, {'allthrot', 'throt'}) ;
%     lock_full_surf = union(lock_full_surf, MACH.u_names(MACH.throttle_idx)) ;
% end
% 
% lock_full_surf_fw = [0 ismember(MACH.u_names, lock_full_surf)] ;

% set parameters for simulated servo (see set_MACH_def.m for descriptions)
clear SERVO
SERVO.servo_type = get_value('SERVO.servo_type') ;
SERVO.w = repval(get_value('SERVO.w'),MACH.num_u) ;
SERVO.z = repval(get_value('SERVO.z'),MACH.num_u) ; 
SERVO.pos_Kaw = repval(get_value('SERVO.pos_Kaw'),MACH.num_u) ;
SERVO.delay = get_value('SERVO.delay') ;
SERVO.x0 = MACH_U_nom_IC ;
SERVO.llim = full_surf_params.trac.llim ;
SERVO.ulim = full_surf_params.trac.ulim ;
SERVO.lrlim = full_surf_params.trac.lrlim ;
SERVO.urlim = full_surf_params.trac.urlim ;

if(use_hm_actuators)
    SERVO.hm_params = setup_hinge_moment ;
end

% ------------ suvo, steve ----------- 6/22/10
setup_sensors

% servo_type = set_servo(sim_name, SERVO.servo_type) ;
% disp(['servo model = ' servo_type]) ;

% parameters for rate cmd select
rate_cmd_select = get_value('rate_cmd_select') ;
rate_cmd_fw = get_value('rate_cmd_fw','onerror',[0 pqr_trim_IC' throttle_trim_IC(1)']) ;

% default canned att_type sequence
att_type_fw = get_value('att_type_fw','onerror',[0 MACH.att_type]) ;

% parameters for att cmd select
att_cmd_select = get_value('att_cmd_select') ;
att_cmd_fw = get_value('att_cmd_fw','onerror',[0 att_trim_IC' throttle_trim_IC(1)']) ;

% parameters for vel cmd select
vel_cmd_select = get_value('vel_cmd_select') ;
vel_cmd_fw = get_value('vel_cmd_fw','onerror',[0 Nd_trim_IC Ed_trim_IC att_trim_IC(3) hd_trim_IC]) ;

% set ideal gain parameter required by pos_cmd_select = 2 (ramp pos cmd)
ideal_vel_Kb = MACH_vel_Kb(1) ;

setup_landing_profile
setup_wind
setup_homing

if(get_value('enable_ideal'))
    setup_ideal
end

assertion_time = get_value('assertion_time') ;
HACcase = [] ;
setup_taem_sgs_al

% parameters for pos cmd select
% Note: pos_cmd_select must be done after setup_taem_sgs_al, which may set
% a value for pos_cmd_fw
pos_cmd_select = get_value('pos_cmd_select') ;
if(use_NdEdh_pos)
    pos_cmd_fw = get_value('pos_cmd_fw','onerror',[0 Nd_trim_IC Ed_trim_IC att_trim_IC(3) h_trim_IC]) ;
else
    pos_cmd_fw = get_value('pos_cmd_fw','onerror',[0 N_trim_IC E_trim_IC att_trim_IC(3) h_trim_IC]) ;
end

% limit externally supplied engine performance values to +- 10 percent
Isp_sl_ulim = trac_params.Isp_sl*1.1 ;
Isp_sl_llim = trac_params.Isp_sl*0.9 ;
Isp_vacuum_ulim = trac_params.Isp_vacuum*1.1 ;
Isp_vacuum_llim = trac_params.Isp_vacuum*0.9 ;
throt_to_ff_ulim = trac_params.throt_to_ff*1.1 ;
throt_to_ff_llim = trac_params.throt_to_ff*0.9 ;

% leave throt limit limits at full range for now
throt_ulim_ulim = throt_max ;
throt_ulim_llim = throt_min ;
throt_llim_ulim = throt_max ;
throt_llim_llim = throt_min ;
