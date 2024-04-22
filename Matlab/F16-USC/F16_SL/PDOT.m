function PDOT_OUT = PDOT(P3,P1)
% PDOT_OUT = rate of change of power

% Author: Subhabrata Ganguli
%
% Ref: Stevens, Brian L.; Lewis, Frank L.; Johnson, Eric N.. 
% Aircraft Control and Simulation: Dynamics, 
% Controls Design, and Autonomous Systems. 
% Wiley.

% P3 = actual power
% P1 = power command

if (P1 >= 50)
    if (P3 >= 50)
        T = 5;
        P2 = P1;
    else
        P2 = 60;
        T = RTAU(P2-P3);
    end
else
    if (P3 >= 50)
        T = 5;
        P2 = 40;
    else
        P2 = P1;
        T = RTAU(P2-P3);
    end
end

PDOT_OUT = T*(P2-P3);

end