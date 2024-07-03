clear
close all

opt = 2;
switch opt
    case 1
        [Ac,Bc,Cc,Dc] = tf2ss(1,[1 0 0]);
        sys = ss(Ac,Bc,Cc,Dc);
        sysd = c2d(sys,0.1,'zoh');
        Ap = sysd.A;
        Bp = sysd.B;
        Cp = sysd.C;
        Dp = sysd.D;
    case 2
        Ap = [0.9 0.2;-0.4 0.8]/2;
        Bp = [0.1;0.01]*2;
        Cp = [1 0];
        
end

Nc = 10;
Np = 20;
Nt = 60;

R = 1*eye(Nc);

[Phi_Phi, Phi_F, Phi_R, Phi, F, Phix, Fx, Aa, Ba, Ca] = ...
    mpcgain(Ap, Bp, Cp, Nc, Np);

nx = size(Ap,1);
x_k = [0.1 0.2 0.1]';
x = x_k;
y = x_k(nx);
xm = x_k(1:nx);
u = 0;

for k = 1:Nt
    DU = (Phi_Phi+R)\(Phi_R - Phi_F*x_k);
    du = DU(1);
    
    if k == 1
        u(k,1) = du;
    else
        u(k,1) = u(k-1,1) + du;
    end
    
    xm(:,k+1) = Ap*xm(:,k) + Bp*u(k,1);
    dxm(:,k+1) = xm(:,k+1) - xm(:,k);
    y(:,k+1) = Cp*xm(:,k+1);
    
    x(:,k+1) = [dxm(:,k+1); y(:,k+1)]; 
    x_k = x(:,k+1);

end

figure(1); clf
subplot(211)
plot(1:Nt,y(1:Nt));
%xlim([1 Nt])
ylabel('y');
subplot(212);
plot(1:Nt,xm(:,1:Nt))
%xlim([1 Nt])
ylabel('xm');
legend('xm(1)','xm(2)');
xlabel('Sample No.');

figure(2); clf
plot(1:Nt,u(1:Nt));
ylabel('u');
xlabel('Sample No.');


