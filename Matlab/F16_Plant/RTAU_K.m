function RTAU_OUT = RTAU_K(DP)
% function used by PDOT

% Author: Subhabrata Ganguli
%
% Ref: Stevens, Brian L.; Lewis, Frank L.; Johnson, Eric N.. 
% Aircraft Control and Simulation: Dynamics, 
% Controls Design, and Autonomous Systems. 
% Wiley.

if (DP < 25)
    RTAU_OUT = 1 + 0.01*DP;
elseif (DP > 50)
    RTAU_OUT = 0.1 + 0.01*DP;
else
    RTAU_OUT = 1.9 -.036 * DP;
end
