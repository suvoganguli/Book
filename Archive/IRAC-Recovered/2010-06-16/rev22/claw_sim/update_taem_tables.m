
if(HACcase > 0)
    disp('using stored trajectory ...')
    setup_taem_sgs_al
    return
end

% t_taem_ic = 0; % load a pre-computed initial condition (see below)
t_taem_ic = t(end); % use point when sim was suspended
% t_taem_ic = t_taem_sw; % use the point when TAEM is designated to start

if(t_taem_ic > 0)
    tidx = find(t_taem_ic == t);

    taem_ic_struct.VN0 = xdot(tidx,7);
    taem_ic_struct.VE0 = xdot(tidx,8);
    taem_ic_struct.VD0 = -xdot(tidx,9);
    taem_ic_struct.h0 = x(tidx,9);
    N_origin = 0;
    E_origin = 0;
    lat_rad = latlonh_IC(1) + ( x(tidx,7) - N_origin ) / constants.earth_radius;
    lon_rad = latlonh_IC(2) + ( x(tidx,8) - E_origin ) / ( constants.earth_radius * cos( latlonh_IC(1) ) ) ;

    taem_ic_struct.lat0 = lat_rad * 180 / pi ;
    taem_ic_struct.lon0 = lon_rad * 180 / pi ;
else
    % load a pre-computed initial condition for TAEM
%     load(fullfile(BAI_dir,'090512_nominal_taem_ic.mat'))
    load(fullfile(BAI_dir,'taem_ic.mat'))
    ix = 20 ;
    taem_ic_struct.VN0 = taem_ic(1,ix) ;
    taem_ic_struct.VE0 = taem_ic(2,ix) ;
    taem_ic_struct.VD0 = -taem_ic(3,ix) ;
    taem_ic_struct.h0 = taem_ic(4,ix) ;
    taem_ic_struct.lat0 = taem_ic(5,ix) ;
    taem_ic_struct.lon0 = taem_ic(6,ix) ;
end

% reload last condition run
% taem_ic_struct = load(fullfile(BAI_dir,'taem_ic_struct'));

taem_ic_struct
save(fullfile(BAI_dir,'taem_ic_struct'),'-struct','taem_ic_struct')

disp('waiting for trajectory computation ...')
timer_fig = mytimercb(1);
try
    waitfor(timer_fig)
catch
    disp('update_taem_tables interrupted, terminating ...')
    delete(timer_fig)
end

disp('converting ref_trajectory to tables ...')
setup_taem_sgs_al

return

disp('resetting sim transition time into TAEM ...')
t_taem_sw = 301 ;
mode_fw = [ 0 modes.direct ; config.engage_time modes.vel ; 140 modes.att ; t_taem_sw modes.pos ] ;
gain_set_fw(end,1) = t_taem_sw + 5;
