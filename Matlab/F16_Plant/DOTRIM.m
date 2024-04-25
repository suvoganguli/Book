% DOTRIM.m
% Trim Function

% Author: Subhabrata Ganguli

% V0 = input
% H0 = input

% Straight Level Flight
% theta = alpha (flight path angle = 0)

%% Inputs

V0 = 502; % ft/sec
h0 = 0; % ft
xcg = 0.35; 

%% Set trim function input

Z0 = [zeros(13,1)];

Z0(1) = V0;

[Zstar,f0,exitflag] = fminunc('F16COST',Z0,...
    optimset('TolFun',1e-10,...
    'TolX',1e-10,'MaxFunEval',1e5,'MaxIter',1e5),...
     xcg,V0,h0)

x13 = TGEAR(Zstar(10));

X_trim = [Zstar(1:9); 0; 0; 0; x13];
U_trim = Zstar(10:13);

save trimcond X_trim U_trim xcg
