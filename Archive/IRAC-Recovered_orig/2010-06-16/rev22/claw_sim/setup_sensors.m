
% Default Settings

n_sensors               = 19 + MACH.num_u;

SENSOR.pqr_idx          = [1:3];
SENSOR.latlonh_idx      = [4:6];
SENSOR.quat_idx         = [7:10];
SENSOR.NEDdot_idx       = [11:13];
SENSOR.accels_cg_idx    = [14:16];
SENSOR.NED_wind_idx     = [17:19];
SENSOR.umeas_idx       = 19+[1:MACH.num_u];

SENSOR.w                = 100*ones(n_sensors,1);
SENSOR.delay            = 5e-3; % scalar

SENSOR.x0               = [pqr_trim_IC; 
                           latlonh_IC'; 
                           quat_trim_IC; 
                           [Nd_trim_IC Ed_trim_IC -hd_trim_IC]';
                           [0 0 0]';
                           [0 0 0]'
                           MACH_U_nom_IC];
                           
                       
SENSOR.ulim             = Inf(n_sensors,1)';
SENSOR.llim             = -Inf(n_sensors,1)';

    
                       