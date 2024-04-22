A = [1 0.05
     0 1];
 
B = [0
    0.05];

Q = eye(2);
R = 1;

E = eye(2);
S = zeros(2,1);

[X,K,L] = idare(A,B,Q,R,S,E);