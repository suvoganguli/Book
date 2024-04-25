function out = rbf(in)

N       = in(1);
x       = in(2);
C(:,1)  = in(3:N+2);
Sig(:,1) = in(N+3:end);

for ii = 1:N
    out(ii,1) = exp( -(norm(x - C(ii,1))^2)/(Sig(ii,1)^2) );
end

return

