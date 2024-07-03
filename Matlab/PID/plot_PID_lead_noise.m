setup_lead_controller

sim('PID_lead_controllers_noise')

figure(1); clf
plot(y_PID.Time, y_PID.Data, 'b-');
hold on
plot(y_lead.Time, y_lead.Data,'r--');
xlabel('Time (sec)');
ylabel('Closed Loop Response')
legend('y\_PID','y\_lead')
grid on

figure(2); clf
plot(u_PID.Time, u_PID.Data, 'b-');
hold on
plot(u_lead.Time, u_lead.Data,'r--');
xlabel('Time (sec)');
ylabel('Controller Response')
legend('u\_PID','u\_lead')
grid on