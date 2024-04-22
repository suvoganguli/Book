function aero = set_aero_params(vehicle_params)

global MACH

disp('Loading BAM bam aero model')

aero.Sref = 403.54 ; % ft^2
aero.bspan = 23.69 ; % feet
aero.cbar = 10 ; % feet

aero.vane_nom = zeros(1,MACH.num_u_aero) ;
aero.vane_min = -30*ones(1,MACH.num_u_aero) ;
aero.vane_max = 30*ones(1,MACH.num_u_aero) ;
aero.vanedot_max = 50*ones(1,MACH.num_u_aero) ;
