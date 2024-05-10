[A,B,C,D] = linmod('PI_openloop');

loop = ss(A,B,C,D);

figure(1); clf
margin(loop)

S = allmargin(loop)


setup_lead_controller

[A2,B2,C2,D2] = linmod('PI_lead_openloop');

loop2 = ss(A2,B2,C2,D2);

figure(2); clf
margin(loop2)
