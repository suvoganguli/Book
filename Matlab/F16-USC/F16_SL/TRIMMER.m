function [X,U] = TRIMMER()

NV = 6;
NN = 13; %20;
MM = 4; %10;
S = zeros(6,1);
DS = zeros(6,1);
X = zeros(NN,1);
U = zeros(MM,1);

RTOD = 180/pi; 

S(1) = U(1);
S(2) = U(2);
S(3) = X(2);
S(4) = U(3);
S(5) = U(4);
S(6) = X(3);

DS(1) = 0.2;
DS(2) = 1.0;
DS(3) = 0.02;
DS(4) = 1.0;
DS(5) = 1.0;
DS(6) = 0.02;

NC = 1000;
SIGMA = -1.0;

[COST,FFIN] = SMPLX(NV,S,DS,SIGMA,NC);

print(COST);


end