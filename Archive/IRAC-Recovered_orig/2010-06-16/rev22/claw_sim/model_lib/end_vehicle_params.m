function vehicle_params = end_vehicle_params(vehicle_params)

% [2008-04-16 SGP] Assume zero trim values for any tvc control inputs
% until we have something better.
if(length(vehicle_params.u_trim) < max(vehicle_params.tvc_idx))
    vehicle_params.u_trim(vehicle_params.tvc_idx) = 0 ;
end

% [2008-04-16 SGP] Assume zero trim values for any rcs control inputs
% until we have something better.
if(length(vehicle_params.u_trim) < max(vehicle_params.rcs_idx))
    vehicle_params.u_trim(vehicle_params.rcs_idx) = 0 ;
end
