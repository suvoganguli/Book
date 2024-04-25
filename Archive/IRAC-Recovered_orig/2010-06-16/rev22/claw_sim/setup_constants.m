% The inline function 'repval' is used to ensure that all numeric vectors
% have the appropriate length, replicating scalar values if necessary.
repval = inline('x.*ones(1,n)','x','n') ;

% The inline function 'repstr' is used to ensure that all string vectors
% have the appropriate length, replicating scalar values if necessary.
repstr = inline('strcat(x,cell(1,n))','x','n') ;

% constant definitions
clear global constants
global constants

constants.g = 9.80665/0.3048 ; % standard gravity in ft/sec^2
constants.rho0 = 0.002378 ; % slugs/ft^3 (reference sea-level air density)
constants.earth_radius = 2.09e7 ; % ft
constants.nav_pos_ok = 10 ;
% constants.BN = 2 ; % magnetic field strength in North direction
% constants.BD = 1 ; % magnetic field strength in Down direction
constants.r2d = 180 / pi ; % radians to degrees conversion
constants.nm2ft = 6076.11 ; % nautical mile to feet conversion
constants.knots2fps = constants.nm2ft/3600 ; % knots to ft/sec conversion

% the transformation body2vert sends the propulsion axis to minus z
constants.airplane2vert = [0 0 1; 0 1 0; -1 0 0] ;
constants.heli2vert = eye(3) ;

% the transformation body2horz sends the propulsion axis to x
constants.airplane2horz = eye(3) ;
constants.heli2horz = [0 0 -1; 0 1 0; 1 0 0] ;

% standard atmosphere model parameters as a function of altitude
clear global atmos
global atmos
atmos.rho_sl = constants.rho0 ; % slugs/ft^3
atmos.alt_alp = 0.003566 ; % Rankine / foot
atmos.alt_R = 53.357 ; % feet / Rankine
atmos.alt_T0 = 518.4 ; % Rankine
atmos.alt_ht = 35000 ; % feet
atmos.alt_delt = ( 1 - atmos.alt_alp * atmos.alt_ht / atmos.alt_T0 )^( 1/( atmos.alt_alp * atmos.alt_R ) ) ;
atmos.alt_gamma = 1.4 ; % unitless
atmos.alt_P0 = atmos.alt_R*atmos.alt_T0*atmos.rho_sl*constants.g ; % psf

% define control modes
clear global modes
global modes
modes.direct = 0 ;
modes.rate = 1;
modes.att = 2 ;
modes.vel = 3 ;
modes.pos = 4 ;
modes.waypoint = 5 ;
mode_names = fieldnames(modes) ;
mode_numbers = cell2mat(struct2cell(modes)) ;

% define att types
clear global att_type
global att_type
att_type.tiltcam = 1 ;
att_type.ypr_bank = 2 ;
att_type.ypr_skid = 3 ;
att_type.mba_bank = 4 ;
att_type.mba_skid = 5 ;
att_type_names = fieldnames(att_type) ;
att_type_numbers = cell2mat(struct2cell(att_type)) ;
if(length(att_type_numbers) ~= att_type_numbers(end))
    error('att_type fields must map one-to-one onto integers 1 to n') ;
end

% legacy definitions of *_mode
% for mode_name = mode_names'
%     eval(sprintf('%s_mode = %d;', char(mode_name), modes.(char(mode_name)))) ;
% end
% clear mode_name
