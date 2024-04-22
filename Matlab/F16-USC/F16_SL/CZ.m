function CZ_OUT = CZ(ALPHA,BETA,EL) 
% z-axis force coeff.

% Author: Subhabrata Ganguli
%
% Ref: Stevens, Brian L.; Lewis, Frank L.; Johnson, Eric N.. 
% Aircraft Control and Simulation: Dynamics, 
% Controls Design, and Autonomous Systems. 
% Wiley.

A = [0.770  0.241  -0.100  -0.416  -0.731 ...
    -1.053  -1.366  -1.646  -1.917  -2.120 ...
    -2.248  -2.229]';

IDX_SHIFT = 3; % Fortran to Matlab

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
S = A(K + IDX_SHIFT) + abs(DA) * ...
    (A(L + IDX_SHIFT) - A(K + IDX_SHIFT));

CZ_OUT = S*(1-(BETA/57.3)^2) - .19*(EL/25.0);

end

