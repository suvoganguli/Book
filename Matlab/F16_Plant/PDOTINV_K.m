function [P1_OUT] = PDOTINV_K(P3,PDOT_IN)

% Author: Subhabrata Ganguli
%
% Ref: Stevens, Brian L.; Lewis, Frank L.; Johnson, Eric N..
% Aircraft Control and Simulation: Dynamics,
% Controls Design, and Autonomous Systems.
% Wiley.

% P3 = actual power
% P1 = power command
% PDOT_IN = power rate

if isempty(P3)
    disp('empty')
end
ctr = 1;
n = length(0:0.01:100);
P1_OUT_vec = inf*ones(n,1);
err = inf*ones(n,1);

for P1 = 0:0.01:100
    if (P1 >= 50)
        if (P3 >= 50)
            T = 5;
            P2 = P1;
        else
            P2 = 60 + 0.1*P1;
            T = RTAU_K(P2-P3);
        end
    else
        if (P3 >= 50)
            T = 5;
            P2 = 40 + 0.1*P1;
        else
            P2 = P1;
            T = RTAU_K(P2-P3);
        end
    end

    PDOT_OUT = T*(P2-P3);

    P1_OUT_vec(ctr) = P1;
    err(ctr) = abs(PDOT_OUT - PDOT_IN);

    ctr = ctr + 1;
end

[~,idx] = min(err);

P1_OUT = P1_OUT_vec(idx);

end