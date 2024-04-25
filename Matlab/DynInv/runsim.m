clear
close all

%% Plant dynamics

A = -2;
B = 3;
C = 1;
D = 0;

%% Controller

K = 4;
fc = 1/2;
fi = 1/4;

invCB = inv(C*B);
CA = C*A;


