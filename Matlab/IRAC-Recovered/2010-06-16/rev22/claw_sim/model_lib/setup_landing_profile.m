% vel_cmd_select = 1 ; % use landing profile for vel cmds

time_accel_cmd = 10 ; % sec
accel_cmd = -10 ; % ft/sec^2
max_vel_cmd = Inf ; % ft/sec
min_vel_cmd = 400 ; % ft/sec

time_gamdot_cmd_descent = 10 ; % sec
gamdot_cmd_descent = -0.06 ; % dfe exper 0.1 % rad/sec
gam_cmd_descent = -0.32 ; % rad

time_turn_cmd = 30 ; % sec
turn_rate_cmd = 0.05 ; % rad/sec
max_chi_cmd = 1.1 * pi ; % radians
min_chi_cmd = -2*pi ; % radians

time_gamdot_cmd_preflare = 140 ; % sec
gamdot_cmd_preflare = 0.06 ; % dfe exper 0.1 ; % rad/sec
gam_cmd_preflare = -0.05 ; % rad

time_gamdot_cmd_flare = 170 ; % sec
gamdot_cmd_flare = 0.06 ; % dfe exper 0.1 ; % rad/sec
gam_cmd_flare = 0 ; % rad
