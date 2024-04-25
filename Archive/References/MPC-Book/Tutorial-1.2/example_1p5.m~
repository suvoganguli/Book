clear
close all

Ap = 0.8;
Bp = 0.1;
Cp = 1;
Nc = 4;
Np = 10;
Nt = 10;

rw = 0;
R = rw*eye(Nc);

[Phi_Phi, Phi_F, Phi_R, Phi, F, Phi2, F2, A_e, B_e, C_e] = ...
    mpcgain(Ap, Bp, Cp, Nc, Np);

r = 1;
BarRs = ones(1,Nt)*r;
Phi_R = Phi_R*r;

nx = size(Ap,1);
no = size(Cp,1);

x_k = [0.1 0.2]';
x(1,1) = x_k(1);
y(1,1) = x_k(2);
xm(1,1) = x_k(2);
u(1,1) = 0;
x = x_k;

for k = 1:Nt
    DU = (Phi_Phi+R)\(Phi_R - Phi_F*x_k);
    du = DU(1);
    
    if k == 1
        u(:,k) = du;
    else
        u(:,k) = u(:,k-1) + du;
    end
    
    xm(:,k+1) = Ap*xm(:,k) + Bp*u(k);
    dxm(:,k+1) = xm(:,k+1) - xm(:,k);
    y(:,k+1) = xm(:,k+1);
    
    x(:,k+1) = [dxm(:,k+1); y(:,k+1)]; 
    x_k = x(:,k+1);

end

figure(1); clf
plot(1:Nt,xm(1:Nt));
xlim([1 Nt])
legend('x','y');
ylabel('State, Output');
xlabel('Sample No.');




