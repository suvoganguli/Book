function cost = mpccost3(z,H,nx,AX,BU,N)

xk = z(1:nx);
Uk = z((nx+1)*N:end);

Xk = AX*xk + BU*Uk;

z_ = [Xk; Uk];

cost = z_'*H*z_;

end