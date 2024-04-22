function CL_OUT =  CL(ALPHA,BETA) 
% rolling moment coeff.

% Author: Subhabrata Ganguli
%
% Ref: Stevens, Brian L.; Lewis, Frank L.; Johnson, Eric N.. 
% Aircraft Control and Simulation: Dynamics, 
% Controls Design, and Autonomous Systems. 
% Wiley.

A = [.0     .0     .0     .0     .0     .0     .0     .0     .0     .0     .0     .0  ;
    -.001  -.004  -.008  -.012  -.016  -.022  -.022  -.021  -.015  -.008  -.013  -.015;
    -.003  -.009  -.017  -.024  -.030  -.041  -.045  -.040  -.016  -.002  -.010  -.019;
    -.001  -.010  -.020  -.030  -.039  -.054  -.057  -.054  -.023  -.006  -.014  -.027;
     .000  -.010  -.022  -.034  -.047  -.060  -.069  -.067  -.033  -.036  -.035  -.035;
     .007  -.010  -.023  -.034  -.049  -.063  -.081  -.079  -.060  -.058  -.062  -.059;
     .009  -.011  -.023  -.037  -.050  -.068  -.089  -.088  -.091  -.076  -.077  -.076]';

S = 0.2 * ALPHA;
K = fix(S);
if(K <= -2) 
    K= -1;
end
if(K >= 9) 
    K= 8;
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

CL_OUT = DUM * sign(BETA) * 1.0;

end


