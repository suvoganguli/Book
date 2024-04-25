
fcase = get_value('fcase') ;

vehicle_params.x_trim = [] ;
vehicle_params.u_trim = zeros(vehicle_params.num_u,1) ;

h0 = 10000 ;

switch(fcase)
    case 1
        % straight up
    	vehicle_params.x_trim = [ 0 0 0 1000 0 0 0 0 h0 0.70710678118656 0 0.70710678118656 0 ]' ;
        vehicle_params.u_trim(MACH.throttle_idx) = 1.39037366087253 ;
    case 2
    	% trimmed level (more or less :-)        
        vehicle_params.x_trim = [ 0 0 0 985.353 0 170.527 0 0 h0 0.996332 0 0.0855776 0 ]';
        vehicle_params.u_trim = [ 0 -0.981848 0 0.628257 0 0 0 ]';
end

if(isempty(vehicle_params.x_trim))
    error('set_trim: fcase = %d not found', fcase)
end
