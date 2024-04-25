function CX_OUT = CX(ALPHA,EL)
% x-axis aerodynamic force coeff.

% Author: Subhabrata Ganguli
%
% Ref: Stevens, Brian L.; Lewis, Frank L.; Johnson, Eric N.. 
% Aircraft Control and Simulation: Dynamics, 
% Controls Design, and Autonomous Systems. 
% Wiley.

A = [-0.099  -0.081  -0.081  -0.063  -0.025  0.044  0.097  0.113  0.145  0.167  0.174  0.166;
     -0.048  -0.038  -0.040  -0.021   0.016  0.083  0.127  0.137  0.162  0.177  0.179  0.167;
     -0.022  -0.020  -0.021  -0.004   0.032  0.094  0.128  0.130  0.154  0.161  0.155  0.138;
     -0.040  -0.038  -0.039  -0.025   0.006  0.062  0.087  0.085  0.100  0.110  0.104  0.091;
     -0.083  -0.073  -0.076  -0.072  -0.046  0.012  0.024  0.025  0.043  0.053  0.047  0.040]';

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

CX_OUT = V + (W-V) * abs(DE);

end
