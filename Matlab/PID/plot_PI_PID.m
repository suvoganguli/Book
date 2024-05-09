sim('PI_PID_controllers')

figure(1); clf
plot(y_PI.Time, y_PI.Data, 'b-');
hold on
plot(y_PID.Time, y_PID.Data,'r--');
xlabel('Time (sec)');
ylabel('Closed Loop Response')
legend('y\_PI','y\_PID')
grid on
