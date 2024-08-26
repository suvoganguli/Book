num = 8;
den = [1 5 4 0];
P = tf(num,den);

figure(1)
margin(P)

phi = 20*pi/180;
alpha = (1-sin(phi))/(1+sin(phi));

w = 1.22;
T = 1/(w*sqrt(alpha));
z = 1/T;
p = 1/(alpha*T);
K = p/z;

z2 = 0.1;
p2 = 0.01;