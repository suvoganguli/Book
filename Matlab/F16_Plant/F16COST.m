function F = F16COST(z,xcg,V0,h0)
% F16 cost function

% Author: Subhabrata Ganguli

% State 
x = zeros(13,1);
x(1:9) = z(1:9);

% Control
u = z(10:13);

x(12) = h0; % altitude
x(13) = TGEAR(u(1));

% Call F16DYN
xdot = F16DYN(x,u,xcg);

% Notations
V = x(1);
alpha = x(2);
theta = x(5);
gam = theta - alpha;
beta = x(3);
phi = x(4);
psi = x(6);
pqr = x(7:9);

% Constraints
Q = [xdot(1:9);
     V - V0;
     gam;
     beta;
     phi;
     psi;
     pqr;
    ];

% Weight
H = eye(17)*1e3;

% Quadratic Scalar Cost
F = Q'*H*Q;

end