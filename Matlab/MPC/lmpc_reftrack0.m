%% Setup
clear
close all

[Ac,Bc,Cc,Dc] = tf2ss(1,[1 0 0]);
sys = ss(Ac,Bc,Cc,Dc);
sysd = c2d(sys,0.1,'zoh');

opt = 2;

switch opt
    case 1
        A = sysd.A;
        B = sysd.B;
    case 2
        A=[0.9 0.2;-0.4 0.8];
        B=[0.1;0.01];
end
  
nx = size(A,1);
nu = size(B,2);

% Nc = 10;
% Np = 20;
NT = 50;
N = 5;

Q = eye(2);
R = 1;

Qt = idare(A,B,Q,R,[],[]);

x0 = [10
      5];

u0 = -1;
xr = [3
      2];
   
ur = pinv(B) * (eye(nx) - A) * xr;

Fx = [1 0
      0 1
     -1 0
      0 -1];
  
gx = [10
      10
      10
      10] - Fx*xr;
 
Fu = [1
     -1];
 
gu = [1
      1] - Fu*ur;


%% A & B

AX = eye(nx);
for i = 1:N
    AX = [AX
          A^i];
end

for i=1:N+1 % row
  for j=1:N % col
      idx_i = (i-1)*nx+1:i*nx;
      idx_j = (j-1)*nu+1:j*nu;
      if i>j
          BU(idx_i,idx_j)=A^(i-j-1)*B;
      else
          BU(idx_i,idx_j)=zeros(nx,nu);
      end    
  end
end

%% Constraints

FX = Fx;
gX = gx;
FU = [];
gU = [];
QX = Q;
RU = [];

for i = 1:N
    FX = blkdiag(FX, Fx);
    gX = abv(gX, gx);
    FU = blkdiag(FU, Fu);
    gU = abv(gU, gu);
    QX = blkdiag(QX, Q);
    RU = blkdiag(RU, R);
end


%% QP

H = blkdiag(QX,RU);
F = blkdiag(FX,FU);
g = [gX; gU];

xk = x0 - xr;
uk = u0 - pinv(B) * (eye(nx) - A) * xr;

Feq = [eye((N+1)*nx) -BU];
geq = AX*xk;

Xk=zeros(nx*(N+1),1); 
Xk(1:nx,1)=x0;
Uk=zeros(nu*N,1);
Uk(1) = u0 - pinv(B) * (eye(nx) - A) * xr;
z=[Xk;Uk];
zk = z;

u_sol = [];
x_sol = [];
x_sol(:,1) = x0 - xr;
fval_sol = [];
xt_sol = [];

options = optimoptions('fmincon','Display', 'off', ...
                        'MaxIterations',1000, ...
                        'ConstraintTolerance',1e-6);

lb = []; ub = [];

for j = 1:NT
        
    u_sol = [u_sol uk];
    
    z0 = z;
    
    n = length(z0);
    
    xt = Xk(end-nx+1:end);
        
    xt_sol = [xt_sol sum(xt)];
    mpc_cost = @(z) z'*H*z + xt'*Qt*xt;
    
    [z,fval,exitflag] = fmincon(@(z) mpc_cost(z), z0, F, g, Feq, geq, lb, ub, [], options);
    if exitflag ~= 1
        disp([j exitflag])
    end
    
    zk(:,j+1) = z;
    
    uk = z((N+1)*nx+1:(N+1)*nx+nu);
        
    xkp1 = A*xk + B*uk;
    
    xk = xkp1;
    
    geq=AX*xk;
       
    x_sol = [x_sol xk];
    fval_sol = [fval_sol fval];

    % if j >= 6
    %     keyboard
    % end
    
end

xr_sol = x_sol + xr;
ur_sol = u_sol + pinv(B) * (eye(nx) - A) * xr;

figure(1)
subplot(211)
hold on
plot(1:(NT+1),xr_sol(1,:),1:NT+1,xr_sol(2,:),'.-')
grid on
ylim([-10 10])
ylabel('x')
legend('x_1','x_2')
subplot(212)
hold on
stairs(1:NT,ur_sol,'.-');
grid on
ylim([-1 1])
ylabel('u');
xlabel('Sample time');

figure(2)
hold on
plot(x_sol(1,:),x_sol(2,:));
ylabel('x_2');
xlabel('x_1');

figure(3)
hold on
plot(1:NT,fval_sol);
xlabel('Sample Time');
ylabel('fval');
grid on

