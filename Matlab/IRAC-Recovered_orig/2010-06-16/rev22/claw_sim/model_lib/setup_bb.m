
Kb_rate = pqr_kbnom ;
Kb_att = att_kbnom ;

% Kb_rate = 4 ; % rad/sec
% Kb_att = 2 ; % rad/sec

% after running ellipsoid with 10 rcs jets
%      min             max
%   9.2922e-005    0.0047705     = pdot
%   7.5039e-005    0.0038524     = qdot
%   5.6839e-005     0.002918     = rdot

pp_Katt = Kb_att(1) * Kb_rate ;  % suvo/dale/1/27/2010
pp_Krate = Kb_rate ;

% coast when rate is above rate_des1
% 
pp_rate_des1 = 5 * pi/180 ; % rad/sec
pp_rate_des2 = 20 * pi/180 ; % rad/sec

pp_ww = sqrt(pp_Katt) ;
pp_zeta = 0.5 * pp_Krate / pp_ww ;

% limiting values of achievable angular acceleration
% these are currently overridden by pp_ellipsoid values
% pp_amin = -0.0047 ; % for 30 lb jets
% pp_amax = 0.0047 ; % for 30 lb jets
pp_amin = -0.0156 ; % for 100 lb jets
pp_amax = 0.0156 ; % for 100 lb jets

pp_params = [ pp_amax pp_amin pp_ww pp_zeta pp_rate_des1 pp_rate_des2 ]' ;

% pp_ellipsoid = (pp_amax*vehicle_params.inertia_noprop)^-2 ;
if(MACH.num_u_rcs == 6)
    bb_ellipsoid = diag([500 3200 1600].^-2) ; % for faked RCS
else
    bb_ellipsoid = diag([638 2140 3196].^-2) ;
end

bb_timer_max = 5 ; % sec
bb_att_thresh = 1e-3 ; % rad
bb_rate_thresh = 1e-3 ; % rad/sec
bb_att_diff_thresh = 20/180*pi ; % rad

bb_params = [
    MACH.dt
    bb_timer_max
    bb_att_thresh
    bb_rate_thresh
    bb_att_diff_thresh
    pp_params
    ] ;
