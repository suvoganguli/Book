setup_lead_controller

[A,B,C,D] = linmod('PID_lead_controllers_linmod1');
sys = ss(A,B,C,D);

[A1,B1,C1,D1] = linmod('PID_lead_controllers_linmod2');
sys1 = ss(A1,B1,C1,D1);

p = bodeoptions;
p.MagUnits = 'abs';
p.XLimMode = {'manual'}
p.XLim = [0.1 10];
figure(1); clf
h = bodeplot(sys,sys1,p)
grid on


