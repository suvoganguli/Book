
if( ideal_engine_actuator )
    integ_engine_a = [] ;
    integ_engine_b = [] ;
    integ_engine_c = [] ;
    integ_engine_d = 0 ;
else
    integ_engine_a = 0 ;
    integ_engine_b = 1 ;
    integ_engine_c = 1 ;
    integ_engine_d = 0 ;
end

if( ideal_d_actuator )
    integ_d_a = [] ;
    integ_d_b = [] ;
    integ_d_c = [] ;
    integ_d_d = zeros(num_d,num_d) ;
else
    integ_d_a = zeros(num_d,num_d) ;
    integ_d_b = eye(num_d) ;
    integ_d_c = eye(num_d) ;
    integ_d_d = zeros(num_d,num_d) ;
end

if( sig_gust > 0 )
    integ_gust_a = 0 ;
    integ_gust_b = 1 ;
    integ_gust_c = 1 ;
    integ_gust_d = 0 ;
else
    integ_gust_a = [] ;
    integ_gust_b = [] ;
    integ_gust_c = [] ;
    integ_gust_d = 0 ;
end

if( use_sn > 0 )
    integ_sn_a = zeros(num_y,num_y) ;
    integ_sn_b = eye(num_y) ;
    integ_sn_c = eye(num_y) ;
    integ_sn_d = zeros(num_y) ;
else
    integ_sn_a = [] ;
    integ_sn_b = [] ;
    integ_sn_c = [] ;
    integ_sn_d = zeros(num_y,num_y) ;
end

if( do_cov )
    integ_cmd_rate_a = [] ;
    integ_cmd_rate_b = [] ;
    integ_cmd_rate_c = [] ;
    integ_cmd_rate_d = 0 ;
else
    integ_cmd_rate_a = [] ;
    integ_cmd_rate_b = [] ;
    integ_cmd_rate_c = [] ;
    integ_cmd_rate_d = 0 ;
end

%%%%%%%%%% MACH rate
if( fi_rate > 0 & mode > 0 )
    integ_MACH_rate_a = zeros(3,3) ;
    integ_MACH_rate_b = eye(3) ;
    integ_MACH_rate_c = eye(3) ;
    integ_MACH_rate_d = zeros(3,3) ;
else
    integ_MACH_rate_a = [] ;
    integ_MACH_rate_b = [] ;
    integ_MACH_rate_c = [] ;
    integ_MACH_rate_d = zeros(3,3) ;
end

%%%%%%%%%% MACH att
if( fi_att > 0 & mode > 1 )
    integ_MACH_att_a = zeros(3,3) ;
    integ_MACH_att_b = eye(3) ;
    integ_MACH_att_c = eye(3) ;
    integ_MACH_att_d = zeros(3,3) ;
else
    integ_MACH_att_a = [] ;
    integ_MACH_att_b = [] ;
    integ_MACH_att_c = [] ;
    integ_MACH_att_d = zeros(3,3) ;
end

if( use_att_ff & mode > 1 )
    integ_MACH_att_ff_a = zeros(3,3) ;
    integ_MACH_att_ff_b = eye(3) ;
    integ_MACH_att_ff_c = eye(3) ;
    integ_MACH_att_ff_d = zeros(3,3) ;
else
    integ_MACH_att_ff_a = [] ;
    integ_MACH_att_ff_b = [] ;
    integ_MACH_att_ff_c = [] ;
    integ_MACH_att_ff_d = zeros(3,3) ;
end

%%%%%%%%%% MACH vel
if( fi_vel > 0 & mode > 2 )
    integ_MACH_vel_a = zeros(3,3) ;
    integ_MACH_vel_b = eye(3) ;
    integ_MACH_vel_c = eye(3) ;
    integ_MACH_vel_d = zeros(3,3) ;
else
    integ_MACH_vel_a = [] ;
    integ_MACH_vel_b = [] ;
    integ_MACH_vel_c = [] ;
    integ_MACH_vel_d = zeros(3,3) ;
end

%%%%%%%%%% MACH pos
if( fi_pos > 0 & mode > 3 )
    integ_MACH_pos_a = zeros(3,3) ;
    integ_MACH_pos_b = eye(3) ;
    integ_MACH_pos_c = eye(3) ;
    integ_MACH_pos_d = zeros(3,3) ;
else
    integ_MACH_pos_a = [] ;
    integ_MACH_pos_b = [] ;
    integ_MACH_pos_c = [] ;
    integ_MACH_pos_d = zeros(3,3) ;
end


