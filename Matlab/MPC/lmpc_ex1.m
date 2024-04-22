%% Setup
clear
close all

A=[0.9 0.2;-0.4 0.8];
B=[0.1;0.01];

NT = 50;
N = 3;

Q = eye(2);
R = 1;

x0 = [10
       5];
   
u0 = -1;

Fx = [1 0
      0 1
     -1 0
      0 -1];
  
gx = [10
      10
      10
      10];
 
Fu = [1
     -1];
 
gu = [1
      1];
  
nx = size(A,1);
nu = size(B,2);

%% A & B

AX = eye(2,2);
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

xk = x0;
uk = u0;

Feq = [eye((N+1)*nx) -BU];
geq = AX*xk;

Xk=zeros(nx*(N+1),1); 
Xk(1:nx,1)=x0;
Uk=zeros(nu*N,1);
z=[Xk;Uk];

u_sol = [];
x_sol = [];
x_sol(:,1) = x0;

for j = 1:NT
    
    z0 = z;
    
    n = length(z0);
    lb = -10*ones(n,1);
    ub = 10*ones(n,1);
    
    mpc_cost = @(z) z'*H*z;
    
    [z,fval,exitflag] = fmincon(@(z) mpc_cost(z), z0, F, g, Feq, geq, lb, ub);
    %[z,fval,exitflag] = fmincon(@(z) mpc_cost(z), z0);
    
    uk = z((nx+1)*N+1:(nx+1)*N+nu);
    %uk = z(N*nx+1);
    
    xkp1 = A*xk + B*uk;
    
    xk = xkp1;
    
    geq=AX*xk;
    
    u_sol(:,j) = uk;
    x_sol(:,j+1) = xkp1;
    
end

figure(1)
subplot(211)
plot(1:(NT+1),x_sol(1,:),1:NT+1,x_sol(2,:))
grid on
xlim([1 NT])
ylabel('x')
legend('x_1','x_2')
subplot(212)
stairs(1:NT,u_sol);
grid on
xlim([1 NT])
ylabel('u');
xlabel('Sample time');

