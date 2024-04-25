function set_body_frame(body_frame)

global MACH constants

% define body frame as either airplane or heli
switch(body_frame)
    case 'airplane'
        % use airplane frame as body frame (propulsion axis is body x)
        MACH.body2vert = constants.airplane2vert ;
        MACH.body2horz = constants.airplane2horz ;
    case 'heli'
        % use heli frame as body frame (propulsion axis is minus body z)
        MACH.body2vert = constants.heli2vert ;
        MACH.body2horz = constants.heli2horz ;
    otherwise
      error('unknown body frame: %s', body_frame);
end

MACH.vert2body = MACH.body2vert' ;
MACH.horz2body = MACH.body2horz' ;
