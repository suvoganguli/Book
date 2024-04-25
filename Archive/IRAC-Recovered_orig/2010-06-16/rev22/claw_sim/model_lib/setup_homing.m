% parameters for target and seeker
% Note: these are dummy values for case when homing is not used.

max_LOS_rate = [1 1] ; % rad/sec for [azimuth_LOS_d elevation_LOS_d]
target_pos_IC = [0 0 0] ;
target_vel_IC = [0 0 0] ;
target_range_detect = 0 ; % ft of slant range; start NE homing
target_range_homing = 0 ; % ft of slant range; start h homing
target_range_blind = 0 ; % ft of slant range; set LOS rates to zero (=> zero accel cmds)
