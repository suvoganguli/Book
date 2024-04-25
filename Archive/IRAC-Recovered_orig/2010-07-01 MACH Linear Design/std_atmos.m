function [ mach, qbar, rho, temp, sos, V ] = std_atmos(CAS,h)

% given: CAS, h
% find: mach, qbar, rho, temp, sos, V
% standard atmosphere model parameters as a function of altitude

kts2fps = 1.69 ;

g = 32.17 ; % ft/sec^2

rho_sl = 0.002378 ; % slugs/ft^3
alt_alp = 0.003566 ; % Rankine / foot
alt_R = 53.357 ; % feet / Rankine
alt_T0 = 518.4 ; % Rankine
alt_ht = 35000 ; % feet
alt_delt = ( 1 - alt_alp * alt_ht / alt_T0 )^( 1/( alt_alp * alt_R ) ) ;
alt_gamma = 1.4 ; % unitless

if( h < alt_ht )
    temp = alt_T0 - alt_alp * h ;
    sig = ( temp / alt_T0 ) ^ ( -1 + 1 / ( alt_alp * alt_R ) ) ;
else
    temp = alt_T0 - alt_alp * alt_ht ;
    tmp = alt_T0 - alt_alp * alt_ht ;
    sig = alt_delt * alt_T0 / tmp / exp( ( h - alt_ht ) / ( alt_R * tmp ) ) ;
end
    
rho = rho_sl * sig ;

sos = sqrt( alt_gamma * alt_R * g * temp ) ;

% rho * V^2 = rho_sl * CAS^2
V = sqrt( rho_sl / rho ) * CAS * kts2fps ;

mach = V / sos ;

qbar = 0.5 * rho * V^2 ;
