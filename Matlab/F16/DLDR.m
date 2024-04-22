function DLDR_OUT  = DLDR(ALPHA,BETA) 
% rolling mom. due to rudder

% Author: Subhabrata Ganguli
%
% Ref: Stevens, Brian L.; Lewis, Frank L.; Johnson, Eric N.. 
% Aircraft Control and Simulation: Dynamics, 
% Controls Design, and Autonomous Systems. 
% Wiley.

A = [.005  .017  .014  .010  -.005  .009  .019  .005   .000  -.005  -.011  .008;
     .007  .016  .014  .014   .013  .009  .012  .005   .000   .004   .009  .007;
     .013  .013  .011  .012   .011  .009  .008  .005   .000   .005   .003  .005;
     .018  .015  .015  .014   .014  .014  .014  .015   .013   .011   .006  .001;
     .015  .014  .013  .013   .012  .011  .011  .010   .008   .008   .007  .003;
     .021  .011  .010  .011   .010  .009  .008  .010   .006   .005   .000  .001;
     .023  .010  .011  .011   .011  .010  .008  .010   .006   .014   .020  .000]';

S = 0.2 * ALPHA;
K = fix(S);
if (K <= -2)
    K = -1;
end
if (K >= 9) 
    K = 8;
end

DA = S - double(K);
L = K + fix( sign(DA)*1.1 );
S = 0.1 * BETA;

M = fix(S);
if (M == -3) 
    M = -2;
end
if (M >= 3) 
    M = 2;
end

DB = S - double(M);
N = M + fix( sign(DB)*1.11 );

IDX_SHIFT_ALPHA = 3;
IDX_SHIFT_BETA = 4;

T = A(K + IDX_SHIFT_ALPHA, M + IDX_SHIFT_BETA);
U = A(K + IDX_SHIFT_ALPHA, N + IDX_SHIFT_BETA);
V = T + abs(DA) * (A(L + IDX_SHIFT_ALPHA, M + IDX_SHIFT_BETA) - T);
W = U + abs(DA) * (A(L + IDX_SHIFT_ALPHA, N + IDX_SHIFT_BETA) - U);
DLDR_OUT  = V + (W-V) * abs(DB);

end