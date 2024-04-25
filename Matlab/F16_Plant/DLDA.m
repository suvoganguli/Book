function DLDA_OUT  = DLDA(ALPHA,BETA) 
% rolling mom. due to ailerons

% Author: Subhabrata Ganguli
%
% Ref: Stevens, Brian L.; Lewis, Frank L.; Johnson, Eric N.. 
% Aircraft Control and Simulation: Dynamics, 
% Controls Design, and Autonomous Systems. 
% Wiley.

A  = [-.041  -.052  -.053  -.056  -.050  -.056  -.082  -.059  -.042  -.038  -.027  -.017;
     -.041  -.053  -.053  -.053  -.050  -.051  -.066  -.043  -.038  -.027  -.023  -.016;
     -.042  -.053  -.052  -.051  -.049  -.049  -.043  -.035  -.026  -.016  -.018  -.014;
     -.040  -.052  -.051  -.052  -.048  -.048  -.042  -.037  -.031  -.026  -.017  -.012;
     -.043  -.049  -.048  -.049  -.043  -.042  -.042  -.036  -.025  -.021  -.016  -.011;
     -.044  -.048  -.048  -.047  -.042  -.041  -.020  -.028  -.013  -.014  -.011  -.010;
     -.043  -.049  -.047  -.045  -.042  -.037  -.003  -.013  -.010  -.003  -.007  -.008]';

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
DLDA_OUT  = V + (W-V) * abs(DB);

end