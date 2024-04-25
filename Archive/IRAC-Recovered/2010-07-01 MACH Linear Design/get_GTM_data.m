% this script creates the following list of variables used in do_analysis
% Aac Aac_trac Bac Bac_trac V_trim alp_trim iu_d iu_dth w_d zeta_d Kengine

do_prt = 1 ;

% engine "actuator" 1st order transfer function break frequency
Kengine = 1 ;
% control surface actuator 2nd order transfer function natural frequency and damping ratio
w_d = 20 ;
zeta_d = 0.7 ;

% load the data for the different flight conditions
load fc_01 % contains these variables: a b c d tt tt1
fc_trac = 1 ;
fc_obac = 1 ;

% trim values are derived from the similarity transformation in the *.mat file
V_trim = sqrt( 1 / ( tt(5,4)^2 + tt(5,6)^2 ) ) ;
alp_trim = atan2(-tt(5,4),tt(5,6)) ;
tht_trim = alp_trim ; % assume gamma = 0
altitude = 0 ; % altitude is used for gust model

% this needs to be updated <------------------------------------
cosc = 0 ;
sinc = 1 ;

% the old states (using MACH nlsim states) are
% p,q,r, u,v,w, N,E,h, e0,e1,e2,e3

% for choice 1: the new states are (corresponds to tt1 below)
% p,q,r, u,v,w, N,E,h, exx, phi,theta,psi

% for choice 2: the new states are (corresponds to tt below)
% p,q,r, V,alpha,beta, N,E,h, exx, phi,theta,psi

% using choice 1 for NASA IRAC GTM
tt3 = inv(tt1) ;
abigpre = tt3 \ ( a * tt3 ) ;
bbigpre = tt3 \ b ;
cbigpre = c * tt3 ;

% second similarity transformation
% old2 states = p,q,r, u,v,w, N,E,h, exx, phi,theta,psi
% new2 states = p,q,r, phi,theta,psi, Nd,Ed,hd, N,E,h

tmp = eye(13) ;
tt4inv = [ tmp(1:3,:) ; tmp(11:13,:) ; abigpre(7:9,:) ; tmp(7:9,:) ; tmp(10,:) ] ;
tt4 = inv(tt4inv) ;

abig = tt4 \ ( abigpre * tt4 ) ;
bbig = tt4 \ bbigpre ;
cbig = cbigpre * tt4 ;

Tuvw2NEhd = tt4(4:6,7:9) ; % this is used in cl/aricraft/aircraft.mdl for introduction of gust

%% suvo - start
use_Vab_states = 0;
if use_Vab_states

    % using choice 2 for NASA IRAC GTM
    % old1 states = p,q,r, u,v,w, N,E,h, e0,e1,e2,e3;
    % new1 states = p,q,r, V,alpha,beta, N,E,h, exx, phi,theta,psi
    tt3x = inv(tt) ;
    abigprex = tt3x \ ( a * tt3x ) ;
    bbigprex = tt3x \ b ;
    cbigprex = c * tt3x ;
    
    % second similarity transformation
    % old2 states = p,q,r, V,alpha,beta, N,E,h, exx, phi,theta,psi
    % new2 states = p,q,r, V,alpha,beta, N,E,h, phi,theta,psi, exx
    
    tmpx = eye(13) ;
    tt4invx = [ tmpx(1:9,:) ; tmpx(11:13,:) ; tmpx(10,:) ] ;
    tt4x = inv(tt4invx) ;
    
    abigx = tt4x \ ( abigprex * tt4x ) ;
    bbigx = tt4x \ bbigprex ;
    cbigx = cbigprex * tt4x ;
    
    Tuvw2Vab  = tt3x(4:6,4:6);
    
    % over-writing some vars
    Tuvw2NEhd = Tuvw2Vab;  % Now Tuvw2NEhd actually represents Tuvw2Vab
    abig = abigx;  % it seems abig is only used in Aac_trac and Ac
    bbig = bbigx;  % - similar -
    cbig = cbigx;  % - similar -
    %dbig = dbigx;  % - similar -
    
end
% suvo - end

%%
%                   1      2     3     4      5          6           7       8       9       10
% MACH.u_names = [ 'elev' 'ail' 'rud' 'stab' 'elevgain' 'throtdiff' 'throt' 'tvc_m' 'tvc_n' 'rcs00'
jx = [ 1:12 ] ;
ju = [ 2 1 3 7 ] ;
iy_axyza = 1:3 ;
iy_mab = 25:27 ;
iy_Vab = 33:35 ; % used in cl/aircraft/aircraft.mdl

num_u = length(ju) ;
num_y = 18 ; % 12 states + 3 accels + 3 Vab
iu_d = 1:3 ; % actuator in cl.mdl assumes d is 1:num_u-1 and throt is num_u
iu_throt = 4 ;
iu_de = 2 ; % used for siso ol zeros of alpha/de
num_d = length(iu_d) ;

Aac = abig(jx,jx) ;
Bac = bbig(jx,ju) ;
Cac = cbig(:,jx) ;
Dac = d(:,ju) ;

Aac_trac = Aac ;
Bac_trac = Bac ;
Cac_trac = Cac ;
Dac_trac = Dac ;

% perform computations for longitudinal axes
ix_LG = [ 2 4 6 12 ] ; % longitudinal states are q, u, w, tht

% determine open loop phugoid and short period frequencies and damping ratios
lam_ol = eig(abigpre(ix_LG,ix_LG)) ;
if( do_prt )
    disp(' ')
    disp('open loop poles of longitudinal model')
    warning off
    rifd(lam_ol)
    warning on
end
w_ol = abs(lam_ol) ;
zeta_ol = -real(lam_ol) ./ ( w_ol + ( w_ol == 0 ) .* ones(size(w_ol)) ) ;
[Y,I_wol] = sort(abs(w_ol),1,'ascend') ;
w_ph = w_ol(I_wol(1)) ;
z_ph = zeta_ol(I_wol(1)) ;
w_sp = w_ol(I_wol(3)) ;
z_sp = zeta_ol(I_wol(3)) ;

% find Ttheta1 and Ttheta2 from q/de ol zeros
zeros_q_de = szeros(pck(abigpre(ix_LG,ix_LG),bbigpre(ix_LG,iu_de),[ 1 zeros(1,3)],0)) ;
if( do_prt )
    disp(' ')
    disp('open loop zeros of q/de')
    warning off
    rifd(zeros_q_de)
    warning on
end ;
w_olz = abs(zeros_q_de) ;
[Y,I_wolz] = sort(abs(w_olz),1,'descend') ;
w_tt2 = w_olz(I_wolz(1)) ;
w_tt1 = w_olz(I_wolz(2)) ;

% % zeros_alpha_de = szeros(pck(Aac_trac,Bac_trac(:,iu_de),Calpha,0)) ;
zeros_alpha_de = szeros(pck(abigpre(ix_LG,ix_LG),bbigpre(ix_LG,iu_de),cbigpre(iy_mab(2),ix_LG),0)) ;
if( do_prt )
    disp(' ')
    disp('open loop zeros of alpha/de')
    warning off
    rifd(zeros_alpha_de)
    warning on
end ;
