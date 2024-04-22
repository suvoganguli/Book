% set configuration options

close_system('ghost_model',0);  % this is a bizarre fix (steve/suvo - 10/14/09)

clear global config vehicle_def MACH_def
global config

setup_constants

config_case = 11 ;  % 5 - BAM, 11 - GTM

%%

switch(config_case)
    case 5
        % use BAM
        set_vehicle_type('BAM') ;
        config.engage_time = 0.01 ;
        config.mode = modes.vel ;
        % config.mode = modes.pos ;
        config.use_NdEdh_pos = 1 ;
            
        % config.att_type_fw = [ 0 att_type.tiltcam ] ; config.fcase = 1 ; % vertical
        config.att_type_fw = [ 0 att_type.mba_bank ] ; config.fcase = 2 ; % horizontal
        % config.att_type_fw = [ 0 att_type.ypr_bank ] ; config.fcase = 2 ; % horizontal
        config.altitude_stop = -inf ;
        % uncomment to use tvc for pitch only
        % config.tvc_min = [-40 0] ;
        % config.tvc_max = [ 40 0] ;
        config.tsim_max = 50 ;
    case 11        
        % use GTM       

        set_vehicle_type('GTM') ; % config.model_name needs to be defined        
        % config.model_name = 'gtm_design_dbg' ;  % suvo - 10/09/09 (to debug using different versions)                
        config.model_name = 'gtm_design' ;  % suvo - 06/17/10               

        config.use_NdEdh_pos = 0 ;  % 1 - used in mixed mode scenarios along with "config.mode = modes.pos"       
        config.att_type_fw = [ 0 att_type.mba_bank ] ;
        config.altitude_stop = -inf ;  
        config.engage_time = 0.0;  % 0.01 (before 2/10/10)
        config.MACH_att_fb = 0.5; % suvo/steve/10-13
        %config.SERVO.servo_type = 'variable rate limit servo model';
        
        config.flag_compare_with_lin = 0;
        
        % sample times
        %config.dtsim = 1/500;
        %config.dt = 1/250;        
        config.dtsim = 1/200;
        config.dt = 1/100;
                
        % actuator model
        %config.SERVO.servo_type = 'models/1st order actuator model';
        config.SERVO.servo_type = 'models/1st order actuator model with delay';
            
        % 1/22/2010
        config.pqr_wght_u_pref = {'throtdiff',1}; 
        
        % Select trim cases
        % 1: eas = 75, gamma = 0  (trim using elev)
        % 2: eas = 75, gamma = 0  (trim using stab)
        % 3: eas = 75, gamma = 0, yaw_rate = 6.48 deg/sec (50 sec circle)
        
        % this is a temporary code - since other mat-files are not created
        config.fcase = 1 ;      % this is used in "set_vehicle_params.m"
        if config.fcase == 1                
            config.do_quicktrim = 1; % 1 = bypasses trim routine call (currently only for fcase 1)
                                     % used in "set_vehicle_params.m"   
        else
            config.do_quicktrim = 0; % 1 = bypasses trim routine call (currently only for fcase 1)
                                     % used in "set_vehicle_params.m" 
        end
        config.do_quicktrim = 1;
        config.obac_eq_trac = 1; % 1 = set trac equal to obac (used in "setup_sim.m")    
        
        % Select an actuator failure scenario
        do_actfail_scenarios
        
        % Select control law gains (used in "set_loop_gains.m")
        config.gain_set = 0;   % keep empty or dont define if using one set of gains only
        % config.gain_set = 1; % added - 1/26/2010 (this is for diff-thrust 
                               % example presented in NASA Glenn)

        if ~exist('gtm_exptno','var')
            % run open-loop trim condition
            disp('Running open-loop at trim');
            config.mode = modes.direct ;
            config.tsim_max = 20 ;
           
        else
            % command tracking            
            do_command_tracking     %   config.mode is set within this script
        end
        
        disp('Note 1: True GTM control limits are not set yet');
        disp('Note 2: Throttle units (0-100) may cause bad condition no.');
        disp('Note 2b: Correct the units shown for throttle');
        
    otherwise
        error('config_case = %d is not defined (MACH.u_units') ;
end

%%

traj_name = get_value('traj_name','onerror',[]) ;
if(ischar(traj_name))
    try
        if(get_value('load_stored_traj','onerror',1))
            if(~exist(traj_name))
                load(traj_name) ;
            end
            config.vel_cmd_fw = eval(traj_name) ;
        end

        disp(['Using trajectory = ' traj_name])
    catch
        error(['Failed to load requested velocity trajectory: ' traj_name]) ;
    end
end


%%

try
    % choose OBAC model and initialize CLAW
    setup_claw
        
    % ------------------------------------------
    % Code added for GTM only (Suvo - 10/08/09)
    
    if exist('gtm_exptno','var')   
        switch (config.mode)
            case modes.rate
               [cmd_nr, cmd_nc] = size(config.rate_cmd_fw); % rows, cols
               config.rate_cmd_fw(1:cmd_nr,5) = ...
                   ones(cmd_nr,1)*obac_params.u_trim(obac_params.throttle_idx);  % add trim throttle
%                if gtm_exptno == 31
%                    % increase throttle by 10% at break-point 7 (t = 6 sec)
%                    % (see do_command_tracking for details of break-points)
%                    config.rate_cmd_fw(7:cmd_nr,5) = ...
%                       ones(cmd_nr-7+1,1)*obac_params.u_trim(obac_params.throttle_idx)*1.20;
%                end
            case modes.att
               [cmd_nr, cmd_nc] = size(config.att_cmd_fw); % rows, cols
               config.att_cmd_fw(1:cmd_nr,5) = ...
                   ones(cmd_nr,1)*obac_params.u_trim(obac_params.throttle_idx);  % add trim throttle               
               
            case {3,4}  % don't need to add trim throttle, since throttle is commanded by the claw
                % keyboard
        end
    end
                
    % ------------------------------------------

    % choose TRAC model and initialize sim
    setup_sim
    
    % set links to proper models
    if ~exist('sim_name','var')
        disp('setting sim_name inside doit_GTM');
        sim_name = 'main_sim_adapt_Gref_SP';
    end       
    set_models(sim_name)
    
    % refresh model before first execution so that it doesn't crash
    % (We have no idea what's broken, or why this fixes it :-()
    model_obj = get_param(sim_name,'Object');
    model_obj.refreshModelBlocks
    
    % set links to proper models, again :-(
    set_models(sim_name)
catch
    if(exist('ple.m'))
        ple % print error stack with hyperlinks to files
    else
        rethrow(lasterror)
    end
end
