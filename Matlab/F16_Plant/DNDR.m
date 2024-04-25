function DNDR_OUT  = DNDR(ALPHA,BETA) 
% yawing mom. due to rudder

% Author: Subhabrata Ganguli
%
% Ref: Stevens, Brian L.; Lewis, Frank L.; Johnson, Eric N.. 
% Aircraft Control and Simulation: Dynamics, 
% Controls Design, and Autonomous Systems. 
% Wiley.

A = [-.018  -.052  -.052  -.052  -.054  -.049  -.059  -.051  -.030  -.037  -.026  -.013;
     -.028  -.051  -.043  -.046  -.045  -.049  -.057  -.052  -.030  -.033  -.030  -.008;
     -.037  -.041  -.038  -.040  -.040  -.038  -.037  -.030  -.027  -.024  -.019  -.013; 
     -.048  -.045  -.045  -.045  -.044  -.045  -.047  -.048  -.049  -.045  -.033  -.016;
     -.043  -.044  -.041  -.041  -.040  -.038  -.034  -.035  -.035  -.029  -.022  -.009;
     -.052  -.034  -.036  -.036  -.035  -.028  -.024  -.023  -.020  -.016  -.010  -.014;
     -.062  -.034  -.027  -.028  -.027  -.027  -.023  -.023  -.019  -.009  -.025  -.010]';

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
DNDR_OUT  = V + (W-V) * abs(DB);

end