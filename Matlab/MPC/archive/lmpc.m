%% Setup
clear

A = [0.5 0
    -1  1.5];
 
B = [0.5
     0.1];

NT = 10;
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

zr = zeros(2,1);
X = [zr zr zr
     B zr zr
    A*B B zr
    A^2*B A*B B];

BU_ = zeros(N*nx,N*nu);

cnt_j = 1;
for j = 1:nu:(N-1)*nu+1 % col
    cnt_i = 1;
    for i = 1:nx:(N-1)*nx+1 % row
        if cnt_j == cnt_i
            BU_(i:i+nx-1,j:j+nu-1) = B;
        elseif cnt_j < cnt_i
            pwr = cnt_i;
            disp([i j])
            BU_(i:i+nx-1,j:j+nu-1) = A^(N-1)*B;
        end

        cnt_i = cnt_i+1;
    end
    cnt_j = cnt_j + 1;
end


BU0 = zeros(nx,nu*N);
BU  = [BU0
       BU_];
         
BU = X;

%% Constraints

FX = Fx;
for i = 1:N
    FX = daug(FX, Fx);
end

gX = gx;
for i = 1:N
    gX = abv(gX, gx);
end

FU = [];
for i = 1:N
    FU = daug(FU, Fu);
end

gU = [];
for i = 1:N
    gU = abv(gU, gu);
end

QX = Q;
for i = 1:N
    QX = daug(QX, Q);
end

RU = [];
for i = 1:N
    RU = daug(RU, R);
end

%% QP

H = daug(QX,RU);
F = daug(FX,FU);
g = [gX; gU];

xk = x0;
uk = u0;

u = [];
for j = 1:NT

    Uk = [];
    for i = 1:N
        Uk = abv(Uk,uk);
    end
    Xk = AX*xk + BU*Uk;
    z0 = [Xk; Uk];
    
    n = length(z0);
    lb = -100*ones(n,1);
    ub = 100*ones(n,1);
    
    [Z,fval,exitflag] = fmincon(@(z) mpccost(z,H), z0, F, g, [], [], lb, ub);
    
    uk = Z((nx+1)*N+1);
    xk = Z(1:nx);
    
    u = [u; uk];
    
end


