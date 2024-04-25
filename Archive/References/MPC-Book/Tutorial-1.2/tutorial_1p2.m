clear
close all

Ap = 0.8;
Bp = 0.1;
Cp = 1;
Nc = 4;
Np = 10;
Nt = 30;

rw = 0;
R = rw*eye(Nc);

[Phi_Phi, Phi_F, Phi_R, Phi, F, Phix, Fx, A_e, B_e, C_e] = ...
    mpcgain(Ap, Bp, Cp, Nc, Np);

x = zeros(Nt,1);
y = zeros(Nt,1);
x_k = [0.1 0.2]';
x(1,1) = x_k(1);
y(1,1) = x_k(2);
for k = 2:Nt
    DU = (Phi_Phi+R)\(Phi_R - Phi_F*x_k);
    Y = F*x_k + Phi*DU;
    X = Fx*x_k + Phix*DU;
    y(k,1) = Y(1);
    x(k,1) = X(1);
    x_k = [X(1); Y(1)];
end

figure(1); clf
plot(1:Nt,x,1:Nt,y);
xlim([1 Nt])
legend('x','y');
ylabel('State, Output');
xlabel('Sample No.');




