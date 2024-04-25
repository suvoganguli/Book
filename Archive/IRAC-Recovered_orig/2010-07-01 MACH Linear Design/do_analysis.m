% things to do
% 1. ask spratt for help with legend('4 actuators','18 sensors')
% 2. ask spratt for help with using y_names without ' in bias names prt to screen
% 3. why does h increase when wings are banked? see mode=2, att_type=2, phi_step

% nice to have
% 1. analysis independent of states, i.e. everything depends on the outputs

% the script get_GTM_data creates the following list of variables used here
% Aac Aac_trac Bac Bac_trac Cac Cac_trac V_trim alp_trim iu_de iu_d iu_throt w_de zeta_de Kengine 

close all
clear all

use_GTM_aircraft = 1 ;

% decide what analyses to perform
do_prt = 1 ;
do_plt = 1 ;
do_thist = 0 ;
do_cov = 1 ;
do_fresp = 0 ;
do_psd = 0 ;

% mode = 0 for direct, = 1 for rate, = 2 for att, = 3 for vel, = 4 for pos 
mode = 1 ;

use_io5 = 1 ;

% att_type = 2 means use theta and att_type = 4 means use alpha
att_type = 4 ;

% if not ideal, the engine is first order and the elevator actuator is second order
ideal_engine_actuator = 1 ;
ideal_d_actuator = 1 ;

if( use_GTM_aircraft )
    get_GTM_data
else
    get_GV_data
end

% gravitational acceleration
g = 32.17 ; % ft/sec^2

% set control law design parameters
if( use_GTM_aircraft )
    Kb_rate = 10 ; % rad/sec
    fi_rate = 0.25 ;

    Kb_att = 4 ; % rad/sec
    fi_att = 0.25 ;
    fb_att = 0.5 ;

    Kturnrate = 3  ; % rad/sec

    Kb_vel = diag([ 1 1 1 ]) ; % rad/sec 
    fi_vel = 0.25 ;
    fc_vel = 0.5 ;

    Kb_pos = 0.2 ; % rad/sec
    fi_pos = 0.25 ;
    fc_pos = 0.5 ;
else
    Kb_rate = 6 ; % rad/sec
    fi_rate = 0.25 ;

    Kb_att = 3 ; % rad/sec
    fi_att = 0.25 ;
    fb_att = 0.5 ;

    Kturnrate = 1  ; % rad/sec

    Kb_vel = diag([ 0.4 0.4 0.4 ]) ; % rad/sec 
    fi_vel = 0.25 ;
    fc_vel = 0.5 ;

    Kb_pos = 0.05 ; % rad/sec
    fi_pos = 0.25 ;
    fc_pos = 0.5 ;
end

% set values used to define the commands for time domain simulations
command_time = 1 ; % sec
pulse_width = 3 ; % sec

throt_step_cmd = 0 ;
p_step_cmd = 1*pi/180 ; % rad/sec
q_step_cmd = 1*pi/180 ; % rad/sec
r_step_cmd = 1*pi/180 ; % rad/sec
phi_step_cmd = 1*pi/180 ; % radians
tht_step_cmd = 1*pi/180 ; % radians
psi_step_cmd = 1*pi/180 ; % radians
mu_step_cmd = 1*pi/180 ; % radians
alpha_step_cmd = 1*pi/180 ; % radians
beta_step_cmd = 1*pi/180 ; % radians
Nd_step_cmd = 10 ;
Ed_step_cmd = 10 ;
hd_step_cmd = 10 ;
N_step_cmd = 200 ;
E_step_cmd = 200 ;
h_step_cmd = 200 ;

% angle conversions
d2r = pi / 180 ;
r2d = 180 / pi ;

% sensor noise parameters
use_sn = 0 ; % set use_sn to zero to remove all sensore noise else set it to 1

sig_p = use_sn * 0.03 * d2r ; % rad/sec 
sig_q = use_sn * 0.03 * d2r ; % rad/sec 
sig_r = use_sn * 0.03 * d2r ; % rad/sec 
sig_phi = use_sn * 0.03 * d2r ; % rad 
sig_tht = use_sn * 0.03 * d2r ; % rad 
sig_psi = use_sn * 0.03 * d2r ; % rad 
sig_Nd = use_sn * 1 ; % ft/sec 
sig_Ed = use_sn * 1 ; % ft/sec 
sig_hd = use_sn * 1 ; % ft/sec 
sig_N = use_sn * 1 ; % feet
sig_E = use_sn * 1 ; % feet
sig_h = use_sn * 1 ; % feet
sig_axa = use_sn * 0.001 ; % g 
sig_aya = use_sn * 0.001 ; % g 
sig_aza = use_sn * 0.001 ; % g 
sig_V = use_sn * 1 ; % ft/sec
sig_alpha = use_sn * 1 ; % ft/sec
sig_beta = use_sn * 1 ; % ft/sec

lam_sn = -20 ; % rad/sec
Asn = lam_sn * eye(num_y) ;

sn_seed = round(1e5*rand(num_y,1)) ; % used as seed for sensor noise below
% note seeds for gust model are hard wired right now

% frequency variables for frequency response analysis
ww = logspace(-2,2,400) ;

% gust model, to change the turbulence value you have to edit this file
dryden_gust_model

% set rate, att, vel command to zero here so defined but overwrite below for sim
gthrot_step_cmd = 0 ;
rate1_step_cmd = p_step_cmd ; % suvo
rate2_step_cmd = q_step_cmd ; % suvo
rate3_step_cmd = 0 ;
att1_step_cmd = 0 ;
att2_step_cmd = 0 ;
att3_step_cmd = 0 ;
vel1_step_cmd = 0 ;
vel2_step_cmd = 0 ;
vel3_step_cmd = 0 ;
pos1_step_cmd = 0 ;
pos2_step_cmd = 0 ;
pos3_step_cmd = 0 ;

if( mode <= 1 )
    tsim_max = 8 ; % sec
elseif( mode == 2 )
    tsim_max = 20 ; % sec
elseif( mode == 3 )
    tsim_max = 50 ; % sec
elseif( mode == 4 )
    tsim_max = 100 ; % sec
end
delt = 0.005 ; % sec

% these variables are used for fresp and cov below
u_names = {'da','de','dr','throt' } ;
y_names = { 'p','q','r','phi','theta','psi','Nd','Ed','hd','N','E','h','axa','aya','aza','V','alpha','beta' } ;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% intent is all data is set above this point

ctht = cos( tht_trim ) ;
stht = sin( tht_trim ) ;

cosa = cos( alp_trim ) ;
sina = sin( alp_trim ) ;

if( att_type == 4 )
    use_att_ff = 1 ;
else
    use_att_ff = 0 ;
end

close all

% set gains unique to mode setting
if( mode == 0 ) % no feedback control law
    Krate = 0 ;
    Katt = 0 ;
    Kvel = 0 ;
    Kpos = 0 ;
elseif( mode == 1 ) % only rate feedback control law
    Krate = 1 ;
    Katt = 0 ;
    Kvel = 0 ;
    Kpos = 0 ;
elseif( mode == 2 ) % attitude and rate feedback control law
    Krate = 1 ;
    Katt = 1 ;
    Kvel = 0 ;
    Kpos = 0 ;
elseif( mode == 3 ) % velocity, attitude, and rate feedback control law
    Krate = 1 ;
    Katt = 1 ;
    Kvel = 1 ;
    Kpos = 0 ;
elseif( mode == 4 ) % position, velocity, attitude, and rate feedback control law
    Krate = 1 ;
    Katt = 1 ;
    Kvel = 1 ;
    Kpos = 1 ;
end 

% print the open loop poles
if( do_prt )
    disp(' ')
    disp('open loop poles')
    warning off
    rifd(eig(Aac_trac))
    warning on
end

% rate loop control law
c_rate = [ eye(3) zeros(3,9) ] ;
ca_rate = c_rate * Aac ;
cb_rate = c_rate * Bac(:,iu_d) ;
cbinv_rate = inv(cb_rate) ;
fc_rate = get_fc(fi_rate) ; 

% attitude loop control law
c_att = [ zeros(3,3) eye(3) zeros(3,6) ] ;

if( use_att_ff )
    fc_att = 1 ;
    ff_att = 1 ;
else
    fc_att = get_fc(fi_att) ; 
    ff_att = 0 ;
end

% create point mass model used in velocity loops
% with NEh velocities as the outputs
% and throttle, att1, and att2 as the inputs
% and NEhdot, NEh as the states

% residualize pqr, and roll, pitch, and yaw rate states

% 3 outputs are NEh velocities
Cvel = [ zeros(3,6) eye(3) zeros(3,3) ] ;

Cmualphabeta = Cac(iy_mab,:) ;
Cpos = [ zeros(3,9) eye(3) ] ;
Cvelpos = [ Cvel ; Cpos ] ;

% M1, M2, M1inv and M3 are used in cl/claw/MACH/get attc.mdl
M1 = Cmualphabeta(:,4:6) ;
M2 = [ Cmualphabeta(:,1:3) zeros(3,3) Cmualphabeta(:,7:12) ] ;
M1inv = inv(M1) ;
M3 = M1inv * M2 ; 
% Note mab = M1 * phithtpsi + M2 * x
% phithtpsi = M1inv * mab - M3 * x

i_phitht = 4:5 ; % this index is also used in cl/claw/MACH/get rate of V wrt L
i_mualpha = 4:5 ;

i_pqr = 1:3 ;
i_resid = [ 1:6 ] ;
i_keep = [ 7:12 ] ; % keep states are NEhdot, NEh

if( att_type == 2 )
    % attitude = phi,theta,psi and using da,de,dr,p,q,r to solve for pqrdot=0 and phithetapsidot = 0
    % resid states are p,q,r, phi,theta,psi
    
    A11 = Aac(i_keep,i_keep) ;
    A1pqr = Aac(i_keep,i_pqr) ;
    A1phitheta = Aac(i_keep,i_phitht) ;
    B11 = Bac(i_keep,iu_d) ;
    B12 = Bac(i_keep,iu_throt) ;
    A21 = Aac(i_resid,i_keep) ;
    A2pqr = Aac(i_resid,i_pqr) ;
    A2phitheta = Aac(i_resid,i_phitht) ;
    B21 = Bac(i_resid,iu_d) ;
    B22 = Bac(i_resid,iu_throt) ;
    C1 = Cvel(:,i_keep) ;
    Cpqr = Cvel(:,i_pqr) ;
    Cphitheta = Cvel(:,i_phitht) ;
    D1 = zeros(3,num_d) ;
    D2 = zeros(3,1) ;

    R = [ A2pqr B21 ] ;
    Q = [ A1pqr B11 ] / R ;
    P = [ Cpqr D1 ] / R ;

    a11_tmp = A11 - Q * A21 ;
    a1phitheta_tmp = A1phitheta - Q * A2phitheta ;
    b12_tmp = B12 - Q * B22 ;
    c1_tmp = C1 - P * A21 ;
    cphitheta_tmp = Cphitheta - P * A2phitheta ;
    d2_tmp = D2 - P * B22 ;

    a_vel = a11_tmp ;
    b_vel = [ b12_tmp a1phitheta_tmp ] ;
    c_vel = c1_tmp ;
    d_vel = [ d2_tmp cphitheta_tmp ] ;
else    
    % attitude = mu,alpha,beta and using da,de,dr,p,q,r to solve for pqrdot=0 and mualphabetadot = 0
    % [ pqr mu,alpha,beta NEhd NEh ]' = Tinv * [ pqr phi,tht,psi NEhd NEh ]'
    tmp = eye(12) ;
    Tinv = [ tmp(1:3,:) ; Cmualphabeta ; tmp(7:12,:) ] ;
    T = inv(Tinv) ;

    F = Tinv * Aac * T ;
    G = Tinv * Bac ;
    H = Cvel * T ;

    A11 = F(i_keep,i_keep) ;
    A1pqr = F(i_keep,i_pqr) ;
    A1mualpha = F(i_keep,i_mualpha) ;
    B11 = G(i_keep,iu_d) ;
    B12 = G(i_keep,iu_throt) ;
    A21 = F(i_resid,i_keep) ;
    A2pqr = F(i_resid,i_pqr) ;
    A2mualpha = F(i_resid,i_mualpha) ;
    B21 = G(i_resid,iu_d) ;
    B22 = G(i_resid,iu_throt) ;
    C1 = H(:,i_keep) ;
    Cpqr = H(:,i_pqr) ;
    Cmualpha = H(:,i_mualpha) ;
    D1 = zeros(3,num_d) ;
    D2 = zeros(3,1) ;

    R = [ A2pqr B21 ] ;
    Q = [ A1pqr B11 ] / R ;
    P = [ Cpqr D1 ] / R ;

    a11_tmp = A11 - Q * A21 ;
    a1mualpha_tmp = A1mualpha - Q * A2mualpha ;
    b12_tmp = B12 - Q * B22 ;
    c1_tmp = C1 - P * A21 ;
    cmualpha_tmp = Cmualpha - P * A2mualpha ;
    d2_tmp = D2 - P * B22 ;

    a_vel = a11_tmp ;
    b_vel = [ b12_tmp a1mualpha_tmp ] ;
    c_vel = c1_tmp ;
    d_vel = [ d2_tmp cmualpha_tmp ] ;
end

ca_vel = c_vel * a_vel ;
cb_vel = c_vel * b_vel ;
cbinv_vel = inv(cb_vel) ;

% create state space matrices for integrators in the control law such that
% they can be removed if they are not active
set_integ_state_space

zeros_pqr_d = szeros(pck(Aac_trac,Bac_trac(:,1:num_d),c_rate,zeros(3,3))) ;
if( do_prt )
    disp(' ')
    disp('open loop zeros of prq/d')
    warning off
    rifd(zeros_pqr_d)
    warning on
end ;

% sensor errors

Bsn = sqrt( -2 * lam_sn ) * ...
    diag([ sig_p sig_q sig_r sig_phi sig_tht sig_psi sig_Nd sig_Ed sig_hd sig_N sig_E sig_h ...
    sig_axa sig_aya sig_aza sig_V sig_alpha sig_beta ]) ;

disp(' ')
disp([ 'mode = ' num2str(mode) ])
disp([ 'att_type = ' num2str(att_type) ])
disp([ 'use_att_ff = ' num2str(use_att_ff) ])
disp([ 'Kturnrate = ' num2str(Kturnrate) ])

[acl,bcl,ccl,dcl] = linmod('cl') ;

lam_cl = eig(acl) ;
if( do_prt )disp(' ')
    disp('closed loop poles')
    warning off
    rifd(lam_cl)
    warning on
end

w_cl = abs(lam_cl) ;
zeta_cl = - real(lam_cl) ./ ( w_cl + ( w_cl == 0 ) .* ones(size(w_cl)) ) ;

[Y,I_zcl] = sort(abs(zeta_cl(:)),1,'ascend') ;
zcl_zmin1 = zeta_cl(I_zcl(1)) ;
if( zcl_zmin1 < 0 )
    disp('closed loop system is UNSTABLE')
end
wcl_zmin1 = w_cl(I_zcl(1)) ;
zcl_zmin3 = zeta_cl(I_zcl(3)) ;
wcl_zmin3 = w_cl(I_zcl(3)) ;

% only some of the indices are used and ones not used are commented out
%                         indices for cl inputs
% 1 mult pert input for da
% 2 mult pert input for de
% 3 mult pert input for dr
% 4 mult pert input for throt
% 5 mult pert input for p
% 6 mult pert input for q
% 7 mult pert input for r
% 8 mult pert input for phi
% 9 mult pert input for theta
% 10 mult pert input for psi
% 11 mult pert input for Nd
% 12 mult pert input for Ed
% 13 mult pert input for hd
% 14 mult pert input for N
% 15 mult pert input for E
% 16 mult pert input for h
% 17 mult pert input for axa
% 18 mult pert input for aya
% 19 mult pert input for aza
% 20 mult pert input for V
% 21 mult pert input for alpha
% 22 mult pert input for beta
iu_cl_ug = 23 ; % wn input for ug
iu_cl_vg = 24 ; % wn input for vg
iu_cl_wg = 25 ; % wn input for wg
iy_cl_p_wn = 26 ; % wn input for p
iy_cl_q_wn = 27 ; % wn input for q
iy_cl_r_wn = 28 ; % wn input for r
iy_cl_phi_wn = 29 ; % wn input for phi
iy_cl_theta_wn = 30 ; % wn input for theta
iy_cl_psi_wn = 31 ; % wn input for psi
iy_cl_Nd_wn = 32 ; % wn input for Nd
iu_cl_Ed = 33 ; % wn input for Ed
iu_cl_hd = 34 ; % wn input for hd
iu_cl_N = 35 ; % wn input for N
iu_cl_E = 36 ; % wn input for E
iu_cl_h = 37 ; % wn input for h
iu_cl_axa = 38 ; % wn input for axa
iu_cl_aya = 39 ; % wn input for aya
iu_cl_aza = 40 ; % wn input for aza
iu_cl_V = 41 ; % wn input for V
iu_cl_alpha = 42 ; % wn input for alpha
iu_cl_beta = 43 ; % wn input for beta
% 44 bias input for p
% 45 bias input for q
% 46 bias input for r
% 47 bias input for phi
% 48 bias input for theta
% 49 bias input for psi
% 50 bias input for Nd
% 51 bias input for Ed
% 52 bias input for hd
% 53 bias input for N
% 54 bias input for E
% 55 bias input for h
% 56 bias input for axa
% 57 bias input for aya
% 58 bias input for aza
% 59 bias input for V
% 60 bias input for alpha
% 61 bias input for beta
iu_cl_attc1 = 62 ; % attc1 input
iu_cl_attc2 = 63 ; % attc2 input
iu_cl_attc3 = 64 ; % attc3 input

%                         indices for cl outputs
% 1 mult pert output for da
iy_cl_dec = 2 ; %  mult pert output for de and elevator command from claw
% 3 mult pert output for dr
iy_cl_throtc = 4 ; % % 2 mult pert output for throt and throt command from claw
% 5 mult pert output for p
% 6 mult pert output for q
% 7 mult pert output for r
% 8 mult pert output for phi
% 9 mult pert output for theta
% 10 mult pert output for psi
% 11 mult pert output for Nd
% 12 mult pert output for Ed
% 13 mult pert output for hd
% 14 mult pert output for N
% 15 mult pert output for E
% 16 mult pert output for h
% 17 mult pert output for axa
% 18 mult pert output for aya
% 19 mult pert output for aza
% 20 mult pert output for V
% 21 mult pert output for alpha
% 22 mult pert output for beta
% 23 output for p
iy_cl_q = 24 ; % output for q
% 25 output for r
% 26 output for phi
iy_cl_theta = 27 ; % output for theta
% 28 output for psi
% 29 output for Nd
% 30 output for Ed
% 31 output for hd
% 32 output for N
% 33 output for E
% 34 output for h
% 35 output for axa
% 36 output for aya
% 37 output for aza
% 38 output for V
iy_cl_alpha = 39 ; % output for alpha
% 40 output for beta
% 41 output for mu
% 42 output for da
% 43 output for de
% 44 output for dr
% 45 output for throt
% 46 output for ug
% 47 output for vg
% 48 output for wg

% 49 sn output for p
% 50 sn output for q
% 51 sn output for r
% 52 sn output for phi
% 53 sn output for theta
% 54 sn output for psi
% 55 sn output for Nd
% 56 sn output for Ed
% 57 sn output for hd
% 58 sn output for N
% 59 sn output for E
% 60 sn output for h
% 61 sn output for axa
% 62 sn output for aya
% 63 sn output for aza
% 64 sn output for V
% 65 sn output for alpha
% 66 sn output for beta

nact = length(u_names) ;
nsens = length(y_names) ;

if( mode == 2 )
    % find the closed loop zeros
    zeros_tht_attc = szeros(pck(acl,bcl(:,iu_cl_attc2),ccl(iy_cl_theta,:),dcl(iy_cl_theta,iu_cl_attc2))) ;
    if( do_prt )
        disp(' ')
        disp('closed loop zeros of theta/attc')
        warning off
        rifd(zeros_tht_attc)
        warning on
    end ;

    zeros_alpha_attc = szeros(pck(acl,bcl(:,iu_cl_attc2),ccl(iy_cl_alpha,:),dcl(iy_cl_alpha,iu_cl_attc2))) ;
    if( do_prt )
        disp(' ')
        disp('closed loop zeros of alpha/attc')
        warning off
        rifd(zeros_alpha_attc)
        warning on
    end ;
    
    if( do_prt )
        use_svd = 0 ;
        if( use_svd )
            % use SVD as alternative to tmp = dcl - ( ccl / acl ) * bcl ; since acl has zero eigs
            % for some reason the SVD approach does not give the correct
            % results here and I do NOT know why at this time 6/25/10
            [u_svd,s_svd,v_svd] = svd(acl) ;
            kdx = find( diag(s_svd) > 1.e-4 ) ;
            tmp = dcl([ iy_cl_theta iy_cl_alpha],iu_cl_attc2 ) - ...
                ccl([ iy_cl_theta iy_cl_alpha],: ) * v_svd(:,kdx) * ...
                ( s_svd(kdx,kdx) \ u_svd(:,kdx)' ) * bcl(:,iu_cl_attc2) ;
        else
            % use eig as alternative to tmp = dcl - ( ccl / acl ) * bcl ; since acl has zero eigs
            [v_eig,d_eig] = eig(acl) ;  % A * V = V * lam -> A = V * lam * inv(V) -> inv(A) = V * inv(lam) * inv(V)
            vinv_eig = inv(v_eig) ;
            kk = find( diag(abs(d_eig)) > 1.e-9 ) ;
            tmp = dcl([ iy_cl_theta iy_cl_alpha],iu_cl_attc2 ) - ...
                ccl([ iy_cl_theta iy_cl_alpha],: ) * ...
                ( v_eig(:,kk) / d_eig(kk,kk) ) * vinv_eig(kk,:) * bcl(:,iu_cl_attc2) ;
            tmp = real(tmp) ;
        end
        disp(' ')
        disp(['dcgain (theta,alpha)/attc = ' num2str(tmp') ])
    end
end

% find expected closed loop poles for attitude loops
% needs to be improved for zeta > 1 case
if( mode == 2 )
    if( att_type == 2 )
        % characteristic equation for io3
        % appropriate for att_type = 2, i.e theta where ff = 0
        % s^3 + 0.5*k1*s + 0.5*k2*k1*s + 0.5*fi2*k2^2*k1 = 0
        roots_io = roots([1 , 0.5 * Kb_rate , 0.5 * Kb_rate * Kb_att , 0.5 * Kb_rate * Kb_att^2 * fi_att ]) ;
        for i=1:3
            if( imag(roots_io(i)) ~= 0 )
                wn_io = abs(roots_io(i)) ;
                zeta_io = - real(roots_io(i)) / wn_io ;
            else
                lam_io = roots_io(i) ;
            end
        end
        wn_io = sqrt( 0.5 * Kb_rate * Kb_att - ( 0.5 * Kb_rate - fi_att * Kb_att / fc_att ) * fi_att * Kb_att / fc_att ) ;
        zeta_io = 0.5 * ( 0.5 * Kb_rate - fi_att * Kb_att / fc_att ) / wn_io ;
    elseif( att_type == 4 )
        tau = 1 / w_tt2 ;
        K1 = Kb_rate ;
        K2 = Kb_att ;
        fb = fb_att ;
        fi = fi_att ;
        fc = fc_att ;
        ff = ff_att ;

        if( use_io5 )
            % characteristic equation for io5
            % appropriate for att_type = 4, i.e alpha where ff ~= 0
            % s *( s^4 + c1 * s^3 + c2 *s^2 + c3 * s + c4 )
            c1 = 0.5 * K1 + fb * K2 + 1 / tau ;
            c2 = 0.5 * ( K2 - ff / tau ) * K1 + ( 0.5 * K1 + fb * K2 ) / tau + 0.5 * fb * K1 * K2 ;
            c3 = 0.5 * fi * K1 * K2^2 - 0.5 * ff * fb * K1 * K2 / tau + 0.5 * K1 * K2 / tau + ...
                0.5 * fb * K1 * K2 / tau + 0.5 * fb * K1 * K2^2 - 0.5 * fc * K1 * K2 / tau ;
            c4 = 0.5 * fi * fb * K1 * K2^3 - 0.5 * fb * fc * K1 * K2^2 / tau + 0.5 * fb * K1 * K2^2 / tau ;
            roots_io = roots([1 c1 c2 c3 c4 ]) ;
            wn_io = sqrt( 0.5 * ( K2 - ff / tau ) * K1 + 0.5 * K1 / tau - ...
                1 /( ff * fb ) * fi * K2 * ( 0.5 * K1 + 1 / tau - fi * K2 / ( ff * fb ) ) ) ;
            zeta_io = 0.5 * ( 0.5 * K1 + 1 / tau - ( fc - ff * fb ) * K2  / ff ) / wn_io ;
        else
            % characteristic equation for io4
            % appropriate for att_type = 4, i.e alpha where ff ~= 0 and no
            % feedforward of gamma dot is included
            % ( s + fb * K2 ) * ( s^3 + 0.5*K1 * s^2 + 0.5 * K1 * K2 * s + 0.5 * fi * K1 * K2 )
            roots_io = roots([1 , 0.5*K1+fb*K2 , 0.5*K1*K2+fb*K2*0.5*K1 , 0.5*fi*K1*K2^2+fb*K2*0.5*K1*K2 , fb*K2*0.5*fi*K1*K2^2 ]) ; 
            wn_io = sqrt( 0.5*K1*K2 + 0.5*fb*K1*K2 - fi*K2^2/ff - fc*K2*( 0.5*K1+fb*K2-fc*K2/ff)/ff ) ;
            zeta_io = 0.5 * ( 0.5 * K1 + fb * K2 - fc * K2 / ff ) / wn_io ;
        end
    end

    tau_io = 0 ;
    disp(' ')
    disp(['wn_io = ' num2str(wn_io) ' rad/sec , zeta_io = ' num2str(zeta_io) ', tau_io = ' num2str(tau_io) ' sec' ])
end


if( do_thist )

    tmin = -inf ;
    tmax = inf ;
    if( mode == 1 )
        rate1_step_cmd = p_step_cmd ;
        rate2_step_cmd = 0 ;
        rate3_step_cmd = 0 ;
        gthrot_step_cmd = 0 ;
        disp(' ')
        disp(' running p command step response')
        sim('cl')
        plt_title = 'p command = step' ;
        mkplt

        rate1_step_cmd = 0 ;
        rate2_step_cmd = q_step_cmd ;
        rate3_step_cmd = 0 ;
        gthrot_step_cmd = 0 ;
        disp(' ')
        disp(' running q command step response')
        sim('cl')
        plt_title = 'q command = step' ;
        mkplt

        rate1_step_cmd = 0 ;
        rate2_step_cmd = 0 ;
        rate3_step_cmd = r_step_cmd ;
        gthrot_step_cmd = 0 ;
        disp(' ')
        disp(' running r command step response')
        sim('cl')
        plt_title = 'r command = step' ;
        mkplt
    end
    if( mode == 2 )
        if( att_type == 2 )
            att1_step_cmd = phi_step_cmd ;
            att2_step_cmd = 0 ;
            att3_step_cmd = 0 ;
            gthrot_step_cmd = 0 ;
            disp(' ')
            disp(' running phi command step response')
            sim('cl')
            plt_title = 'phi command = step' ;
            mkplt

            att1_step_cmd = 0 ;
            att2_step_cmd = tht_step_cmd ;
            att3_step_cmd = 0 ;
            gthrot_step_cmd = 0 ;
            disp(' ')
            disp(' running theta command step response')
            sim('cl')
            plt_title = 'theta command = step' ;
            mkplt

            att1_step_cmd = 0 ;
            att2_step_cmd = 0 ;
            att3_step_cmd = psi_step_cmd ;
            gthrot_step_cmd = 0 ;
            disp(' ')
            disp(' running psi command step response')
            sim('cl')
            plt_title = 'psi command = step' ;
            mkplt
        elseif( att_type == 4 )
            att1_step_cmd = mu_step_cmd ;
            att2_step_cmd = 0 ;
            att3_step_cmd = 0 ;
            gthrot_step_cmd = 0 ;
            disp(' ')
            disp(' running mu command step response')
            sim('cl')
            plt_title = 'mu command = step' ;
            mkplt

            att1_step_cmd = 0 ;
            att2_step_cmd = alpha_step_cmd ;
            att3_step_cmd = 0 ;
            gthrot_step_cmd = 0 ;
            disp(' ')
            disp(' running alpha command step response')
            sim('cl')
            plt_title = 'alpha command = step' ;
            mkplt

            att1_step_cmd = 0 ;
            att2_step_cmd = 0 ;
            att3_step_cmd = beta_step_cmd ;
            gthrot_step_cmd = 0 ;
            disp(' ')
            disp(' running beta command step response')
            sim('cl')
            plt_title = 'beta command = step' ;
            mkplt
        end
    end
    if( mode == 3 )
        vel1_step_cmd = Nd_step_cmd ;
        vel2_step_cmd = 0 ;
        vel3_step_cmd = 0 ;
        att3_step_cmd = 0 ;
        disp(' ')
        disp(' running Nd command step response')
        sim('cl')
        plt_title = 'Nd command = step' ;
        mkplt

        vel1_step_cmd = 0 ;
        vel2_step_cmd = Ed_step_cmd ;
        vel3_step_cmd = 0 ;
        att3_step_cmd = 0 ;
        disp(' ')
        disp(' running Ed command step response')
        sim('cl')
        plt_title = 'Ed command = step' ;
        mkplt

        vel1_step_cmd = 0 ;
        vel2_step_cmd = 0 ;
        vel3_step_cmd = hd_step_cmd ;
        att3_step_cmd = 0 ;
        disp(' ')
        disp(' running hd command step response')
        sim('cl')
        plt_title = 'hd command = step' ;
        mkplt
    end
    if( mode == 4 )
        pos1_step_cmd = N_step_cmd ;
        pos2_step_cmd = 0 ;
        pos3_step_cmd = 0 ;
        att3_step_cmd = 0 ;
        disp(' ')
        disp(' running N command step response')
        sim('cl')
        plt_title = 'N command = step' ;
        mkplt

        pos1_step_cmd = 0 ;
        pos2_step_cmd = E_step_cmd ;
        pos3_step_cmd = 0 ;
        att3_step_cmd = 0 ;
        disp(' ')
        disp(' running E command step response')
        sim('cl')
        plt_title = 'E command = step' ;
        mkplt

        pos1_step_cmd = 0 ;
        pos2_step_cmd = 0 ;
        pos3_step_cmd = h_step_cmd ;
        att3_step_cmd = 0 ;
        disp(' ')
        disp(' running h command step response')
        sim('cl')
        plt_title = 'h command = step' ;
        mkplt
    end

    tm = find( t >= tmin & t <= tmax ) ;

    x_std = std(x(tm,:)) ;
    u_std = std(u(tm,:)) ;
    axyza_std = std(axyza(tm,:)) ;
    Vab_std = std(Vab(tm,:)) ;
    mu_std = std(mu(tm,:)) ;
    uc_std = std(uc(tm)) ;
    gust_std = std(gust(tm,:)) ;
    sn_std = std(sn(tm,:)) ;

    % %     t_MACH = t ;
    % %     x_MACH = x ;
    % %     u_MACH = u ;
    % %     y_MACH = y ;
    % %     h_MACH = h ;
    % %     nz_MACH = nz ;
    % %     throtc_MACH = throtc ;
    % %     dec_MACH = dec ;
end ;

if( do_cov & mode == 4 )

    % do steady state analysis
    iwn_cl = num_u + num_y + [ 1:num_y+3 ]  ;
    ibias_cl = num_u + num_y + 3 + num_y + [ 1:num_y ] ;

    if( do_prt )
        disp(' ')
        disp('response to sensor bias errors')
% %         disp(['bias inputs: ' y_names ])
        disp('18 bias inputs: pqr, phithtpsi, NEhdot, NEh, axyza, Vab')
        disp('26 outputs: pqr, phithtpsi, NEhdot, NEh, axyza, Vab, mu, u, gust')
        itmp = ( num_u + num_y + 1 ) : ( num_u + num_y + 26 ) ; 
        dcgain = dcl(itmp,ibias_cl) - ccl(itmp,:) / acl * bcl(:,ibias_cl)
    end

    SYS = ss(acl,bcl(:,iwn_cl),ccl,dcl(:,iwn_cl)) ;
    W = eye(length(iwn_cl)) ;
    P = covar(SYS,W) ;
    sigma = [ ] ;
    for i =1:size(P,1)
        sigma = [ sigma sqrt(P(i,i)) ] ;
    end ;
    if( do_prt )
        sigma_uc = sigma(1,1:4)
        sigma_x = sigma(1,num_u + num_y + [1:12])
        sigma_axyza = sigma(1,num_u + num_y + [13:15])
        sigma_Vab = sigma(1,num_u + num_y + [16:18])
        sigma_mu = sigma(1,num_u + num_y + 19)
        sigma_u = sigma(1,num_u + num_y + 19 + [1:num_u])
        sigma_gust = sigma(1,num_u + num_y + 19 + num_u + [1:3])
        sigma_sn = sigma(1,num_u + num_y + 19 + num_u + 3 + [1:num_y])
    end
else 
    sigma = zeros(1,size(ccl,1)) ;
end

if( do_fresp == 1 )
    uy_names = horzcat(u_names,y_names) ;
    clsys = ss(acl,bcl,ccl,dcl) ;
    % do the frequency response analysis
    Hcl = freqresp(clsys,ww) ;

    Hu = [ ] ;
    Hy = [ ] ; 
    
    i_u = 1:nact ;
    i_y = nact+1:nact+nsens ;
    for i=1:length(ww)
        Hu = [ Hu , svd(squeeze(Hcl(i_u,i_u,i))) ] ;
        Hy = [ Hy , svd(squeeze(Hcl(i_y,i_y,i))) ] ;
    end ;
    disp(' ')
    [Hu_bnds,MUINFO] = mussv(Hcl(i_u,i_u,:),ones(nact,2)) ;
    [Hy_bnds,MUINFO] = mussv(Hcl(i_y,i_y,:),ones(nsens,2)) ;

    Muu = squeeze(Hu_bnds)' ;
    Myy = squeeze(Hy_bnds)' ;
    
    [max_ubnds,Iu_bnds] = max(Muu(:,1)) ;
    [max_ybnds,Iy_bnds] = max(Myy(:,1)) ;
    wmu_u = ww(Iu_bnds) ;
    wmu_y = ww(Iy_bnds) ;
    
    [maxMuu,indx_Muu] = max(Muu) ;
    [maxMyy,indx_Myy] = max(Myy) ;
    if( do_prt )
        max_over_w_bnds = [ maxMuu ; maxMyy ] ;
        max_over_w_lower_and_upper_bnds = max_over_w_bnds(:,[2 1])
        
        w_mu_max = [ ww(indx_Muu(1)) maxMuu(1) ;  ww(indx_Myy(1)) maxMyy(1) ] ;
        disp('loop       w      max(mu)')
        disp(sprintf('%6s %8.4f %8.2f','u' ,ww(indx_Muu(1)),maxMuu(1)))
        disp(sprintf('%6s %8.4f %8.2f','y' ,ww(indx_Myy(1)),maxMyy(1)))
    end
    
    if( do_plt )
        figure
        subplot(2,1,1) , loglog(ww,squeeze(Hu_bnds(1,1:2,:)),[ww(1) ww(end)],[1 1],'k-')
        axis([ ww(1) ww(end) 0.1 10 ])
        title('structured singular value upper and lower bounds for multiplicative perturbations')
        ylabel([ num2str(nact) ' actuators'])
        subplot(2,1,2) , loglog(ww,squeeze(Hy_bnds(1,1:2,:)),[ww(1) ww(end)],[1 1],'k-')
        axis([ ww(1) ww(end) 0.1 10 ])
        ylabel([ num2str(nsens) ' sensors'])
        xlabel('frequency (rad/sec)')

        figure
        loglog(ww,squeeze(Hu_bnds(1,1,:)),ww,squeeze(Hy_bnds(1,1,:)),[ww(1) ww(end)],[1 1],'k-')
        title('structured singular value upper bounds for multiplicative perturbations')
        axis([ ww(1) ww(end) 0.1 10 ])
        ylabel('upper bound for ssv')
        xlabel('frequency (rad/sec)')
%         legend([num2str(nact) ' actuators'],[num2str(nsens)' sensors'])    % ask spratt to help    
        legend('4 actuators','18 sensors')
    end

    % y = - L * ( u + y )
    % (1+L)*y = - L * u
    % y = - L/(1+L) * u
    % let M = -L/(1+L)
    % (1+L) * M = -L
    % (1 + M ) * L + M = 0
    % L = - M / ( 1 + M )

    all_gm = [ ] ;
    all_pm = [ ] ;
    all_lp = [ ] ;

    for idx = 1:nact+nsens
        mcl = squeeze(Hcl(idx,idx,:)) ;
        lp = - ( 1 + mcl ) .\ mcl ;
        if( max(abs(lp)) > 1.e-3 )
            [ gm_results,pm_results ] = gpm([lp ww'],idx) ;
            all_gm = [ all_gm ; gm_results ] ;
            all_pm = [ all_pm ; pm_results ] ;
        end ;
        all_lp = [ all_lp , lp ] ;
    end ;
    
    name_length = -max(cellfun('length',uy_names)) ;
    
    disp(' ')
    disp('loop      w        GM')
    disp(' ')
    if( size(all_gm,1) > 0 )
        [Y,I_gm] = sort(abs(all_gm(:,3)),1,'ascend') ;
        if( do_prt )
            sort_all_gm = all_gm(I_gm,:) ;
           
            for kkk = I_gm'
                disp(sprintf('%*s %8.4f %8.2f',name_length,uy_names{all_gm(kkk,1)},all_gm(kkk,2:3)))
            end

        end
        igm_gmin1 = all_gm(I_gm(1),1) ;
        wgm_gmin1 = all_gm(I_gm(1),2) ;
        gm_gmin1 = all_gm(I_gm(1),3) ;
        if( size(all_gm,1) > 1 )
            igm_gmin2 = all_gm(I_gm(2),1) ;
            wgm_gmin2 = all_gm(I_gm(2),2) ;
            gm_gmin2 = all_gm(I_gm(2),3) ;
        else
            igm_gmin2 = 0 ;
            wgm_gmin2 = 0 ;
            gm_gmin2 = Inf ;
        end
    else
        disp('no gm found')
    end
    
    disp(' ')
    disp('loop      w        PM')
    disp(' ')
    if( size(all_pm,1) > 0 )
        [Y,I_pm] = sort(abs(all_pm(:,3)),1,'ascend') ;
        if( do_prt )
            sort_all_pm = all_pm(I_pm,:) ;

            for kkk = I_pm'
                disp(sprintf('%*s %8.4f %8.2f',name_length,uy_names{all_pm(kkk,1)},all_pm(kkk,2:3)))
            end
        end
        ipm_pmin1 = all_pm(I_pm(1),1) ;
        wpm_pmin1 = all_pm(I_pm(1),2) ;
        pm_pmin1 = all_pm(I_pm(1),3) ;
        ipm_pmin2 = all_pm(I_pm(2),1) ;
        wpm_pmin2 = all_pm(I_pm(2),2) ;
        pm_pmin2 = all_pm(I_pm(2),3) ;
    else
        disp('no pm found')
    end
    
    if( do_plt )
        use_several_plot_pages = 1 ;
        if( use_several_plot_pages )

            figure
            loglog(ww,abs(all_lp(:,i_u)),[ww(1) ww(end)],[1 1],'k-')
            title('broken loop single-loop-at-a-time analysis')
            axis([ww(1) ww(end) 0.01 100 ])
            ylabel('loop gain')
            legend(u_names)
            
            figure
            yidx = [1:6] ;
            pltidx = num_u + yidx ; 
            loglog(ww,abs(all_lp(:,pltidx)),[ww(1) ww(end)],[1 1],'k-')
            title('broken loop single-loop-at-a-time analysis')
            axis([ww(1) ww(end) 0.01 100 ])
            ylabel('loop gain')
            xlabel('frequency (rad/sec)')
            legend(y_names(yidx))
            grid off
            
            figure
            yidx = [7:12] ;
            pltidx = num_u + yidx ; 
            loglog(ww,abs(all_lp(:,pltidx)),[ww(1) ww(end)],[1 1],'k-')
            title('broken loop single-loop-at-a-time analysis')
            axis([ww(1) ww(end) 0.01 100 ])
            ylabel('loop gain')
            xlabel('frequency (rad/sec)')
            legend(y_names(yidx))
            grid off
            
            figure
            yidx = [13:18] ;
            pltidx = num_u + yidx ; 
            loglog(ww,abs(all_lp(:,pltidx)),[ww(1) ww(end)],[1 1],'k-')
            title('broken loop single-loop-at-a-time analysis')
            axis([ww(1) ww(end) 0.01 100 ])
            ylabel('loop gain')
            xlabel('frequency (rad/sec)')
            legend(y_names(yidx))
            grid off
        else
            figure
            subplot(2,1,1) , loglog(ww,abs(all_lp(:,i_u)),[ww(1) ww(end)],[1 1],'k-')
            title('broken loop single-loop-at-a-time analysis')
            axis([ww(1) ww(end) 0.01 100 ])
            ylabel('loop gain')
            legend(u_names)
            subplot(2,1,2) , loglog(ww,abs(all_lp(:,i_y)),[ww(1) ww(end)],[1 1],'k-')
            axis([ww(1) ww(end) 0.01 100 ])
            ylabel('loop gain')
            xlabel('frequency (rad/sec)')
            legend(y_names)
            grid off
        end
    end
    
    if( mode == 4 & do_psd )
        iii = iy_cl_throtc ;
        jjj = [ iy_cl_u_wn iy_cl_w_wn iy_cl_q_wn iy_cl_tht_wn iy_cl_nz_wn iy_cl_nx_wn iy_cl_h_wn iu_cl_ug iu_cl_wg ] ;

        nww = length(ww) ;
        psd = [ ] ;
        for k = 1:nww
            tmpG = Hcl(iii,jjj,k) ;
            psd = [ psd tmpG * tmpG' ] ;
        end
        
        if( do_plt )
            figure
            loglog(ww,psd)
            ylabel('PSD (epr^2/(rad/sec))')
            xlabel('frequency (rad/sec)')
        end ;
        psd_MACH = psd ;
        ww_MACH = ww ;
    end

    if( mode == 2 )
        crude_fit = 0 ;
        if( att_type == 2 )
            if( crude_fit )
                [wn,zeta,tau] = get_rom(ww,squeeze(Hcl(iy_cl_theta,iu_cl_attc2,:))) ;
            else
                wn = wn_io ;
                zeta = zeta_io ;
                tau = 0 ;
            end
            sys = ss([0,1;-wn^2,-2*zeta*wn],[0;wn^2],[1,0],0) ;
            sysg1 = squeeze(freqresp(sys,ww)) ;
            sysg2 = exp( - sqrt(-1) * tau * ww' ) ;
            sysg = sysg1 .* sysg2 ;
        else
            if( crude_fit )
                [wn,zeta,tau] = get_rom(ww,squeeze(Hcl(iy_cl_alpha,iu_cl_attc2,:))) ;
            else
                wn = wn_io ;
                zeta = zeta_io ;
                tau = 0 ;
            end
            sys = ss([0,1;-wn^2,-2*zeta*wn],[0;wn^2],[1,0],0) ;
            sysg1 = squeeze(freqresp(sys,ww)) ;
            sysg2 = exp( - sqrt(-1) * tau * ww' ) ;
            sysg = sysg1 .* sysg2 ;
        end
        if( do_plt )
            % plot closed loop response theta/attc
            figure
            if( att_type == 2 )
                subplot(2,1,1) , loglog(ww,squeeze(abs(Hcl(iy_cl_theta,iu_cl_attc2,:))),'-', ...
                    ww,abs(sysg),':')
                legend('actual','reference 2nd order')
            else
                subplot(2,1,1) , loglog(ww,squeeze(abs(Hcl(iy_cl_theta,iu_cl_attc2,:))),'-')
            end
            title('closed loop response: theta/attc')
            ylabel('gain (deg/deg)')
            axis([ ww(1) ww(end) 0.01 10 ])
            if( att_type == 2 )
                subplot(2,1,2) , semilogx(ww,squeeze(r2d*angle(Hcl(iy_cl_theta,iu_cl_attc2,:))),'-', ...
                    ww,r2d*angle(sysg),':')
            else
                subplot(2,1,2) , semilogx(ww,squeeze(r2d*angle(Hcl(iy_cl_theta,iu_cl_attc2,:))))
            end
            ylabel('phase (deg)')
            xlabel('frequency (rad/sec)')

            % plot closed loop response alpha/attc
            figure
            if( att_type == 4 )
                subplot(2,1,1) , loglog(ww,squeeze(abs(Hcl(iy_cl_alpha,iu_cl_attc2,:))),'-', ...
                    ww,abs(sysg),':')
                legend('actual','reference 2nd order')
            else
                subplot(2,1,1) , loglog(ww,squeeze(abs(Hcl(iy_cl_alpha,iu_cl_attc2,:))))
            end
            title('closed loop response: alpha/attc')
            ylabel('gain (deg/deg)')
            axis([ ww(1) ww(end) 0.01 10 ])
            if( att_type == 4 )
                subplot(2,1,2) , semilogx(ww,squeeze(r2d*angle(Hcl(iy_cl_alpha,iu_cl_attc2,:))),'-', ...
                    ww,r2d*angle(sysg),':')
            else
                subplot(2,1,2) , semilogx(ww,squeeze(r2d*angle(Hcl(iy_cl_alpha,iu_cl_attc2,:))))
            end
            ylabel('phase (deg)')
            xlabel('frequency (rad/sec)')
        end
    end

end ;

namefigs

if( do_fresp & do_cov )
    this_run_results = [ fc_obac ; fc_trac ; ...
        w_ph ; z_ph ; w_sp ; z_sp ; w_tt1 ; w_tt2 ; ...
        wcl_zmin1 ; zcl_zmin1 ; wcl_zmin3 ; zcl_zmin3 ; ...
        wmu_u ; max_ubnds ; wmu_y ; max_ybnds ;...
        igm_gmin1 ; wgm_gmin1 ; gm_gmin1 ; igm_gmin2 ; wgm_gmin2 ; gm_gmin2 ; ...
        ipm_pmin1 ; wpm_pmin1 ; pm_pmin1 ; ipm_pmin2 ; wpm_pmin2 ; pm_pmin2 ; ...
        sigma' ] ;
end

% the comments below have not been updated as of 6/26/10

% the variables unique to the TRAC will have _trac in their name
% the variables for the OBAC will NOT have _obac in their name

% the following variables will NOT be mismatched between TRAC and OBAC
% alp_trim 
% stht and ctht
% Cvel 

% the following variables will be mismatched between TRAC and OBAC
% e.g. mass properties can be mismatched 
% Aac
% Bac

% the following variable may also be mismatched but are only used for
% reporting the results, i.e. they are not used in the analyses


% variables used in cl.mdl:

% aircraft:
% Aac
% Bac
% Cvel
% stht
% g


% engine:
% Kengine

% gust:
% V_trim
% Lu
% Lw

% sensor errors:
% Asn_p
% Asn_q
% Asn_r
% Asn_phi
% Asn_tht
% Asn_psi
% Asn_Nd
% Asn_Ed
% Asn_hd
% Asn_N
% Asn_E
% Asn_h
% Bsn_p
% Bsn_q
% Bsn_r
% Bsn_phi
% Bsn_tht
% Bsn_psi
% Bsn_Nd
% Bsn_Ed
% Bsn_hd
% Bsn_N
% Bsn_E
% Bsn_h

% MACH
% c_rate
% ca_rate
% cbinv_rate
% Kb_rate
% fi_rate
% fc_rate
% integ_MACH_rate_a
% integ_MACH_rate_b
% integ_MACH_rate_c
% integ_MACH_rate_d
% c_att
% Kb_att
% fi_att
% fc_att
% integ_MACH_att_a
% integ_MACH_att_b
% integ_MACH_att_c
% integ_MACH_att_d
% c_vel
% ca_vel
% cbinv_vel
% Kb_vel
% fi_vel
% fc_vel
% integ_MACH_vel_a
% integ_MACH_vel_b
% integ_MACH_vel_c
% integ_MACH_vel_d
% Kb_pos
% fi_pos
% fc_pos
% integ_MACH_pos_a
% integ_MACH_pos_b
% integ_MACH_pos_c
% integ_MACH_pos_d

% commands:
% vgnd_step_cmd
% alt_step_cmd

% claw:
% Krate
% Katt
% Kvel
% Kpos

% unit conversion:
% r2d

% simulation configuration parameters:
% tsim_max
% delt
