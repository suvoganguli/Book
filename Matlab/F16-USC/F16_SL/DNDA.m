function DNDA_OUT  = DNDA(ALPHA,BETA) 
% yawing mom. due to ailerons

% Author: Subhabrata Ganguli
%
% Ref: Stevens, Brian L.; Lewis, Frank L.; Johnson, Eric N.. 
% Aircraft Control and Simulation: Dynamics, 
% Controls Design, and Autonomous Systems. 
% Wiley.

A = [.001  -.027  -.017  -.013  -.012  -.016   .001   .017   .011  .017   .008  .016
     .002  -.014  -.016  -.016  -.014  -.019  -.021   .002   .012  .016   .015  .011
    -.006  -.008  -.006  -.006  -.005  -.008  -.005   .007   .004  .007   .006  .006
    -.011  -.011  -.010  -.009  -.008  -.006   .000   .004   .007  .010   .004  .010
    -.015  -.015  -.014  -.012  -.011  -.008  -.002   .002   .006  .012   .011  .011
    -.024  -.010  -.004  -.002  -.001   .003   .014   .006  -.001  .004   .004  .006
    -.022   .002  -.003  -.005  -.003  -.001  -.009  -.009  -.001  .003  -.002  .001]';

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
DNDA_OUT  = V + (W-V) * abs(DB);

end