function F = f16_cost(z)

x = zeros(13,1);
x = z(1:9);

u = z(10:13);

x(13) = TGEAR(u(1));

xdot = F16_DYN(x,u,0.35);
V = x(1);
alpha = x(2);
theta = x(5);
gam = theta - alpha;
beta = x(3);
phi = x(4);
psi = x(6);
pqr = x(7:9);

Q = [xdot(1:9);
     V - 502;
     gam;
     beta;
     phi;
     psi;
     pqr;
    ];

H = eye(17)*1e3;

%H([2 3 7 8 9]) = 100*H([2 3 7 8 9]);

F = Q'*H*Q;

% XD(1)**2 + 100.0*( XD(2)**2 + XD(3)**2 )
% &      + 10.0*( XD(7)**2 + XD(8)**2 + XD(9)**2 )


end