function CN_OUT =  CN(ALPHA,BETA) 
% yawing moment coeff.

% Author: Subhabrata Ganguli
%
% Ref: Stevens, Brian L.; Lewis, Frank L.; Johnson, Eric N.. 
% Aircraft Control and Simulation: Dynamics, 
% Controls Design, and Autonomous Systems. 
% Wiley.

A = [.0    .0    .0    .0    .0    .0    .0    .0    .0     .0     .0     .0  ;
     .018  .019  .018  .019  .019  .018  .013  .007  .004  -.014  -.017  -.033;
     .038  .042  .042  .042  .043  .039  .030  .017  .004  -.035  -.047  -.057;
     .056  .057  .059  .058  .058  .053  .032  .012  .002  -.046  -.071  -.073;
     .064  .077  .076  .074  .073  .057  .029  .007  .012  -.034  -.065  -.041;
     .074  .086  .093  .089  .080  .062  .049  .022  .028  -.012  -.002  -.013;
     .079  .090  .106  .106  .096  .080  .068  .030  .064   .015   .011  -.001]';

S = 0.2 * ALPHA;
K = fix(S);
if (K <= -2) 
    K = -1;
end
if (K >= 9) 
    K = 8;
end

DA = S - double(K);
L = K + fix( sign(DA) * 1.1 );
S = .2* abs(BETA);
M = fix(S);

if(M == 0) 
    M= 1;
end
if(M >= 6) 
    M= 5;
end

DB = S - double(M);

IDX_SHIFT_ALPHA = 3;
IDX_SHIFT_BETA = 1;

N = M + fix( sign(DB) * 1.1 );
T = A(K + IDX_SHIFT_ALPHA, M + IDX_SHIFT_BETA);
U = A(K + IDX_SHIFT_ALPHA, N + IDX_SHIFT_BETA);
V = T + abs(DA) * (A(L + IDX_SHIFT_ALPHA, M + IDX_SHIFT_BETA) - T);
W = U + abs(DA) * (A(L + IDX_SHIFT_ALPHA, N + IDX_SHIFT_BETA) - U);
DUM = V + (W-V) * abs(DB);

CN_OUT = DUM * sign(BETA) * 1.0;

end


