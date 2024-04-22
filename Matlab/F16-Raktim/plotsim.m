% plotsim

Vt = out.logsout{1}.Values.Data;
alpha = out.logsout{2}.Values.Data;
beta = out.logsout{3}.Values.Data;
gamma = out.logsout{4}.Values.Data;
omega = out.logsout{5}.Values.Data;
phi_tht_psi = out.logsout{6}.Values.Data;

figure(1);
subplot(411)
plot(tout,Vt);
ylabel('Vt (ft/sec)')
subplot(412)
plot(tout,alpha*180/pi);
ylabel('alpha (deg)')
subplot(413)
plot(tout,beta*180/pi);
ylabel('beta (deg)')
subplot(414)
plot(tout,gamma*180/pi);
ylabel('gamma (deg)')
xlabel('time (sec)')

figure(2);
subplot(311)
plot(tout,omega(:,1)*180/pi);
ylabel('p (deg/sec)')
subplot(312)
plot(tout,omega(:,2)*180/pi);
ylabel('q (deg/sec)')
subplot(313)
plot(tout,omega(:,3)*180/pi);
ylabel('r (deg/sec)')
xlabel('time (sec)')

figure(3);
subplot(311)
plot(tout,phi_tht_psi(:,1)*180/pi);
ylabel('phi (deg)')
subplot(312)
plot(tout,phi_tht_psi(:,2)*180/pi);
ylabel('theta (deg)')
subplot(313)
plot(tout,phi_tht_psi(:,3)*180/pi);
ylabel('psi (deg)')
xlabel('time (sec)')

