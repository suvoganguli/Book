function [out] = projection_Kx(in)

thetamax = 300*1e1;  % 600  - norm(Kxstar-Kxnom) = 292
thetamax = 300*1e5;  % -- EXPT

eta = 0.0001*thetamax;

theta(1:3,1) = in(1:3);
y(1:3,1)     = in(4:6);

f = (norm(theta)^2 - thetamax^2)/(eta*thetamax^2);

gradf = 2*theta/(eta*thetamax^2);

if ((f > 0) && (y'*gradf > 0))
    delta = (gradf*gradf')/norm(gradf)^2 * y * f;
    yproj = y - delta;    
    disp('projection active');
else
    yproj = y;
    delta = zeros(3,1);
end

out = [yproj; delta];

return
