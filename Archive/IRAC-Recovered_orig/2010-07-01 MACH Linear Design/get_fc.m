function [fc] = get_fc(fi)
if( fi < 0.25 )
    fc = 0.5 * ( 1 + sqrt( 1 - 4 * fi ) ) ;
else
    fc = sqrt(fi) ;
end ;
