function set_vehicle_def

clear global vehicle_def
global vehicle_def

vehicle_def.obac_model_type = 'gtm' ;

vehicle_def.use_variable_mass = 0 ;
vehicle_def.weight = 49.6 ; % lb  (MWS.w0)

vehicle_def.vane_names = {'elev' 'ail' 'rud' 'stab' 'elevgain' 'throtdiff'} ;
vehicle_def.mixer = [0 1 0 ; 1 0 0 ; 0 0 1; 0 1 0; 0 0 0; 0 0 0] ;  % assume: psuedo-da, de, dr
vehicle_def.vane_units = set_named_values(vehicle_def.vane_names,'array','default','deg') ;

% correct the units - ask steve - suvo (2009/10/27)
% a) is the throt case correctly handled
% b) how to correct the case for elevgain

vehicle_def.vane_units{5} = '0 to 1';
vehicle_def.vane_units{6} = '% (R-L)/2';
vehicle_def.throt_names = {'throt'};
vehicle_def.throt_units = set_named_values(vehicle_def.throt_names,'array','default','% (R+L)/2') ;

vehicle_def.throt_min    = 0;
vehicle_def.throt_max    = 100;  % perc
vehicle_def.throtdot_max = 70;   % perc/sec - assuming tau = 1.44 sec

vehicle_def.p_max = 1.0 ; % rad/sec
vehicle_def.pqr_wght_cv = [ 1 2 2 ] ; % lower priority for roll axis (airplane)


% define actuators
% actuator order:
%     'elev'    'ail'    'rud'    'stab'    'elevgain'    'throtdiff'
%     'throt'    'tvc_m'    'tvc_n'    'rcs00'
% added on 1/26/2010

vehicle_def.SERVO.w = [31.4*ones(1,4) 100 6 6 100 100 100];

% define sensors
% sensor order: q alpha
%vehicle_def.SENSOR.w = [100 100];
%vehicle_def.SENSOR.x0 = [0 0];

flag_actdelay = 1;
%flag_sensdelay = 1;

if flag_actdelay == 1    
    vehicle_def.SERVO.delay = [0.015] ; % 15 msec
end

% if flag_sensdelay == 1    
%     vehicle_def.SENSOR.delay = [0.01] ; % 10 msec
% else
%     vehicle_def.SENSOR.delay = [0] ; 
% end


% EOF