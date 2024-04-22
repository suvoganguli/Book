% MRAC

ft = 20;
dt = 0.001;

A = [0 1; 1 1];
B = [0; 1];
C = [1 0];
W = [1; 0]*1;
    
x = [0; 0];
y = C*x;

K1 = place(A, B, [-1 -2]);
K2 = -inv(C*inv(A-B*K1)*B);
Gamma = 30;
Am = A-B*K1;
Bm = B*K2;
P = lyap(Am',eye(2));

What = [0; 0];
xm = [0; 0];

index = 1;

for k = 0:dt:ft
    beta = [x(1)^2; x(1)*x(2)];

    if k < 10
        r = 1;
    elseif k >= 10
        r = -1;
    end

    u = -K1*x + K2*r - What'*beta;
    What = What + dt*Gamma*beta*(x-xm)'*P*B;
    xm = xm + dt*(Am*xm + Bm*r);

    x = x + dt*(A*x + B*(u+W'*beta));
    y = C*x;

    c_rec(index,1:1) = r;
    xm_rec(index,1:2) = xm;
    x_rec(index,1:2) = x;
    W_rec(index,1:2) = W;
    What_rec(index,1:2) = What;
    u_rec(index,1:1) = u;
    t_rec(index,1:1) = k;
    index = index + 1;

end

figure(1); clf;
subplot(311); hold on;
plot(t_rec,c_rec);
plot(t_rec,xm_rec(:,1));
plot(t_rec,x_rec(:,1),'--');

subplot(312); hold on;
plot(t_rec,xm_rec(:,2));
plot(t_rec,x_rec(:,2),'--');

subplot(313); hold on;
plot(t_rec,u_rec);




