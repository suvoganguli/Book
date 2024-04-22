%% Setup
clear
% close all

opt = 3;

switch opt
    case 1
        [Ac,Bc,Cc,Dc] = tf2ss(1,[1 0 0]);
        sys = ss(Ac,Bc,Cc,Dc);
        sysd = c2d(sys,0.1,'zoh');
        A = sysd.A;
        B = sysd.B;
    case 2
        A=[0.9 0.2;-0.4 0.8];
        B=[0.1;0.01];
    case 3
        Ad = [1 0; 0 0.1];
        Bd = [1; 1];
        Cd = eye(2);
        Dd = [0; 0];
        sysd = ss(Ad,Bd,Cd,Dd,0.1);
        sysc = d2c(sysd,'zoh');
        A = sysd.A;
        B = sysd.B;
end
  
nx = size(A,1);
nu = size(B,2);

Np = 25;
Nc = 15;
Nt = 50;

Q = [1 0;
     0 1]*100;
R = 1;

Qt = idare(A,B,Q,R,[],[]);

x0 = [0
      0];

u0 = 0;
xr = [1
      0.5];
   
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
 
gu = [4
      4] - Fu*ur;


%% A & B

AX = eye(nx);
for i = 1:Nc
    AX = [AX
          A^i];
end

for i=1:Nc+1 % row
  for j=1:Nc % col
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

for i = 1:Nc
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

Feq = [eye((Nc+1)*nx) -BU];
geq = AX*xk;

Xk=zeros(nx*(Nc+1),1); 
Xk(1:nx,1)=x0;
Uk=zeros(nu*Nc,1);
Uk(1) = u0 - pinv(B) * (eye(nx) - A) * xr;
z=[Xk;Uk];
zk = z;

u_sol = [];
x_sol = [];
x_sol(:,1) = x0 - xr;
fval_sol = [];
xt_sol = [];

options = optimoptions('fmincon','Display', 'off', ...
                        'MaxIterations',1e4, ...
                        'MaxFunctionEvaluations',1e4, ...
                        'ConstraintTolerance',1e-6);

lb = []; ub = [];

for j = 1:Nt
            
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
    
    uk = z((Nc+1)*nx+1:(Nc+1)*nx+nu);
        
    xkp1 = A*xk + B*uk;
    
    xk = xkp1;
    
    geq=AX*xk;
       
    u_sol = [u_sol uk];
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
plot(1:(Nt+1),xr_sol(1,:),'.-',1:Nt+1,xr_sol(2,:),'.-')
grid on
% ylim([-10 10])
xlim([0 Nt])
ylabel('x')
legend('x_1','x_2')
subplot(212)
hold on
stairs(1:Nt,ur_sol,'.-');
grid on
% ylim([-1 1])
xlim([0 Nt])
ylabel('u');
xlabel('Sample time');

figure(2)
hold on
plot(x_sol(1,:),x_sol(2,:));
ylabel('x_2');
xlabel('x_1');

figure(3)
hold on
plot(1:Nt,fval_sol);
xlabel('Sample Time');
ylabel('fval');
grid on

