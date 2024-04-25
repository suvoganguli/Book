function vehicle_params = start_vehicle_params(vehicle_params)

global MACH

% use MACH number of states and state indices as default for vehicle model
vehicle_params.num_x = MACH.num_x;
vehicle_params.pqr_idx = MACH.pqr_idx;
vehicle_params.uvw_idx = MACH.uvw_idx;
vehicle_params.NEh_idx = MACH.NEh_idx;
vehicle_params.quat_idx = MACH.quat_idx;

% use MACH number of inputs and input indices as default for vehicle model
vehicle_params.num_u = MACH.num_u;
vehicle_params.vane_idx = MACH.vane_idx;
vehicle_params.throttle_idx = MACH.throttle_idx;
vehicle_params.rcs_idx = MACH.rcs_idx ;
vehicle_params.tvc_idx = MACH.tvc_idx ;

% dummy defaults for fuel related params
% any vehicle that really uses propulsion should set these!
vehicle_params.Isp_sl = 1 ; % sec
vehicle_params.Isp_vacuum = 1 ; % sec
vehicle_params.throt_to_ff = 1 ; % lbs/sec
vehicle_params.r_prop = [ 0 0 0 ]' ; % ft
vehicle_params.tvc_select = 1 ;
vehicle_params.throt_select = 1 ;

