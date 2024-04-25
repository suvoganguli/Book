% runsim_K_q.m

% Author: Subhabrata Ganguli

% setup
load F16lin.mat
load trimcond.mat

C_l = C_lon(4,:);
CB_l = C_l*B_lon(:,2);
invCB_l = inv(CB_l);
CA_l = C_l*A_lon;

Kq = 2;
fc = 1/2;
fi = 1/4;

C_nl = C(8,:);
CB_nl = C_nl*B(:,2);
invCB_nl = inv(CB_nl);
CA_nl = C_nl*A;

C_rate = C([7:9 13],:);

K_rate = 8*ones(4,1);
fc_rate = 1/2*ones(4,1);
fi_rate = 1/4*ones(4,1);

%% Simulation

return

sim('F16lin_K_q');
sim('F16nonlin_K_q');

%% Plots

figure(1); clf
subplot(211)
plot(t_l, r_l*180/pi, t_l, y_l*180/pi, ...
     t_nl, y_nl*180/pi,'--')
legend('Step Input',...
    'Linear Plant', 'Nonlinear Plant')
title('q (deg/sec) step response')
ylabel('q (deg/sec)')
grid on
subplot(212)
plot(t_l, u_l, ...
     t_nl, (u_nl-U_trim(2)),'--')
legend('Linear Plant', 'Nonlinear Plant')
title('de (deg) response')
ylabel('de (deg)')
xlabel('time (sec)')
grid on