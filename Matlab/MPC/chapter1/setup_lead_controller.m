% setup_lead_controller

% Design Phase Margin
phi = 60*pi/180;

alpha = (1-sin(phi))/(1+sin(phi));
w = 1/sqrt(T)/sqrt(alpha*T);

disp(1/sqrt(T))
disp(sqrt(alpha*T))
disp(w)
