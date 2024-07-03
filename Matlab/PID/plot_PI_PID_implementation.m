sim('PID_controller_implementation')

figure(1); clf
plot(y_PID1.Time, y_PID1.Data, 'b-');
hold on
plot(y_PID2.Time, y_PID2.Data,'r--');
xlabel('Time (sec)');
ylabel('Closed Loop Response')
legend('\alpha_D=1','\alpha_D=0')
grid on

[A,B,C,D] = linmod('PID_controller_implementation_RHZ');
sys = ss(A,B,C,D);
% Find the transmission zeros
zeros = tzero(sys);

% Display the zeros
disp('The zeros of the transfer function are:');
rifd(zeros);


