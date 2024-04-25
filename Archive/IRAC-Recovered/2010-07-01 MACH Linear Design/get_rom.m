function [wn,zeta,tau] = get_rom(ww,gg)

kmin = inf ;
kmax = -inf ;

for i=1:size(gg,1)
    gain = abs(gg(i)) ;
    if( gain < inf )
        k = ww(i)^2 * gain ;
        kmin = min(kmin,k) ;
        kmax = max(kmax,k) ;
    end
end
wn_min = sqrt(kmin) 
wn_max = sqrt(kmax) 
wn = wn_max ;

tmp1 = diff( angle(gg) ) ./ diff(ww') ;
tmp = 0.5 * ( [ tmp1 ; 0 ] + [ 0 ; tmp1 ] ) ;

ix = find( ww > wn , 1 ) ;

if( ix > 1 )
    slope = tmp(ix-1) + ( tmp(ix) - tmp(ix-1) ) / ( ww(ix) - ww(ix-1) ) * ( wn - ww(ix-1) ) ;
    phase = angle(gg(ix-1)) + ( angle(gg(ix)) - angle(gg(ix-1)) ) / ( ww(ix) - ww(ix-1) ) * ( wn - ww(ix-1) ) ;
else
    slope = tmp(1) ;
    phase = angle(gg(1))
end

w = wn ;

tau = -( pi/2 + phase ) / wn ;

a = 4 * wn^2 * w^2 * ( slope + tau ) ;
b = 2 * wn * ( wn^2 + w^2 ) ;
c = ( wn^2 - w^2 )^2 * ( slope + tau ) ;

if( abs(c) > 0 )
else
    zeta = -b / a ;
end
disp(['wn = ' num2str(wn) ' rad/sec , zeta = ' num2str(zeta) ' tau = ' num2str(tau) ' sec' ])
