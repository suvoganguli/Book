load linmodel_fcase1_eas75_vab  % loads londyn latdyn MWS_new Xtrim Trimcond
 

%% Create Short Period Model

% [alpha, q] <- elev

tmpdyn = modred(londyn,[1 4],'Truncate');
spdyn = tmpdyn(2:3,1);

% tmpdyn = londyn(2:3,1); 
% a = tmpdyn.a(2:3,2:3);
% b = tmpdyn.b(2:3,:);
% c = tmpdyn.c(:,2:3);
% d = tmpdyn.d;
% spdyn = ss(a,b,c,d);
% spdyn.StateName = [{'alpha'} {'q'}]';
% spdyn.InputName = 'Elevator';
% spdyn.OutputName = [{'alpha'} {'q'}]';

Za  = spdyn.a(1,1);
Zq  = spdyn.a(1,2);
Zde = spdyn.b(1,1);
Ma  = spdyn.a(2,1);
Mq  = spdyn.a(2,2);
Mde = spdyn.b(2,1);

% Eigenvalues
fprintf('londyn\n');
rifd(eig(londyn.a))
fprintf('\nspdyn\n');
rifd(eig(spdyn.a))


%% Aero-data

load GTM_Aero

data_CZ_bas = Aero.C6_bas.data(:,14,3); % alpha, beta, Z
data_alpha = Aero.C6_bas.alpha;
figure(1);
subplot(211)
plot(data_alpha, -data_CZ_bas);
grid on
xlabel('\alpha (deg)');
ylabel('CL-bas');
subplot(212)
plot(data_alpha,gradient(-data_CZ_bas,data_alpha)*180/pi);
grid on
xlabel('\alpha (deg)');
ylabel('CL-bas_\alpha');

data_CM_bas = Aero.C6_bas.data(:,14,5); % alpha, beta, M
data_alpha = Aero.C6_bas.alpha;
figure(2);
subplot(211)
plot(data_alpha, data_CM_bas);
grid on
xlabel('\alpha (deg)');
ylabel('CM-bas');
subplot(212)
plot(data_alpha,gradient(data_CM_bas,data_alpha)*180/pi);
grid on
xlabel('\alpha (deg)');
ylabel('CM-bas_\alpha');

data_CZ_con1 = squeeze(Aero.dC3_ele.data(4,14,3,:,2));  % alpha1, beta, stab, elev1, CZ
data_CZ_con2 = squeeze(Aero.dC3_ele.data(5,14,3,:,2));  % alpha2, beta, stab, elev2, CZ
data_elev = Aero.dC3_ele.elev;
figure(3);
subplot(211)
plot(data_elev,data_CZ_con1,data_elev,data_CZ_con2);
grid on
xlabel('\delta_e (deg)');
ylabel('CZ-con');
subplot(212)
plot(data_elev,gradient(data_CZ_con1,data_elev),...
    data_elev,gradient(data_CZ_con2,data_elev));
grid on
xlabel('\delta_e (deg)');
ylabel('CZ-con_{\delta_e}');


data_CM_con1 = squeeze(Aero.dC3_ele.data(4,14,3,:,3));  % alpha1, beta, stab, elev1, CM
data_CM_con2 = squeeze(Aero.dC3_ele.data(5,14,3,:,3));  % alpha2, beta, stab, elev2, CM
data_elev = Aero.dC3_ele.elev;
figure(4);
subplot(211)
plot(data_elev,data_CM_con1,data_elev,data_CM_con2);
grid on
xlabel('\delta_e (deg)');
ylabel('CM-con');
subplot(212)
plot(data_elev,gradient(data_CM_con1,data_elev),...
    data_elev,gradient(data_CM_con2,data_elev));
grid on
xlabel('\delta_e (deg)');
ylabel('CM-con_{\delta_e}');


data_CZ_dyn = Aero.dC3_q.data(:,8,2); % alpha, qhat, Z
data_alpha = Aero.dC3_q.alpha;
figure(5);
subplot(211)
plot(data_alpha, data_CZ_dyn);
grid on
xlabel('\alpha (deg)');
ylabel('CZ-q');
title('Aero.dC3_q');
subplot(212)
plot(data_alpha,gradient(data_CZ_dyn,data_alpha));
grid on
xlabel('\alpha (deg)');
ylabel('CZ-dyn_\alpha');
% 
% 
% data_CZ_dyn = Aero.dC3_p.data(:,8,2); % alpha, phat, Z
% data_alpha = Aero.dC3_p.alpha;
% figure(6);
% subplot(211)
% plot(data_alpha, data_CZ_dyn);
% grid on
% xlabel('\alpha (deg)');
% ylabel('CZ-q');
% title('Aero.dC3_p');
% subplot(212)
% plot(data_alpha,gradient(data_CZ_dyn,data_alpha));
% grid on
% xlabel('\alpha (deg)');
% ylabel('CZ-dyn_\alpha');
% 
% data_CZ_dyn = Aero.dC3_r.data(:,8,2); % alpha, rhat, Z
% data_alpha = Aero.dC3_r.alpha;
% figure(7);
% subplot(211)
% plot(data_alpha, data_CZ_dyn);
% grid on
% xlabel('\alpha (deg)');
% ylabel('CL-q');
% title('Aero.dC3_r');
% subplot(212)
% plot(data_alpha,gradient(data_CZ_dyn,data_alpha));
% grid on
% xlabel('\alpha (deg)');
% ylabel('CZ-dyn_\alpha');



% plot(Aero.dC3_q.alpha,squeeze(Aero.dC3_q.data(:,8,2)));

%% Estimate Parameters 

qbar0 = 19.04;  % psf
V0 = 128.08;    % ft/s
S = 5.91;       % ft^2
m = 1.54;       % slugs
Iy = 4.2540;    % slug-ft^2
Cbar = 0.9153;  % ft

% Za
CLa = 4.791; % fig 1
Za_est = - qbar0*S/(m*V0)*CLa; 

% Zq
CZq = 0.0004029; % fig 5,6,7
Zq_est = 1 - qbar0*S*CZq;  

% Zde
CZde = -8.34e-3; % fig 3
Zde_est = (qbar0*S)/(m*V0)*CZde;  

% Ma
CMa = -1.5623;  % fig 2
Ma_est = (qbar0*S*Cbar/Iy)*CMa;

% Mq
CMq = 0.0004029; % gtm_design_dbg
Mq_est = 1 - qbar0*S*CMq;  

% Mde
CMde = -0.0318; % fig 4
Mde_est = (qbar0*S*Cbar/Iy)*CMde;  


disp(' ');
disp('Parameters (actual vs estimate)');
disp(['Za: ' num2str([Za Za_est])]);
disp(['Zq (bad): ' num2str([Zq Zq_est])]);
disp(['Zde: ' num2str([Zde Zde_est])]);
disp(['Ma: ' num2str([Ma Ma_est])]);
disp(['Mq (bad): ' num2str([Mq Mq_est])]);
disp(['Mde: ' num2str([Mde Mde_est])]);




return

%%  Stuff not required now

load linmodel_fcase2_eas75

fcase2_sys = sys;
fcase2_londyn = londyn;
fcase2_latdyn = latdyn;

idx = [1 3 5 11 2 4 6 10];
a1 = fcase1_sys.a(idx,idx);
a2 = fcase2_sys.a(idx,idx);

norm(a1(1:4,5:8))
norm(a1(5:8,1:4))
norm(a2(1:4,5:8))
norm(a2(5:8,1:4))


% [wn_lon,z_lon]=damp(londyn);
% 
% % Just assuming frequency seperation here...
% phugoid_w_z     = [wn_lon(1),z_lon(1)];
% shortperiod_w_z = [wn_lon(3),z_lon(3)];
% 
% [wn_lat,z_lat]=damp(latdyn);
% 
% % Just assuming frequency seperation here...
% spiral_w_z      = [wn_lat(1),z_lat(1)];
% roll_w_z        = [wn_lat(2),z_lat(2)];
% dutchroll_w_z   = [wn_lat(3),z_lat(3)];


