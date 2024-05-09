% zeiglar nicholes

Kp = 0.96;
Ki = 0;
Kd = 0;

t_end = 100;
sim('sys_zn1')

figure(1); clf
plot(r.Time,r.Data,'r--', ...
    y.Time, y.Data, 'b-')

Ku = Kp;
Tu = 4.5;
Ti = Tu/2;
Td = Tu/8;

Kp = 0.6*Ku;
Ki = Kp/Ti;
Kd = Kp*Td;

t_end = 30;
sim('sys_zn1')
figure(1); clf
plot(r.Time,r.Data,'r--', ...
    y.Time, y.Data, 'b-')

return

Kp = 0.4; % 0.576
Ki = 0.3; % 0.252;
Kd = 1; % 0.324

t_end = 20;
sim('sys_zn1')
figure(1); clf
plot(r.Time,r.Data,'r--', ...
    y.Time, y.Data, 'b-')

