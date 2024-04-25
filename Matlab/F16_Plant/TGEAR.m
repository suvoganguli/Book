function TGEAR_OUT = TGEAR(THTL)
% Power command v. thtl. relationship

% Author: Subhabrata Ganguli
%
% Ref: Stevens, Brian L.; Lewis, Frank L.; Johnson, Eric N.. 
% Aircraft Control and Simulation: Dynamics, 
% Controls Design, and Autonomous Systems. 
% Wiley.

if (THTL <= 0.77)
    TGEAR_OUT = 64.94*THTL;
else
    TGEAR_OUT = 217.38*THTL-117.38;
end

end

