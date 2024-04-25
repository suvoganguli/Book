function CM_OUT = CM(ALPHA,EL) 
% pitching moment coeff.

% Author: Subhabrata Ganguli
%
% Ref: Stevens, Brian L.; Lewis, Frank L.; Johnson, Eric N.. 
% Aircraft Control and Simulation: Dynamics, 
% Controls Design, and Autonomous Systems. 
% Wiley.

A = [.205   .168   .186   .196   .213   .251   .245   .238   .252   .231   .198   .192;
     .081   .077   .107   .110   .110   .141   .127   .119   .133   .108   .081   .093;
    -.046  -.020  -.009  -.005  -.006   .010   .006  -.001   .014   .000  -.013   .032;
    -.174  -.145  -.121  -.127  -.129  -.102  -.097  -.113  -.087  -.084  -.069  -.006;
    -.259  -.202  -.184  -.193  -.199  -.150  -.160  -.167  -.104  -.076  -.041  -.005]';

S = 0.2 * ALPHA;
K = fix(S);
if (K <= -2) 
    K = -1;
end
if(K >= 9) 
    K = 8;
end

DA = S - double(K);
L = K + fix( sign(DA) * 1.1 );
S = EL/12.0;
M = fix(S);

if(M <= -2) 
    M = -1;
end
if(M >= 2) 
    M = 1;
end
DE = S - double(M);
N = M + fix( sign(DE) * 1.1 );

IDX_SHIFT_ALPHA = 3; % Fortran to Matlab
IDX_SHIFT_EL = 3; % Fortran to Matlab

T = A(K + IDX_SHIFT_ALPHA, M + IDX_SHIFT_EL);
U = A(K + IDX_SHIFT_ALPHA, N + IDX_SHIFT_EL);
V = T + abs(DA) * (A(L + IDX_SHIFT_ALPHA, M + IDX_SHIFT_EL) - T);
W = U + abs(DA) * (A(L + IDX_SHIFT_ALPHA, N + IDX_SHIFT_EL) - U);

CM_OUT = V + (W-V) * abs(DE);

end
