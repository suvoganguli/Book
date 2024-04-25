function vehicle_params = set_vehicle_params(vehicle_params)

% vehicle parameters for BAM model
% internal model is in the airplane frame

global MACH

set_body_frame('airplane') ;

body2airplane = get_value('airplane2vert')'*MACH.body2vert ;
vehicle_params.body2airplane = body2airplane ;
vehicle_params.airplane2body = body2airplane' ;

weight = get_value('weight') ;

% inertias in airplane reference frame
Ixx = 16861 ; % slugs ft^2 
Iyy = 179846 ; % slugs ft^2
Izz = 199570 ; % slugs ft^2

massprops.mass = weight/get_value('g','constants') ;
massprops.inertia = body2airplane'*diag([Ixx Iyy Izz])*body2airplane ;
massprops.r_cg = [ 0 0 0 ] ;

vehicle_params.mass_IC = massprops.mass ;

% max propellant values
vehicle_params.mass_maxprop = massprops.mass ;
vehicle_params.r_cg_maxprop = massprops.r_cg ;
vehicle_params.inertia_maxprop = massprops.inertia ;

% no propellant values
vehicle_params.mass_noprop = massprops.mass ;
vehicle_params.r_cg_noprop = massprops.r_cg ;
vehicle_params.inertia_noprop = massprops.inertia ;

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
