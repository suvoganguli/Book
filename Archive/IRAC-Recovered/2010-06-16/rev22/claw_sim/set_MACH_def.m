function set_MACH_def

clear global MACH_def
global MACH_def

% system configuration
MACH_def.sim_name = 'main_sim' ;
MACH_def.model_home = 'model_lib' ;
MACH_def.path_dirs = {'utility_lib' 'plotting_files'} ;
if(ispc)
    MACH_def.smn_root = 'P:\oav-unix\FlightControl\MACH\smn' ;
else
    MACH_def.smn_root = '/net/projects/oav-unix/FlightControl/MACH/smn' ;
end
MACH_def.use_clawsf = 0 ;

% simulation only parameters
MACH_def.dtsim = 0.005 ;
MACH_def.mode = 'direct' ;
MACH_def.engage_time = 2 ; % default
MACH_def.tsim_max = Inf ; % run forever
MACH_def.angular_rate_stop = 2 ; % stop if any angular rate exceeds 2 rad/sec
MACH_def.energy_stop = -Inf ; % do not enforce energy stop criterion
MACH_def.altitude_stop = 0 ; % stop if altitude goes negative
MACH_def.gain_set_fw = [ 0 0 ] ; % use default gain_set ( = 0 ) throughout
MACH_def.latlonh_IC = [ [45.0 -93.5]/get_value('r2d','constants') 0 ] ; % Mpls, MN 
MACH_def.assertion_time = inf ; % don't use on-the-fly TAEM
MACH_def.HACcase = [] ; % don't define a TAEM trajectory

% configuration switches for sim
MACH_def.use_wind_meas_sim = 0 ; % 0 => set NED wind meas to zero, 1 => use actual NED wind input as meas
MACH_def.use_full_surf_cmd = 1 ; % = 0 use pseudo surf cmds, = 1 use full surf cmds (both while NOT engaged)
MACH_def.use_cam_rate_cmd_fw = [ 0 0 ] ; % = 0 use cam input directly, = 1 use cam input as cam rate
MACH_def.use_att_rate_cmd_fw = [ 0 0 ] ; % = 0 use att input directly, = 1 use att input as att rate
MACH_def.enable_bb_fw = [ 0 0 ] ; % 0 = always use linear rate controller, 1 = enable use of bangbang rate controller
MACH_def.enable_homing_fw = [ 0 0 ] ; % 0 = always use desdyn controller, 1 = enable use of proportional nav controller
MACH_def.use_held_aero_obac_fw = [ 0 0 ] ; % 0 = update aero environment continuously, 1 = hold last value (Note: this is a from workspace variable!)
% MACH_def.use_held_aero_trac_fw = use_held_aero_obac_fw ; % 0 = update aero environment continuously, 1 = hold last value (Note: this is a from workspace variable!)
MACH_def.accel_submode_fw = [ 0 0 ] ; % 0 = normal velocity desdyn, 1 = NED_dd commands, 2 = vchigam_dot commands, 3 = homing commands
MACH_def.use_Vchigam_fw = [ 0 0 ] ; % 0 = normal velocity inputs, 1 = V, chi, gamma velocity inputs
MACH_def.fail_surfs = {} ; % no surface failures
MACH_def.lock_full_surf = {} ; % lock no surfaces
MACH_def.rate_cmd_select = 0 ; % use step rate cmds by default
MACH_def.att_cmd_select = 0 ; % use step att cmds by default
MACH_def.vel_cmd_select = 0 ; % use step vel cmds by default
MACH_def.pos_cmd_select = 0 ; % use step pos cmds by default
MACH_def.enable_ideal = 1 ; % enable/disable generation and use of ideal responses
MACH_def.use_hm_actuators = 0 ; % enable/disable use of hinge moment actuators for aero surfaces

% simulated servo parameters
% choose one of the following.  see model_lib blocks for details
MACH_def.SERVO.servo_type = 'variable limit servo model' ;
% MACH_def.SERVO.servo_type = 'dynamic servo model' ;
% MACH_def.SERVO.servo_type = 'limit only servo model' ;
% MACH_def.SERVO.servo_type = 'no servo model' ;
MACH_def.SERVO.w = 100 ;                             % servo bandwidths (rad/sec)
MACH_def.SERVO.z = sqrt(1/2) ;                       % servo damping ratios
MACH_def.SERVO.pos_Kaw = 2 ;                         % servo pos anti-windup gain
MACH_def.SERVO.delay = 0 ;                           % servo input delay (sec)
% MACH_def.SERVO.x0 = MACH.U_nom_IC ;                % servo initial condition
% MACH_def.SERVO.rlim = full_surf_limits.trac.rlim ; % servo rate limit
% MACH_def.SERVO.llim = full_surf_limits.trac.llim ; % servo pos lower limit
% MACH_def.SERVO.ulim = full_surf_limits.trac.ulim ; % servo pos upper limit

% CLAW
MACH_def.dt = 0.02 ; % CLAW rate is 50 Hz

% define OBAC and TRAC models
% subtype paths may be identified by appending with a valid file separator
% for example, 'lstsq2/wam' specifies the wam variant of the lstsq2 model_type
% MACH_def.obac_model_type = ? ; % defined in set_vehicle_def
% MACH_def.trac_model_type = ? ; % defined in set_vehicle_def

% define default fields for EVERY model here
% others may be added per vehicle in set_vehicle_def.m
% MACH_def.model_def.rho = get_value('rho0','constants') ; % legacy

MACH_def.att_type_fw = [ 0 get_value('att_type.mba_bank','base') ] ; % this should really be designated for each config case

MACH_def.att_type_priority = zeros(1,length(get_value('att_type_numbers','base'))) ;
MACH_def.abs_cos_b_thresh = 0.5 ;
MACH_def.abs_cos_theta_thresh = 0.5 ;
MACH_def.abs_vel_rw_thresh = 1 ; % ft/sec
MACH_def.abs_cos_beta_thresh = 0.5 ;
MACH_def.abs_cos_gamma_rw_thresh = 0.1 ;
MACH_def.mba_qbar_thresh = 1 ; % lbs/ft^2

% surface limits
% all of these limits should really be set in set_vehicle_def.m per vehicle

MACH_def.group_names = {'tvc' 'rcs' 'throt'};

% vanes/aero surfaces
MACH_def.vane_names = {'DA', 'DE', 'DR'} ;
MACH_def.mixer = eye(3) ;
MACH_def.vane_units = {'deg'} ;
MACH_def.vane_min = -30 ;
MACH_def.vane_max = 30 ;
MACH_def.vanedot_max = 50 ;

% thrust vector control
MACH_def.use_tvc = 0 ;
MACH_def.tvc_units = {'deg'} ;
MACH_def.tvcdot_max = 50 ; % deg/sec

% reaction control system
MACH_def.rcs_units = {'1 == full'} ;
MACH_def.rcs_min = 0 ; % discrete, 0 = off, 1 = on
MACH_def.rcs_max = 1 ; % discrete, 0 = off, 1 = on
MACH_def.rcsdot_max = 200 ; % 1/sec

% throttle
MACH_def.use_throt = 1 ;
MACH_def.throt_units = {'1 == full'} ;
MACH_def.throt_min = 0 ;
MACH_def.throt_max = 2 ;
MACH_def.throtdot_max = 0.3 ; % maximum command throt rate % DFE exper was 0.1

% design limits

% angular rate limits
MACH_def.p_max = 1.0 ; % rad/sec ; changed from 0.5 to improve roll response [2003-06-11 SGP]
MACH_def.q_max = 1.0 ; % rad/sec ; changed from 0.5 to improve pitch response [2003-06-11 SGP]
MACH_def.r_max = 1.0 ; % rad/sec ; changed from 0.5 to improve yaw response [2003-05-05 SGP]

% angle limits (all angles limits in radians)
MACH_def.att_min.tiltcam = [ -1.0 -1.0 ] ; % [ tilta tiltb ]
MACH_def.att_min.ypr_bank = [ -1.0 -1.0 ] ; % [ roll pitch ]
MACH_def.att_min.ypr_skid = [ -1.0 -1.0 ] ; % [ yaw pitch ]
MACH_def.att_min.mba_bank = [ -pi*1.1 -0.2 ] ; % [ bank alpha ]
MACH_def.att_min.mba_skid = [ -pi/6 -pi/6 ] ; % [ beta alpha ]

MACH_def.att_max.tiltcam = [ 1.0 1.0 ] ; % [ tilta tiltb ]
MACH_def.att_max.ypr_bank = [ 1.0 1.0 ] ; % [ roll pitch ]
MACH_def.att_max.ypr_skid = [ 1.0 1.0 ] ; % [ yaw pitch ]
MACH_def.att_max.mba_bank = [ pi*1.1 0.35 ] ; % [ bank alpha ]
MACH_def.att_max.mba_skid = [ pi/6 pi/6 ] ; % [ beta alpha ]

% rate (pqr) loop parameters
MACH_def.pqr_u_pert = 0.25 ; % perturbations for rate loop Bmat computation
MACH_def.pqr_u_pref = {'default' 0} ;
MACH_def.pqr_wght_u_pref = {'default' 1 'tvc' 0.0001} ;
% example of overriding preference weightings
% make adjustments to rate loop params for body flaps and yaw tabs
% config.pqr_wght_u_pref = { '(BF|RBF|LBF|RYT|LYT)' 1000 } ;

MACH_def.pqr_wght_cv_type = 'wght_cv_diag' ;
MACH_def.pqr_wght_cv = 1 ; % equal weight for all three axes
% MACH_def.pqr_wght_cv = [ 2 2 1 ] ; % lower priority for yaw axis (heli)
% MACH_def.pqr_wght_cv = [ 1 2 2 ] ; % lower priority for roll axis (airplane)
% uncomment to allow immediate limit changes
% MACH_def.pqr_u_limit_urlim = inf ;
% MACH_def.pqr_u_limit_lrlim = -inf ;

% aero surface cutoff thresholds for low qbar
MACH_def.aero_surf_qbar_on = 0 ;
MACH_def.aero_surf_qbar_off = 0 ;

% rcs allocation parameters
MACH_def.rcs_cvddes_thresh = 0.1 ; % this effectively turns off RCS alloc block
MACH_def.rcs_efficiency_thresh = 0.01 ; % only eliminate near cancellations

% att loop parameters
MACH_def.att_fe = 2 ; % gain on loop to enforce dot(ed_des,e_nom) == 0
MACH_def.az_llim = -100*get_value('g','constants') ; % body Z-axis accel lower bound (ft/sec2)
MACH_def.az_ulim =  100*get_value('g','constants') ; % body Z-axis accel upper bound (ft/sec2)

% vel loop parameters
% [2009-02-19 SGP] throt pert is way too big for full range 0 to 2.  Try
% setting to same value as angle perts
% MACH_def.vel_u_pert = [ 0.05 0.05 0.25 ];
MACH_def.vel_u_pert = [ 0.05 0.05 0.05 ];
MACH_def.vel_u_pref = 0 ;
MACH_def.vel_wght_u_pref = 1 ;
MACH_def.vel_wght_cv_type = 'wght_cv_full' ;
% MACH.vel_wght_cv = eye(3) ; % equal weight on Nd, Ed, hd
MACH_def.vel_wght_cv = diag([1 1 sqrt(10)]) ; % larger weight on hd
% [2008-01-23 SGP] alternate weighting when throttle is held fixed with
% limits (throt_llim == throt_ulim).  In this case, the cvs are
% transformed from velocities components in [N E h] to
% [along_track cross_track vertical_normal]
% MACH_def.vel_wght_fltpath = [0.01 1 1] ;
% [2009-02-05 SGP] Change along path weight to zero
MACH_def.vel_wght_fltpath = [ 0 1 1 ] ;
MACH_def.K_pn = [4 4] ; % rad/sec; gains for proportional nav control

% pos loop parameters
% velocity limits
% [2008-09-11 SGP] open up old OAV/MAV limits for FAST, APGM, BAM, etc.
% should be done per vehicle
% MACH_def.pos_u_ulim = [  100  100  10 ] ; % ft/sec
% MACH_def.pos_u_llim = [ -100 -100  -5 ] ; % ft/sec
MACH_def.pos_u_ulim = [ 1000 1000 1000 ] ; % ft/sec
MACH_def.pos_fltpath_u_ulim = [ 1 1 1 ] ; % ft/sec

% misc parameters
MACH_def.K_quaterr = -5 ; % gain to enforce norm(quat) == 1 (used in geted block)
MACH_def.vel_cmd_ramp_time = 0 ; % sec
MACH_def.K_velpos = 1/30 ; % rad/sec; gains for nav complementary filter
MACH_def.gain_set = [] ; % load all gain sets (see vehicle set_loop_gains.m)

% configuration switches for CLAW
MACH_def.use_variable_mass = 1 ; % 0 = hold constant at initial value, 1 = update mass, r_cg, based on fuel flow
% MACH_def.enforce_fuel = use_variable_mass ; % 0 = throt ignores fuel, 1 = throt requires fuel
MACH_def.use_preference_schedule = 0 ; % 0 = no preference schedule, 1 = model dependent preference schedule
MACH_def.preference_schedule_name = 'model_lib/no preference schedule' ;
MACH_def.use_limit_schedule = 0 ; % 0 = no limit schedule, 1 = model dependent limit schedule
MACH_def.limit_schedule_name = 'model_lib/no limit schedule' ;
MACH_def.use_NdEdh_pos = 0 ; % 0 = pos mode cmd is NEh, 1 = pos mode cmd is NdEdh
MACH_def.use_wind_est = 0 ; % = 0 for sensed relative wind, 1 = for estimate of relative wind
MACH_def.use_nav = 1 ; % = 0 to use complementary filter, 1 = to use Kalman filter navigation
MACH_def.use_throt_estimate = 0 ; % 0 = use last throt cmd as throt nom, 1 = use measured rpm to estimate throt nom
MACH_def.use_cam_as_camcmd = 0 ; % 0 = use camcmd in vel obac computations , 1 = use current cam in vel obac computations
MACH_def.reset_camcmd_on_entry = 0 ; % 0 = don't reset camcmd integrator, 1 = reset camcmd integrator on entry to mode >= att_mode
MACH_def.compute_all_vel_cols = 1 ; % 0 = compute Bmat_vel one column per cycle, 1 = compute all columns every cycle
MACH_def.compute_all_rate_cols = 1 ; % 0 = compute Bmat_rate one column per cycle, 1 = compute all columns every cycle
MACH_def.use_eow_as_iv = 0 ;
MACH_def.use_pos_fltpath_lim = 0 ;

% configuration variables for mkplt
MACH_def.plot_udot = 1 ; % turn on/off vane rate plots
MACH_def.plot_attdot = 1 ; % turn on/off attitude and throttle rates plots
MACH_def.plot_photo = 0 ; % turn on/off photo plot
MACH_def.plot3D = 0 ; % turn on/off 3D trajectory plot
MACH_def.plot_traj = 0 ; % turn on/off 2D trajectory plot
MACH_def.plot_homing = 0 ; % turn on/off homing plot
MACH_def.plot_fltpath = 0 ; % turn on/off fltpath mode on vel cvdex plot
MACH_def.show_along_fltpath = 0 ; % turn on/off along path line on vel cvdex plot
MACH_def.show_surf_limits = 1 ; % turn on/off surface limit lines on surf plots
MACH_def.set_paper_position = 0 ; % set paper position if true
MACH_def.t_trim = 5 ; % compute x_trim, u_trim values from last t_trim seconds of data
