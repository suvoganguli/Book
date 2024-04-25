% linearize the equations of motion for the OBAC
% first execute doit.m, run the simulation, i.e. main_sim, execute mkplt.m

% sample state and u at this time 

% for DamageCase = 0, t = 19; (vel-loop closed), 11/03/10
% for DamageCase = 3, t = 19; (vel-loop closed), 11/03/10
% for DamageCase = 1, t = 0.01 (19 gives steady-state results)

time_linmod = input('Enter time for linmod: ') ; % 5.0

r2d = 180 / pi ;

if( ~exist('t') )
    disp(' ')
    disp('run the simulation so the t variable will exist')
    return
end

t_lm_idx = find( t == time_linmod ) ;

if( isempty(t_lm_idx) )
    disp(' ')
    disp('the t variable from the simulation does not include time_linmod')
    return
end

if( ~exist('y_aero_vel_idx') )
    disp(' ')
    disp('run mkplt so the needed indicies will exist')
    return
end

t1_lm_idx = find( t1 == time_linmod ) ;
xu = [ x(t_lm_idx,:) u_out(t1_lm_idx,:) zeros(1,3) ] ;

disp(' ')
disp('Velocity (ft/sec), alpha (deg), gamma (deg), altitude (feet) =')
vagh = [ y(t_lm_idx,y_aero_vel_idx) r2d*y(t_lm_idx,y_aero_alpha_idx) r2d*vchigam(t_lm_idx,3) x(t_lm_idx,9) ]

% use linmod to linearize the eom. Note no states, so [ A B ; C D ] contained in tmpd
[tmpa,tmpb,tmpc,tmpd] = linmod('xdot_obac') ;

disp(' ')
disp('poles of linearized model')
warning off
rifd(eig(tmpd(1:13,1:13)))
warning on

% record data corresponding to the linearization of trim point
xuyxdot_trim = [ x(end,:)' ; u_servo(end,:)' ; y(end,:)' ; xdot(end,:)' ] ;

if(0)
    ix_LG = [ 2 4 6 9 10:13 ] ;

    a_LG = tmpd(ix_LG,ix_LG) ;
    disp(' ')
    disp('open loop longitudinal poles')
    rifd(eig(a_LG))

    ix_LD = [ 1 3 5 10:13 ] ;

    a_LD = tmpd(ix_LD,ix_LD) ;
    disp(' ')
    disp('open loop lateral-directional poles')
    rifd(eig(a_LD))
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
a = tmpd(1:13,1:13) ;
b = tmpd(1:13,14:end) ;
c = tmpd(14:end,1:13) ;
d = tmpd(14:end,14:end) ;

use_eigenvector_approach = 0 ;
if( use_eigenvector_approach )
    % trying to find the eigenvector that corresponds to the quaternion
    % state that is non-minimal so this state can be removed from the model
    % and we can proceed with phi, theta, psi as states instead of
    % quaternions. Note the eigenvalue for the state of interest is at the
    % origin and there are other eigenvalues at the origin so it is not
    % trivial to find the index for the eigenvalue of interest. I stopped
    % trying to make this approach work when it appeared that I was getting
    % two eigenvectors that were very close to the same which did not make
    % sense to me.
    [eigvec,eigval] = eig(a) ;
    eigval = diag(eigval) ;
    
    % find indices of the eigenvalues near the origin
    [tmpi,tmpj] = find(abs(eigval) < 0.01 ) ;

    eigvecinv = inv(eigvec) ;

    tmpvec = eigvecinv(tmpi,:)' ;

    % normalize the eigenvectors selected to make the 4 elements
    % corresponding to the quaternions have unit length. I did this so I
    % could examine the normalized eigenvectors and look for the trim
    % quaternion in the rows corresponding to the quaternions. Here is
    % where I found that two eigenvectors appeared to be essentially the
    % same which does not make sense. I also checked that the eigvev *
    % eigvecinv ~ eye(13) and this seemed to work out so I am puzzled. Some
    % of the singular values of eigvec were near zero so this approach is
    % going to be very sensitive if it works at all and I stopped using
    % this approach. Note tmpvec_scl was not used for anything other than
    % inspection.
    tmpe = real(tmpvec(10:13,:)) ;
    tmpe2 = diag( 1./sqrt( diag(tmpe' * tmpe ) ) ) ;
    tmpvec_scl = real(tmpvec * tmpe2) ;

    if( max(abs(imag(tmpvec))) > 1e-6 )
        disp('imag part of eigenvector is not small')
        return
    end
    tmpvec = real(tmpvec) ;
else
    tmpvec = [ zeros(9,1) ; xu(10:13)' ] ;
end

% A new state vaiable for the non-minimal quaternion norm state is derived
% as follows
    % a * tmpvec = 0 * tmpvec
    % x_old = eigvec * x_new
    % x_new = inv(eigvec) * x_old

% set up a similarity transformation
    % the old states are
    % p,q,r, u,v,w, N,E,h, e0,e1,e2,e3

    % for choice 1: the new states are (not in use but corresponds to tt1 below)
    % p,q,r, u,v,w, N,E,h, exx, phi,theta,psi
    
    % for choice 2: the new states are (this is in use and corresponds to tt below)
    % p,q,r, V,alpha,beta, N,E,h, exx, phi,theta,psi

tmp_eye = eye(13) ;

% similarity transformation for choice 1:
tt1 = [ tmp_eye(1:9,:) ; ... % p,q,r,u,v,w,N,E,h
    tmpvec' ; ... % non-minimal quaternion state
    c(22:24,1:13) ] ; % phi, theta, psi

% similarity transformation for choice 2:
tt = [ tmp_eye(1:3,:) ; ... % p,q,r
    c(33:35,1:13) ; ... % V,alpha,beta
    tmp_eye(7:9,:) ; ... % N,E,h
    tmpvec' ; ... % non-minimal quaternion state
    c(22:24,1:13) ] ; % phi, theta, psi

sys = ss(a,b,c,d) ;
sys2 = ss2ss(sys,tt) ;
[f,g,h,d2] = ssdata(sys2) ;

%% Generating plant for MRAC design

do_suvo_analysis = 1;
if do_suvo_analysis
    sys_tt1 = ss2ss(sys,tt1) ;
    [a_tt1,b_tt1,c_tt1,d_tt1] = ssdata(sys_tt1) ;
    
    % From: p,q,r, u,v,w, N,E,h, exx, phi,theta,psi
    % To:   v,p,r,phi
    ix_LD_tt1 = [ 5 1 3 11 ] ;
    % From: de da dr stab elevgain throtdiff throt tvc_m tvc_n rcs00
    % To: da dr
    iu_LD_tt1 = [ 2 3 ] ;
    a_tt1_LD = a_tt1(ix_LD_tt1,ix_LD_tt1); % FINAL OUTPUT for suvo_analysis
    b_tt1_LD = b_tt1(ix_LD_tt1,iu_LD_tt1); % FINAL OUTPUT for suvo_analysis
    
end
%%

% get eigenvalues after transformation (will be the same as eig(a))
eigs13 = eig(f) ;
real13 = real(eigs13) ;
[max_real,ix] = max(real13) ;

% select a subset of the states for longitudinal case including altitude
ix_LG = [ 2 4 5 9 12 ] ;

a_LG = f(ix_LG,ix_LG) ;
disp(' ')
disp('open loop longitudinal poles including h')
rifd(eig(a_LG))

% select a subset of the states for lateral-directional case including psi
ix_LD = [ 1 3 6 11 13 ] ;

a_LD = f(ix_LD,ix_LD) ;
disp(' ')
disp('open loop lateral-directional poles including psi')
rifd(eig(a_LD))

% select a subset of the states for longitudinal case excluding altitude
ix1_LG4 = [ 2 4 5 12 ] ;
ix_LG4 = [ 4 5 12 2 ] ; % V alpha theta q to agree with Gulfstream order
iu_LG4 = [ 2 4 8 ] ; % elev eltab throt (close as possible to Gulfstream: del dstab epr for right now)

a_LG4 = f(ix_LG4,ix_LG4) ;
b_LG4 = g(ix_LG4,iu_LG4) ;
disp(' ')
disp('open loop longitudinal poles w/o h')
rifd(eig(a_LG4))

% select a subset of the states for lateral-directional case excluding psi
ix1_LD4 = [ 1 3 6 11 ] ;
ix_LD4 = [ 6 11 1 3 ] ; % beta, phi, p , r to agree with Gulfstream order
iu_LD4 = [ 1 1 3 1 1 ] ; % ail ail rud ail ail (close as possible to Gulfstream: daill dailr drud dsl dsb for right now)

a_LD4 = f(ix_LD4,ix_LD4) ;
b_LD4 = g(ix_LD4,iu_LD4) ;
disp(' ')
disp('open loop lateral-directional poles w/o psi')
rifd(eig(a_LD4))

% record variables for documentation and comparison with other models
tmp_LG = [ a_LG4 b_LG4  zeros(4,2) ] ;
tmp_LD = [ a_LD4 b_LD4 ] ;
LG0LD = [ tmp_LG ; zeros(1,9) ; tmp_LD ] ;

save -ASCII tmp_LG0LD LG0LD

abcd = tmpd ;
save -ASCII tmp_abcd abcd

fghd = [ f g ; h d ] ;
save -ASCII tmp_fghd fghd

save -ASCII tmp_trim xuyxdot_trim

save fc_xx abcd fghd LG0LD xuyxdot_trim

return

load augment_with_linmod_data

fc = 38 + 4 + config.fcase ;
aug_tbl_weight(fc) = trac_params.mass_IC * constants.g ;
aug_tbl_V(fc) = y(t_lm_idx,y_aero_vel_idx) ;
aug_tbl_alpha(fc) = y(t_lm_idx,y_aero_alpha_idx) ;
aug_tbl_theta(fc) = y(t_lm_idx,y_rpy_idx(2))  ;
aug_tbl_h(fc) = x(t_lm_idx,9) ;
aug_tbl_cas(fc) = sqrt( 2 * y(t_lm_idx,y_aero_qbar_idx) / constants.rho0 ) / constants.knots2fps ;

for i = 1:4
    for j = 1:4
        aug_A_lon(i,j,fc) = a_LG4(i,j) ;
        aug_A_lat(i,j,fc) = a_LD4(i,j) ;
    end
    for j=1:3
        aug_B_lon(i,j,fc) = b_LG4(i,j) ;
    end
    for j=1:5
        aug_B_lat(i,j,fc) = b_LD4(i,j) ;
    end
end

return

save augment_with_linmod_data aug_*
