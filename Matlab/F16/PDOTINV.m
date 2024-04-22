function [P1_OUT, sol] = PDOTINV(P3,PDOT_IN)
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
P1_OUT = 0;
ctr = 1;
k = 1;
sol = 0;

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
    elseif abs(PDOT_OUT - PDOT_IN) < 1e-3
        P1_OUT_vec(k) = P1;
        k = k+1;
    end

    ctr = ctr + 1;
end

if ~isempty(P1_OUT_vec)
    [~,idx] = min(abs(PDOT_OUT - PDOT_IN));
    P1_OUT = P1_OUT_vec(idx);
    sol = 1;
else
    sol = 0;
end

if sol == 0
    disp('No Solution')
    keyboard
else
    disp('Solution')
    PDOT_true = PDOT(P3,P1_OUT);
    disp([PDOT_IN PDOT_true])
    if abs(PDOT_IN - PDOT_true) > 1
        keyboard
    end
end

end