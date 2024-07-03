% static gain definitions required by ideal response blocks
% these should no longer be used in the real-time CLAW

Ki2Kc = inline('(Ki < 0.25).*(0.5*(1+sqrt(1-4*Ki))) + (Ki >= 0.25).*sqrt(Ki)') ;

MACH_pqr_Kc = Ki2Kc(MACH_pqr_Ki) ;
% MACH_pqr_Ki_trim = (trim_loop_gain./(MACH_pqr_Kc.*MACH_pqr_Kb)).*(MACH_pqr_Ki > 0) ;
MACH_pqr_int_IC = (1-MACH_pqr_Kc).*MACH_pqr_IC' ;
MACH_att_Kc = Ki2Kc(MACH_att_Ki) ;
% MACH_att_Ki_trim = (trim_loop_gain./(MACH_att_Kc.*MACH_att_Kb)).*(MACH_att_Ki > 0) ;
MACH_att_int_IC = (1-MACH_att_Kc).*MACH_quat_IC' ;
MACH_vel_Kc = Ki2Kc(MACH_vel_Ki) ;
% MACH_vel_Ki_trim = (trim_loop_gain./(MACH_vel_Kc.*MACH_vel_Kb)).*(MACH_vel_Ki > 0) ;
MACH_vel_int_IC = (1-MACH_vel_Kc).*MACH_vel_IC' ;
MACH_pos_Kc = Ki2Kc(MACH_pos_Ki) ;
% MACH_pos_Ki_trim = (trim_loop_gain./(MACH_pos_Kc.*MACH_pos_Kb)).*(MACH_pos_Ki > 0) ;
MACH_pos_int_IC = (1-MACH_pos_Kc).*MACH_pos_IC' + MACH_vel_IC'./MACH_pos_Kb ;
