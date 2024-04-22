function CY_OUT = CY(BETA,AIL,RDR) 
% sideforce coefficient

% Author: Subhabrata Ganguli
%
% Ref: Stevens, Brian L.; Lewis, Frank L.; Johnson, Eric N.. 
% Aircraft Control and Simulation: Dynamics, 
% Controls Design, and Autonomous Systems. 
% Wiley.

CY_OUT = -.02*BETA + .021*(AIL/20.0) + .086*(RDR/30.0);

end


