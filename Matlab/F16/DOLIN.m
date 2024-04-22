% DOLIN.m

% Author: Subhabrata Ganguli
%
% Ref: Stevens, Brian L.; Lewis, Frank L.; Johnson, Eric N.. 
% Aircraft Control and Simulation: Dynamics, 
% Controls Design, and Autonomous Systems. 
% Wiley.

%% Linmod

load trimcond.mat

[A,B,C,D] = linmod('F16sim_lin',X_trim,U_trim);

% 1 - V
% 2 - alpha
% 3 - beta
% 4 - phi
% 5 - theta
% 6 - psi
% 7 - p
% 8 - q
% 9 - r
% 10 - Xe
% 11 - Ye
% 12 - h

%% Longitudinal

idx_lon = [1 2 5 8 10 12 13];

A_lon = A(idx_lon,idx_lon);
B_lon = B(idx_lon,[1 2]);
C_lon = C(idx_lon,idx_lon);
D_lon = D(idx_lon,[1 2]);

sys_lon = ss(A_lon,B_lon,C_lon,D_lon);

disp('Longitudinal Poles');
rifd(eig(A_lon));

%% Lateral

idx_lat = [3 4 6 7 9 11];

A_lat = A(idx_lat,idx_lat);
B_lat = B(idx_lat,[3 4]);
C_lat = C(idx_lat,idx_lat);
D_lat = D(idx_lat,[3 4]);

sys_lat = ss(A_lat,B_lat,C_lat,D_lat);

disp(' ')
disp('Lateral Poles');
rifd(eig(A_lat));

save F16lin.mat A B C D A_lon B_lon C_lon D_lon ...
    A_lat B_lat C_lat D_lat;


%% Step responses - longitudinal

% throttle
t = 0:0.01:1;
n = length(t);
u = [ones(n,1)*0.1 zeros(n,1)];
[Y,T] = lsim(sys_lon, u, t);

figure(1);
subplot(211);
plot(T,Y(:,1))
ylabel('V (ft/sec)')
subplot(212);
plot(T,Y(:,2)*180/pi)
ylabel('alpha (deg)')
xlabel('time (sec)')

figure(2);
subplot(311);
plot(T,Y(:,3)*180/pi)
ylabel('theta (deg)')
subplot(312);
plot(T,Y(:,4)*180/pi)
ylabel('q (deg/sec)')
subplot(313);
plot(T,Y(:,7))
ylabel('power (ft-lb/sec)')
xlabel('time (sec)')

% elevator
t = 0:0.01:1;
n = length(t);
u = [zeros(n,1) ones(n,1)*pi/180];
[Y,T] = lsim(sys_lon, u, t);

figure(3);
subplot(211);
plot(T,Y(:,1))
ylabel('V (ft/sec)')
subplot(212);
plot(T,Y(:,2)*180/pi)
ylabel('alpha (deg)')
xlabel('time (sec)')

figure(4);
subplot(311);
plot(T,Y(:,3)*180/pi)
ylabel('theta (deg)')
subplot(312);
plot(T,Y(:,4)*180/pi)
ylabel('q (deg/sec)')
subplot(313);
plot(T,Y(:,7))
ylabel('power (ft-lb/sec)')
xlabel('time (sec)')

%% Step responses - lateral

% aileron
t = 0:0.01:1;
n = length(t);
u = [ones(n,1)*pi/180 zeros(n,1)];
[Y,T] = lsim(sys_lat, u, t);

figure(5);
subplot(211);
plot(T,Y(:,1)*180/pi)
ylabel('beta (deg)')
subplot(212);
plot(T,Y(:,2)*180/pi)
ylabel('phi (deg)')
xlabel('time (sec)')

figure(6);
subplot(311);
plot(T,Y(:,3)*180/pi)
ylabel('psi (deg)')
subplot(312);
plot(T,Y(:,4)*180/pi)
ylabel('p (deg/sec)')
subplot(313);
plot(T,Y(:,5)*180/pi)
ylabel('r (deg/sec)')
xlabel('time (sec)')

% rudder
t = 0:0.01:1;
n = length(t);
u = [zeros(n,1) ones(n,1)*pi/180];
[Y,T] = lsim(sys_lon, u, t);

figure(7);
subplot(211);
plot(T,Y(:,1)*180/pi)
ylabel('beta (deg)')
subplot(212);
plot(T,Y(:,2)*180/pi)
ylabel('phi (deg)')
xlabel('time (sec)')

figure(8);
subplot(311);
plot(T,Y(:,3)*180/pi)
ylabel('psi (deg)')
subplot(312);
plot(T,Y(:,4)*180/pi)
ylabel('p (deg/sec)')
subplot(313);
plot(T,Y(:,5)*180/pi)
ylabel('r (deg/sec)')
xlabel('time (sec)')