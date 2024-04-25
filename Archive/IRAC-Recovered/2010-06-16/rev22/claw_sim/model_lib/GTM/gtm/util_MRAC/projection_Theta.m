function out = projection_Theta(in)

thetamax = 5;
eta = 0.1*thetamax;

theta(1:11,1) = in(1:11);
y(1:11,1)     = in(12:22);

f = (norm(theta)^2 - thetamax^2)/(eta*thetamax^2);

gradf = 2*theta/(eta*thetamax^2);

if ((f > 0) && (y'*gradf > 0))
    out = y - (gradf*gradf')/norm(gradf)^2 * y * f;    
else
    out = y;
end

% if (norm(theta)^2 - thetamax^2) > 0
%     keyboard
% end

return
