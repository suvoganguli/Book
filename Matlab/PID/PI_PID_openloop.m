[A,B,C,D] = linmod('PI_openloop');

syscl = ss(A,B,C,D);

[A2,B2,C2,D2] = linmod('PID_openloop');

syscl2 = ss(A2,B2,C2,D2);

figure(1); clf
bode(syscl, syscl2)
grid on