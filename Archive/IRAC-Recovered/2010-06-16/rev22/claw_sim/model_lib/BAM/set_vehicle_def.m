function set_vehicle_def

clear global vehicle_def
global vehicle_def

vehicle_def.obac_model_type = 'bam' ;
vehicle_def.use_variable_mass = 0 ;
vehicle_def.weight = 61429 ;

vehicle_def.use_tvc = 1 ;
vehicle_def.tvc_min = [-40 -40] ;
vehicle_def.tvc_max = [ 40  40] ;

vehicle_def.p_max = 1.0 ; % rad/sec
% vehicle_def.pqr_wght_cv = [ 2 2 1 ] ; % lower priority for yaw axis (heli)
vehicle_def.pqr_wght_cv = [ 1 2 2 ] ; % lower priority for roll axis (airplane)

