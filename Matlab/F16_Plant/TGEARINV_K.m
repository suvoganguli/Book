function [THTL_OUT, sol] = TGEARINV_K(TGEAR_IN)
% Power command v. thtl. relationship

% Author: Subhabrata Ganguli
%
% Ref: Stevens, Brian L.; Lewis, Frank L.; Johnson, Eric N..
% Aircraft Control and Simulation: Dynamics,
% Controls Design, and Autonomous Systems.
% Wiley.

THTL_OUT = 0;

i = 0;
%figure(2); clf
sol = 0;
for THTL = 0:0.001:1
    if (THTL <= 0.77)
        TGEAR = 64.94*THTL;
    else
        TGEAR = 217.3816*THTL-117.38; % 217.3816
    end

    %plot(i,TGEAR,'b*',i,TGEAR_IN,'ro');
    %hold on

    if (abs(TGEAR - TGEAR_IN) < 0.5) && (TGEAR ~= 0) && (THTL ~=0)
        THTL_OUT = THTL;
        sol = 1;
        break
    end

    i = i+1;

end

end

