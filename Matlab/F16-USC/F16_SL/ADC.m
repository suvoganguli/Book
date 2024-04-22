function [TFAC, T, RHO, AMACH, QBAR, PS ] = ADC (VT, ALT)
% air data computer

% Author: Subhabrata Ganguli
%
% Ref: Stevens, Brian L.; Lewis, Frank L.; Johnson, Eric N.. 
% Aircraft Control and Simulation: Dynamics, 
% Controls Design, and Autonomous Systems. 
% Wiley.

% VT    = true velocity (fps)
% ALT   = altitude (ft)

% TFAC  = temperature factor
% T     = temperature (deg R), R = Rankine scale
% RHO   = density (slug/ft^3)
% AMACH = Mach
% QBAR  = dynamic pressure (psf)
% PS    = static pressure (psf)

R0 = 2.37764e-3; %2.377E-3;

TFAC = 1.0 - 0.703E-5 * ALT;
T = 519.0 * TFAC;

if (ALT >= 35000.0) 
    T= 390.0;
end

RHO = R0 * (TFAC^4.14);

AMACH = VT/sqrt(1.4*1716.3*T);          
QBAR = 0.5*RHO*VT*VT;                  
PS    = 1715.0 * RHO * T;

end


