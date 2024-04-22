clear

% Ad = [0 0; 0 1];
% Bd = [1; 0];
% Cd = [1 0];
% Dd = [0];
% 
% sysd = ss(Ad,Bd,Cd,Dd,0.1);
% 
% sys = d2c(sysd,'tutsin');
% sys2 = minreal(sys);
% [n,d] = ss2tf(sys2.A,sys2.B,sys2.C,sys2.D)

% [Ac,Bc,Cc,Dc] = tf2ss([0 10],[0 10]);
% sys = ss(Ac,Bc,Cc,Dc);
% sysd = c2d(sys,0.1,'zoh');
% A = sysd.A;
% B = sysd.B;

A = 0;
B = 10;
C = 1;
D = 0;
sysc = ss(A,B,C,D);
sysd = c2d(sysc,0.1);

% sys = tf(1,[1 0 0])

Q = 1;
R = 1;

A = sysd.A;
B = sysd.B;
C = sysd.C;
D = sysd.D;

Qt = idare(A,B,Q,R,[],[])