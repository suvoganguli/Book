% script for setting up the trim condition for GTM

% initialize vectors
vehicle_params.x_trim = [] ;
vehicle_params.u_trim = zeros(vehicle_params.num_u,1) ;

%% Access GTM trim routine

% model name used for trim-routine
gtm_model = config.model_name;

% get the gtm parameters from previous init_design call in
% set_vehicle_params.m

if config.do_quicktrim
    ;
else    
    MWS = vehicle_params.aero; % Note: aero is set as MWS in set_vehicle_params
    loadmws(MWS,gtm_model);
    
    % Trim cases
    fcase = get_value('fcase') ;
    switch(fcase)
        
        % ==========================
        % LONG MODE
        % ==========================
        case 1
            eas0 = 75;  % knots
            gamma0 = 0; % deg            
            % call gtm trim routine
            [MWS_new,Xtrim,Trimcond,Err] = trimgtm(struct('eas',eas0, 'gamma',gamma0));
            
            
        case 2
            eas0 = 75;  % knots
            gamma0 = 0; % deg            
            % call gtm trim routine
            [MWS_new,Xtrim,Trimcond,Err] = trimgtm(struct('eas',eas0, 'gamma',gamma0),'stab');
            
        % ==========================
        % LAT MODE
        % ==========================
            
        case 3
            eas0 = 75; % knots
            gamma0 = 0; % deg
            
            t0 = config.engage_time ;
            tf = t0 + 50 ;
            
            % trimming for steady-state turn
            flag_trim = 2; % options 1 and 3 does not trim well 
            switch(flag_trim)
                case 1      % specify r0                   
                    turn_rate0 = 2*pi/(tf - t0); % chidot (= omega)
                    turn_speed0 = 128;  % this is a hack from plots (should relate to eas0)
                    phi0 = atan( turn_rate0 * turn_speed0 / 32.17);
                    
                    r0 = turn_rate0 * cos( phi0 );   % r = omega * cos(phi0)
                    r0_deg = r0*180/pi;
                    
                    % call gtm trim routine
                    [MWS_new,Xtrim,Trimcond,Err] = ...
                        trimgtm(struct('eas',eas0, 'gamma',gamma0,'rdeg',r0_deg));
                    
                case 2      % specify psidot0
                    turn_rate0 = 2*pi/(tf - t0); % chidot (= omega)
                    turn_speed0 = 124;  % this is a hack from plots (should relate to eas0)
                    phi0 = atan( turn_rate0 * turn_speed0 / 32.17);
                    
                    yaw_rate0 = turn_rate0 ;   % psidot = chidot (=omega) [neglect thetadot term]
                    yaw_rate0_deg = yaw_rate0*180/pi;
                    
                    % call gtm trim routine
                    [MWS_new,Xtrim,Trimcond,Err] = ...
                        trimgtm(struct('eas',eas0, 'gamma',gamma0,'yawrate',yaw_rate0_deg));     
                    
                case 3      % specify phi0
                    turn_rate0 = 2*pi/(tf - t0); % chidot (= omega)
                    turn_speed0 = 124;  % this is a hack from plots (should relate to eas0)
                    phi0 = atan( turn_rate0 * turn_speed0 / 32.17);
                    
                    phi0_deg = phi0*180/pi;
                    
                    % call gtm trim routine
                    [MWS_new,Xtrim,Trimcond,Err] = ...
                        trimgtm(struct('eas',eas0,'gamma',gamma0,'roll',phi0_deg));
                    
            end          
        otherwise
            error('set_trim: fcase = %d not found', fcase)
    end
        
    appendmws(MWS_new,gtm_model); 
    vehicle_params.aero = MWS_new;
    
end


%% Code to save MWS, test trim and linearization after updating GTM model

% Change config.quicktrim = 0 before running the code below

% disp('Keyboard in set_trim (to save MWS_new into MWS_somename.mat)');
% keyboard
% tmpfilename = fullfile('model_lib','GTM','gtm','MWS_fcase1.mat');
% eval(['save ' tmpfilename ' MWS_new Xtrim Trimcond Err;']);

% disp('Keyboard in set_trim (to linearize model)');
% keyboard
% [sys,londyn,latdyn]=linmodel(MWS_new);


%% Map data to vehicle_params data-structure

att0_gtm    = Xtrim(10:12);
e0_gtm      = euler2q(att0_gtm,[1 0 0 0],2);  % att_type.ypr_bank = 2

% states
vehicle_params.x_trim(MACH.pqr_idx)  = ...
    [Trimcond.pdeg Trimcond.qdeg Trimcond.rdeg]'*pi/180 ;
vehicle_params.x_trim(MACH.uvw_idx)  = Xtrim(1:3);
vehicle_params.x_trim(MACH.NEh_idx)  = [0; 0; Xtrim(9)];  % Xtrim(7:8) = lat/lon
vehicle_params.x_trim(MACH.quat_idx) = e0_gtm(:);

% control
vehicle_params.u_trim(MACH.u_idx.elev)  = Trimcond.elevator ;
vehicle_params.u_trim(MACH.u_idx.ail)   = Trimcond.aileron ;
vehicle_params.u_trim(MACH.u_idx.rud)   = Trimcond.rudder ;
vehicle_params.u_trim(MACH.u_idx.stab)   = Trimcond.stab ;
vehicle_params.u_trim(MACH.u_idx.elevgain)   = 1 ;
vehicle_params.u_trim(MACH.u_idx.throt) = Trimcond.throttle ; %/100 ;

% make sure these are column vectors
vehicle_params.x_trim = vehicle_params.x_trim(:);
vehicle_params.u_trim = vehicle_params.u_trim(:);

% EOF

