function [P1_OUT] = PDOTINV(P3,PDOT_IN)
% PDOT_OUT = rate of change of power

% Author: Subhabrata Ganguli
%
% Ref: Stevens, Brian L.; Lewis, Frank L.; Johnson, Eric N..
% Aircraft Control and Simulation: Dynamics,
% Controls Design, and Autonomous Systems.
% Wiley.

% P3 = actual power
% P1 = power command
if isempty(P3)
    disp('empty')
end
ctr = 1;
k = 1;
P1_OUT_vec = 100*ones(100,1);

for P1 = 0:0.01:100
    if (P1 >= 50)
        if (P3 >= 50)
            T = 5;
            P2 = P1;
        else
            P2 = 60 + 0.1*P1;
            T = RTAU(P2-P3);
        end
    else
        if (P3 >= 50)
            T = 5;
            P2 = 40 + 0.1*P1;
        else
            P2 = P1;
            T = RTAU(P2-P3);
        end
    end

    PDOT_OUT = T*(P2-P3);

    if abs(PDOT_OUT - PDOT_IN) < 1e-6
        P1_OUT_vec(k) = P1;
        k = k+1;
    elseif abs(PDOT_OUT - PDOT_IN) < 1e-2
        P1_OUT_vec(k) = P1;
        k = k+1;
    end

    % figure(1); hold on
    % plot(ctr,PDOT_IN,'b*',ctr,PDOT_OUT,'ro')

    ctr = ctr + 1;
end

P1_OUT = min(P1_OUT_vec);

end