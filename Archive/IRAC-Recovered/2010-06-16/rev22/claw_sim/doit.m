% set configuration options
clear global config vehicle_def MACH_def
global config

setup_constants

% Note: description of config variables moved to bottom of file

config_case = 10 ;

% uncomment to use S-function claw_main
% config.sim_name = 'main_sim_clawsf' ; config.use_clawsf = 1 ;

switch(config_case)
    case 1
        % Dale's TAEM profile
        set_vehicle_type('NGC4') ;
        config.engage_time = 0.01 ;
        config.mode = modes.vel ;
        config.mode_fw = [ 0.01 modes.vel ] ;
        config.weight = 'noprop' ; % landing weight
        config.att_type_fw = [ 0 att_type.mba_bank ] ;
        % start with throttle on and cut off at 10 seconds
        config.fail_surfs = {0 'throt' 1 1 'obac'; 10 'throt' 0 0 'obac'} ;
        config.fcase = 5 ; % trim at altitude = 21749 feet and V = 400 ft/sec
        config.vel_cmd_select = 2 ; % use landing profile vel cmds
        config.use_tvc = 0 ; % do not use thrust vectoring
        config.tsim_max = 200 ;
        config.traj_name = 'DFE_TAEM_profile' ;
        config.load_stored_traj = 0 ;
        config.use_rcs = 0 ;
        
        % if not using the S-function CLAW we could remove RCS jets from
        % the inputs, but setting use_rcs = 0 achieves almost all of this
        % efficiency savings
%         if(~get_value('use_clawsf'))
%             config.rcs_select = [] ;
%         end
    case 2
        % ascent and combined profiles
        % use config_case = 10 for rocketback_combined
        
        set_vehicle_type('NGC4') ;
        config.engage_time = 0.01 ; % these are not trim conditions!
        config.mode = modes.vel ;
        config.weight = 'maxprop' ; % default weight is with max propellant (aka GLOW)
        config.fcase = 1 ; % pointed straight up on ground with zero velocity
        config.att_type_fw = [ 0 att_type.tiltcam; 50 att_type.mba_bank ] ;
        config.vel_cmd_select = 1 ; % default is to use a stored velocity profile
            
        config.fail_surfs = {0 'throt' 1 1 'obac'} ; % default throttle profile is full on

        config.use_throt = 3 ; % use individual engines instead of ganged
        
        config.throtdot_max = 10 ;

        config.use_tvc = 1 ; % use ganged thrust vectoring

        config.rcs_cvddes_thresh = 2.58e-4 ; % half of smallest norm cvd achievable
        config.rcs_efficiency_thresh = 0.3 ;
                
        % by default, all of these sub-cases may load a stored
        % vel_cmd_fw trajectory using the generic code further below,
        % but some may not, or may pre-load, in which case they should
        % set config.load_stored_traj = 0.
        
%         config.traj_name = 'Honeywell_test_ascent' ; config.tsim_max = 300 ;
%         config.traj_name = 'Honeywell_test_ascent_after_MECO' ; config.tsim_max = 110 ;
%         config.traj_name = 'NGC_maxmach_ascent' ; config.tsim_max = 184 ;
%         config.traj_name = 'NGC_heater_ascent' ; config.tsim_max = 200 ;
%         config.traj_name = 'NGC_heater_combined' ; config.tsim_max = 856 ;
%         config.traj_name = 'NGC_glideback_ascent' ; config.tsim_max = 99 ;
%         config.traj_name = 'NGC_glideback_combined' ; config.tsim_max = 579 ;
%         config.traj_name = 'NGC_rocketback_ascent' ; config.tsim_max = 137 ;

        switch(config.traj_name)
            case { 'NGC_maxmach_ascent', 'NGC_rocketback_ascent' }
                % throttle remains full throughout traj
            case 'NGC_heater_combined'
                % throttle profile for heater combined
                config.fail_surfs = {0 'throt' 1 1 'obac'; 153 'throt' 0.6 0.6 'obac'; 204.78 'throt' 0 0 'obac'} ;
            case 'NGC_heater_ascent'
                % throttle profile for heater ascent
                config.fail_surfs = {0 'throt' 1 1 'obac'; 153 'throt' 0.6 0.6 'obac'} ;
                % fail body flap hard up at 160 sec and tell CLAW at 165 sec
                %                     config.fail_surfs = vertcat(config.fail_surfs,{160 'BF' -10 -10 'trac'}) ;
                %                     config.fail_surfs = vertcat(config.fail_surfs,{165 'BF' -10 -10 'obac'}) ;
            case 'NGC_glideback_combined'
                % throttle profile for glideback combined
                config.fail_surfs = {
                    0 'throt' 1 1 'obac' ;
                    8.419622 'throt' 0.6 0.6 'obac' ;
                    39.38819 'throt' 1 1 'obac' ;
                    44.22926 'throt' 0.6 0.6 'obac' ;
                    98.552 'throt' 0 0 'obac'
                    } ;
                config.weight = 44378 ; % start with partial fuel load
            case 'NGC_glideback_ascent'
                % throttle profile for glideback ascent
                config.fail_surfs = {
                    0 'throt' 1 1 'obac' ;
                    8.419622 'throt' 0.6 0.6 'obac' ;
                    39.38819 'throt' 1 1 'obac' ;
                    44.22926 'throt' 0.6 0.6 'obac'
                    } ;
                config.weight = 44378 ; % start with partial fuel load

            case 'Honeywell_test_ascent'
%                 config.enable_bb_fw = [ 0 1 ] ;
%                 config.att_type_fw = [ 0 att_type.tiltcam ] ; % stay in tiltcam
                config.mode_fw = [ 0 modes.direct ; config.engage_time modes.vel ; 135 modes.att ] ;
                config.att_cmd_select = 1 ;
                config.use_att_rate_cmd_fw = [ 0 1 ] ;
                config.att_cmd_fw = [ 0 0 0 0 1 ] ; % default to no (att rate) command
                config.vel_cmd_select = 3 ; % builtin velocity profile
                config.load_stored_traj = 0 ;

                %             % mu or tilta step (or pulse)
                %             config.att_cmd_fw = [
                %                 0 0 0 0 1
                %                 190 0 0 0 1
                %                 190 1/20 0 0 1
                %                 190.2 1/20 0 0 1
                %                 190.2 0 0 0 1
                % %                 195.0 0 0 0 1
                % %                 195.0 -1/50 0 0 1
                % %                 195.2 -1/50 0 0 1
                % %                 195.2 0 0 0 1
                %                 ] ;
                % alpha or tiltb step
                config.att_cmd_fw = [
                    0 0 0 0 1
                    200 0 0 0 1
                    200 0 5 0 1
                    200.2 0 5 0 1
                    200.2 0 0 0 1
                    ] ;

                % example of turning on a selected RCS jet dymanically
                %             config.fail_surfs = vertcat(config.fail_surfs,{220 'rcs04' 1 1 'obac'});

            case 'Honeywell_test_ascent_after_MECO'
                % start trajectory after MECO in attitude mode, and enable
                % bang-bang control

                config.enable_bb_fw = [ 0 1 ; 60 0 ] ; % disable bangbang to check variable gains
                config.gain_set_fw = [ 0 -1 ] ;
                config.fcase = 6 ;
                config.weight = 'noprop' ;
                config.fail_surfs = {0 'throt' 0 0 'obac'} ; % start with throttle off
                config.use_throt = 0 ;
                config.mode_fw = [ 0 modes.direct; config.engage_time modes.att ] ;
                config.att_type_fw = [ 0 att_type.tiltcam ] ; % stay in tiltcam
%                 config.att_type_fw = [ 0 att_type.mba_bank ] ;
                config.use_att_rate_cmd_fw = [ 0 1 ] ;
                config.att_cmd_select = 1 ;
                config.att_cmd_fw = [ 0 0 0 0 0 ] ; % default to no (att rate) command
                config.load_stored_traj = 0 ;

                % mu/tilta rate command
                if(1)
                    config.att_cmd_fw = [
                        10 0 0 0 0
                        10 50*0.1 0 0 0
                        10.2 50*0.1 0 0 0
                        10.2 0 0 0 0
                        ] ;
                end
                % alpha/tiltb rate command
                if(0)
                    config.att_cmd_fw = [
                        10 0 0 0 0
                        10 0 50*0.1 0 0
                        10.2 0 50*0.1 0 0
                        10.2 0 0 0 0
                        ] ;
                end
                % beta/cam rate command
                if(0)
                    config.att_cmd_fw = [
                        10 0 0 0 0
                        10 0 0 50*0.1 0
                        10.2 0 0 50*0.1 0
                        10.2 0 0 0 0
                        ] ;
                end
            otherwise
                error('no case for trajectory: %s', config.traj_name) ;
        end
    case 3
        % Dale's descent from Mach 8 profile
        % [2009-02-25 SGP] this trajectory needs more tweaking of the
        % initial engagement
        set_vehicle_type('NGC4') ;
        config.att_type_fw = [ 0 att_type.mba_bank ] ;
        
        config.engage_time = 0.01 ; % sec
        config.mode = modes.vel ;
        config.fail_surfs = {0 'throt' 0 0 'obac'} ; % ramp down throttle IC immediately
        config.weight = 'noprop' ; % landing weight
        config.use_variable_mass = 0 ; % don't use variable mass (and don't enforce fuel restrictions)
        config.fcase = 2 ; % trim at altitude = 120073 feet and V = 7139 ft/sec (see set_trim.m)
        config.vel_cmd_select = 1 ; % use stored profile vel_cmd_fw

%         config.traj_name = 'NEhdot_maxdrag_trajectory' ;
        config.traj_name = 'NEhdot_mindrag_trajectory' ;
        try
            load('NEhdot_maxD_minD_trajectories') ;
            config.load_stored_traj = 0 ;
        catch
            error('Failed to load NEhdot_maxD_winD_trajectories')
        end

        % hold trajectory initial condition for t_start seconds
        t_start = 6 ; % sec
        tmp = eval(config.traj_name) ;
        vel_cmd_0 = tmp(1,:) ; % initial velocities from trajectory
        tmp(:,1) = tmp(:,1) + t_start ; % shift time column in trajectory by t_start
        tmp = [ vel_cmd_0; tmp ] ; % tack shifted trajectory onto initial condition
        tmp = tmp*[ 1 0 0 0 0 ; 0 1 0 0 0 ; 0 0 1 0 0 ; 0 0 0 0 1 ] ; % insert zero cam cmd in column 4
        config.vel_cmd_fw = tmp ;
        clear tmp vel_cmd_0
        
        config.use_tvc = 0 ; % do not use thrust vectoring
        config.tsim_max = config.vel_cmd_fw(end,1) ; % stop at end of traj
        
        if(get_value('use_clawsf'))
            % if using the S-function CLAW, RCS jets must be present,
            % but we lock them at the initial condition of zero.
            config.rcs_select = 1:10 ;
            config.fail_surfs = vertcat(config.fail_surfs,{0 'rcs' 'set' 'cmd' 'obac'}) ;
        end

    case 4
        % heater, glideback, or rocketback descent from NGC profiles
        set_vehicle_type('NGC4') ;
        config.att_type_fw = [ 0 att_type.mba_bank ] ;
        config.engage_time = 0.01 ;
        config.mode = modes.vel ;
        config.fail_surfs = {0 'throt' 0 0 'obac'} ; % throttle is off
        config.weight = 'noprop' ;
        config.vel_cmd_select = 1 ; % use a stored velocity profile
        
        % Note: NGC_rocketback_descent has been modified to record number
        % 41 of the original, which has been save as
        % NGC_rocketback_descent_orig, and time has been shifted to zero
        
%         config.traj_name = 'NGC_heater_descent' ; config.fcase = 3 ; config.tsim_max = 651.8147 ;
%         config.traj_name = 'NGC_glideback_descent' ; config.fcase = 4 ; config.tsim_max = 579.3196 ;
        config.traj_name = 'NGC_rocketback_descent' ; config.fcase = 7 ; config.tsim_max = 387.97638 ;

        config.rcs_select = 1:10 ; % use first 10 defined RCS jets

        % stop using all aero surfaces at 20 seconds to see if RCS can take
        % over control
%         config.fail_surfs = vertcat(config.fail_surfs, {20 'allaero' 0 0 'obac'}) ;

        % don't use SB at all
%         config.fail_surfs = vertcat(config.fail_surfs, {0 'SB' 0 0 'obac'}) ;

        % fail BF hard up at 70 seconds, and tell CLAW at 75 seconds
%         config.fail_surfs = vertcat(config.fail_surfs, {70 'BF' -10 -10 'trac'}) ;
%         config.fail_surfs = vertcat(config.fail_surfs, {75 'BF' -10 -10 'obac'}) ;
    case 5
        % use BAM
        set_vehicle_type('BAM') ;
        config.engage_time = 0.01 ;
        config.mode = modes.vel ;
%         config.mode = modes.pos ;
        config.use_NdEdh_pos = 1 ;
            
%         config.att_type_fw = [ 0 att_type.tiltcam ] ; config.fcase = 1 ; % vertical
        config.att_type_fw = [ 0 att_type.mba_bank ] ; config.fcase = 2 ; % horizontal
%         config.att_type_fw = [ 0 att_type.ypr_bank ] ; config.fcase = 2 ; % horizontal
        config.altitude_stop = -inf ;
        % uncomment to use tvc for pitch only
%         config.tvc_min = [-40 0] ;
%         config.tvc_max = [ 40 0] ;
        config.tsim_max = 50 ;
    case 6
        % use APGM
        set_vehicle_type('APGM') ;
        config.enable_homing_fw = [ 0 1 ] ;
        t_att = 15.64 ;
        t_pos = 24 ;
        config.mode_fw = [ 0 modes.direct ; t_att modes.att ; t_pos modes.pos ] ;
        config.att_type_fw = [ 0 att_type.mba_skid ] ;
        config.use_NdEdh_pos = 1 ;
        config.fcase = 3 ;
        config.pos_cmd_select = 1 ;
        config.pos_cmd_fw = [ 0 300 0 0 1000 ] ;
        config.att_cmd_select = 1 ;
        config.att_cmd_fw = [
            0        0     0     0 0
            t_att+2  0     0     0 0
            t_att+2  0 20*pi/180 0 0
            ] ;
        config.tsim_max = 60 ;
    case 7
        % use BDIMAV
        set_vehicle_type('BDIMAV') ;
        config.engage_time = 1 ;
        config.mode = modes.pos ;  % uncomment to use position mode
%         config.mode = modes.vel ;  % uncomment to use velocity mode
        config.pos_cmd_select = 1 ; % use pos_cmd_fw for position commands
        config.vel_cmd_select = 1 ; % use vel_cmd_fw for velocity commands
        config.att_type_fw = [ 0 att_type.tiltcam ] ;
        config.fcase = 1 ;
        config.altitude_stop = -inf ;
        config.use_wind_meas_sim = 1 ;
        config.show_surf_limits = 0 ;

        if(~exist('use_FC'))
            use_FC = false ;
        end
        if(use_FC)
           disp('Using Flow Control')
        else
           disp('Not using Flow Control')
           config.fail_surfs = {0 'FCMAG,FCDIR' 0 0 'obac'} ;
        end

        config.tsim_max = 150 ;
        
        % wind parameters
        config.use_steady = 1 ;
        config.use_gusts = 1 ;
        config.wind_heading = 0 ; % rad
        config.wind_steady = 30*get_value('knots2fps','constants') ; % ft/sec
        config.wind_sigma = 30*get_value('knots2fps','constants') ; % ft/sec
        config.wind_slope = 1/20 ; % 1/sec
        config.wind_start = 10 ; % sec
        
        % examples of position commands
        % rows of pos_cmd_fw are [t(sec) N(ft) E(ft) cam(rad) h(ft)]

        % hold hover at [N E cam h] = [0 0 0 40] until 50 seconds
        % command movement to [N E cam h] = [100 0 0 40] by 70 seconds
%         config.pos_cmd_fw = [ 0 0 0 0 40 ; 50 0 0 0 40 ; 70 100 0 0 40 ] ;

        % hold hover at [N E cam h] = [0 0 0 40] until 50 seconds
        % command movement to [N E cam h] = [0 0 0 60] by 70 seconds
%         config.pos_cmd_fw = [ 0 0 0 0 40 ; 50 0 0 0 40 ; 70 0 0 0 60 ] ;

        % example of velocity commands
        % rows of vel_cmd_fw are [t(sec) Nd(ft) Ed(ft) cam(rad) hd(ft)]
        
        % hold hover at [Nd Ed cam hd] = [0 0 0 0] until 50 seconds
        % command acceleration to [Nd Ed cam hd] = [20 0 0 0] by 70 seconds
%         config.vel_cmd_fw = [ 0 0 0 0 0 ; 50 0 0 0 0 ; 70 20 0 0 0 ] ;

        % Note: "cam" is the rotation angle around the propulsion axis, and
        % is fixed at zero for these examples.
    case 8
        % use GV
        set_vehicle_type('GV') ;
        
        % uncomment to use version of main_sim structure for GV autocode
%         config.sim_name = 'main_sim_GV' ;
        
        % uncomment to use S-function claw_main_GV
%         config.sim_name = 'main_sim_GV_clawsf' ; config.use_clawsf = 1 ;

        config.engage_time = 1 ;        
        config.command_time = 2 ;
        config.mode = modes.pos ;
        config.use_NdEdh_pos = 1 ;
        config.tsim_max = 20 ;
        config.wconf = 9 ;
        config.MACH_att_fb = 0.5 ; % used in turn rate feed forward
        
        % circle in NdEd, hold altitude
        do_circle = 1 ;
        if(do_circle && config.mode == modes.pos)
            config.pos_cmd_select = 1 ;
            h0 = 10000 ; % trim altitude
            vel = 487.2512 ; % trim velocity
            t0 = config.engage_time ;
            tf = t0 + 200 ;
            t_cmd = [t0:0.1:tf]' ;
            turn_rate = 2*pi/(tf - t0);
            config.tsim_max = tf ;
            config.pos_cmd_fw = [ t_cmd vel*cos(turn_rate*(t_cmd-t0)) ...
            vel*sin(turn_rate*(t_cmd-t0)) repmat([0 h0],length(t_cmd),1) ] ;
            clear vel h0 tf t_cmd turn_rate
        end
    
        config.att_type_fw = [ 0 att_type.mba_bank ] ; config.fcase = 1 ; % horizontal
        config.altitude_stop = -inf ;
        config.fail_surfs = {0 'eltab,dsb,flap,gear' 'set' 'cmd' 'obac'} ;

        config.ham_lib = fullfile('..','..','ham5release6','ham') ;
        
    case 10
        % uncomment sim_name to use FAST model
        % with discretized vehicle model lumped with CLAW
        config.sim_name = 'main_sim_lumped' ;

        % this is the FAST case that goes from launch to touchdown
        config.traj_name = 'launch_to_touchdown' ;

        % start of generic setup from config_case = 2
        
        set_vehicle_type('NGC4') ;
        config.engage_time = 0.01 ; % these are not trim conditions!
        config.mode = modes.vel ;
        config.weight = 'maxprop' ; % default weight is with max propellant (aka GLOW)
        config.fcase = 1 ; % pointed straight up on ground with zero velocity
        config.att_type_fw = [ 0 att_type.tiltcam; 50 att_type.mba_bank ] ;
        config.vel_cmd_select = 1 ; % default is to use a stored velocity profile
            
        config.fail_surfs = {0 'throt' 1 1 'obac'} ; % default throttle profile is full on

        config.use_throt = 3 ; % use individual engines instead of ganged
                
        config.throtdot_max = 10 ; 
        
        config.use_tvc = 1 ; % use ganged thrust vectoring
        
        config.rcs_cvddes_thresh = 2.58e-4 ; % half of smallest norm cvd achievable
        config.rcs_efficiency_thresh = 0.3 ;

        % end of generic setup from config_case = 2

        % engine failure code
        bad_engine = '' ; % no failure
%         bad_engine = 'throt1' ; % fail engine 1
%         bad_engine = 'throt2' ; % fail engine 2
        if(bad_engine)
            trac_engine_out = 40 ; % sec
            obac_engine_out = 45 ; % sec
            switch(bad_engine)
                case 'throt1'
                    good_engines = {'throt2' 'throt3'} ;
                case 'throt2'
                    good_engines = {'throt1' 'throt3'} ;
                case 'throt3'
                    good_engines = {'throt1' 'throt2'} ;
            end

            config.fail_surfs = vertcat(config.fail_surfs,{trac_engine_out bad_engine 0 0 'trac'}) ;
            config.fail_surfs = vertcat(config.fail_surfs,{obac_engine_out bad_engine 0 0 'obac'}) ;
            config.fail_surfs = vertcat(config.fail_surfs,{obac_engine_out good_engines{1} 1.4 1.4 'obac'}) ;
            config.fail_surfs = vertcat(config.fail_surfs,{obac_engine_out good_engines{2} 1.4 1.4 'obac'}) ;
        end

        % changes to original rocketback_combined added after start of Barron
        % TAEM trajectory integration (uncomment selectively to apply)
        
        % throttle is full on except for 2.5 seconds during simulated staging
        % (nominal engines only)
        if(isempty(bad_engine))
            config.fail_surfs = vertcat(config.fail_surfs,{
                137.7345 'throt' 0.6 0.6 'obac' ;
                140.2345 'throt' 1 1 'obac'
                }) ;
        end

        config.use_tvc = 3 ; % use individual thrust vectoring

        config.aero_surf_qbar_on = 5 ;
        config.aero_surf_qbar_off = 3 ;
        
        % start generic rocketback combined code

        config.att_cmd_select = 1 ;
        config.use_att_rate_cmd_fw = [ 0 0 ] ; % use (absolute) attitude commands
        
        % start in velocity mode, switch to attitude around the
        % time that qbar drops below 50 psf, switch back to
        % velocity after angle-of-attack command finishes ramping
        % from 50 deg (at 300 sec) to 15 deg (at 311+ sec)
        config.mode_fw = [ 0 modes.direct ; config.engage_time modes.vel ; 140 modes.att ; 312 modes.vel ] ;

        if(~exist('rocketback'))
            try
                rocketback = load('NGC_rocketback_combined') ;
            catch
                error('Failed to load NGC_rocketback_combined') ;
            end
        end
        config.load_stored_traj = 0 ;
        config.latlonh_IC = [ [34.92 -117.9]/constants.r2d 0 ] ; % use Edwards as origin
        config.latlonh_IC = [ [34.87598765573822 -117.61772185564041]/constants.r2d 0 ] ; % use alternate origin

        % combined tiltcam/rpy profile attitude command
        t_switch1 = 150 ;
        t_switch2 = 270 ;
        if(bad_engine)
            % special setting for engine out
            t_switch2 = 240 ;
        end

        tm_tiltcam = find(rocketback.t < t_switch1) ;
        tm_rpy = find(rocketback.t >= t_switch1 & rocketback.t < t_switch2) ;
        tm_mab = find(rocketback.t >= t_switch2) ;

        % set first switch time to first rpy point, and insert extra tiltcam point
        % to avoid interpolation issues
        t_switch1 = rocketback.t(tm_rpy(1)) ;

        % set second switch time to first mab point, and insert extra ypr point
        % to avoid interpolation issues
        t_switch2 = rocketback.t(tm_mab(1)) ;

        config.att_cmd_fw = [
            rocketback.t(tm_tiltcam) rocketback.tiltcam(tm_tiltcam,:)
            t_switch1 rocketback.tiltcam(tm_tiltcam(end),:)
            rocketback.t(tm_rpy) rocketback.rpy(tm_rpy,:)
            t_switch2 rocketback.rpy(tm_rpy(end),:)
            rocketback.t(tm_mab) rocketback.mab(tm_mab,:)
            ] ;

        config.att_type_fw = [ 0 att_type.tiltcam ; t_switch1 att_type.ypr_bank ; t_switch2 att_type.mba_bank ] ;

        % tack on throttle command
        config.att_cmd_fw = [ config.att_cmd_fw ones(size(config.att_cmd_fw,1),1) ] ;

        % individual att_type commands
        config.tiltcam_cmd_fw = [ rocketback.t rocketback.tiltcam ] ;
        config.rpy_cmd_fw = [ rocketback.t rocketback.rpy ] ;
        config.mab_cmd_fw = [ rocketback.t rocketback.mab ] ;
        
        vel_cmd_fw = [rocketback.t rocketback.NdEdhd ] ;
        vel_cmd_fw = vel_cmd_fw*[ 1 0 0 0 0 ; 0 1 0 0 0 ; 0 0 1 0 0 ; 0 0 0 0 1 ] ; % insert zero cam cmd in column 4
        config.vel_cmd_fw = vel_cmd_fw ;

        % rampin the discontinuity between attitude cmds and
        % velocity cmds
        config.vel_cmd_ramp_time = 10 ;

        % strip out bad time point at 165.0063
        config.att_cmd_fw = config.att_cmd_fw(abs(config.att_cmd_fw(:,1)-165.0063)>0.0001,:) ;
        config.vel_cmd_fw = config.vel_cmd_fw(abs(config.vel_cmd_fw(:,1)-165.0063)>0.0001,:) ;
        config.tiltcam_cmd_fw = config.tiltcam_cmd_fw(abs(config.tiltcam_cmd_fw(:,1)-165.0063)>0.0001,:) ;
        config.rpy_cmd_fw = config.rpy_cmd_fw(abs(config.rpy_cmd_fw(:,1)-165.0063)>0.0001,:) ;
        config.mab_cmd_fw = config.mab_cmd_fw(abs(config.mab_cmd_fw(:,1)-165.0063)>0.0001,:) ;

        % use bb controller during low qbar roll maneuver
        if(isempty(bad_engine))
            config.enable_bb_fw = [ 0 0 ; 183 1 ; 280 0 ] ; % stay in bb longer during low qbar
        else
            config.enable_bb_fw = [ 0 0 ; 185 1 ; 244 0 ] ;
        end
        
        % send aero surfs to zero during period of low qbar
        if(~isfield(config,'aero_surf_qbar_off'))
            if(isempty(bad_engine))
                config.fail_surfs = vertcat(config.fail_surfs, {157 'allaero' 0 0 'obac' ; 293 'allaero' 'min' 'max' 'obac'}) ;
            else
                config.fail_surfs = vertcat(config.fail_surfs, {160 'allaero' 0 0 'obac' ; 224 'allaero' 'min' 'max' 'obac'}) ;
            end
        end
        
        % add 5 second pad around enable_bb for no integrator gain set
        if(isempty(bad_engine))
            config.gain_set_fw = [ 0 0 ; 178 1 ; 285 0 ] ;
        else
            config.gain_set_fw = [ 0 0 ; 180 1 ; 249 0  ] ;
        end

        % end of generic rocketback combined code
        
        % miscellaneous test code fragments
%         config.gain_set = 0 ; % load just gain_set = 0 (nominal config)
%         config.gain_set = 1 ; % load just gain_set = 1 (bangbang config, no att/rate integ)
%         config.gain_set = [] ; % load all gain sets

        % use gain_set = value of enable_bb
        % Note: if only one gain_set is loaded, this will have no
        % effect (the single/default gain set will be used throughout)
%         config.gain_set_fw = [ 0 -1 ] ;

        % do "1st attempt" with gain set locked at bang-bang values
        % throughout
%         config.gain_set_fw = [ 0 1 ] ;

        % test failure of speed brake during low qbar
%         config.fail_surfs = vertcat(config.fail_surfs, { 200 'SB' -20 -20 'obac' ; 250 'SB' 'min' 'max' 'obac' }) ;

        % SGP exper --- force tvc_m onto upper limit during
        % time that it wants to be there anyway.  This somewhat
        % magically allows SMN to find a solution with cvdex =
        % 0, when before it could not (and the daisy chain
        % caused RCS to try to remove the residual).
%         config.fail_surfs = vertcat(config.fail_surfs,{
%             30 'tvc_m' 12.5 12.5 'obac' ;
%             50 'tvc_m' -12.5 12.5 'obac' ;
%         }) ;
        
        % TAEM specific modifications to rocketback_combined follow

        switch bad_engine
            case ''
                t_taem_sw = 375 ; % nominal rocketback
%                 t_taem_sw = 380 ; % + simulated traj computation delay
            case 'throt1'
                t_taem_sw = 260 ; % engine 1 out
            case 'throt2'
                t_taem_sw = 270 ; % engine 2 out
            case 'throt3'
                t_taem_sw = 270 ; % engine 3 out (BUT this case has not been run, assume timing for engine 2 out would work)
        end

        if(t_taem_sw >= 312)
            % next line is documented in 090512 6dof launch to touchdown.ppt
            config.mode_fw = [ 0 modes.direct ; config.engage_time modes.vel ; 140 modes.att ; 312 modes.vel ; t_taem_sw modes.pos ] ;
        else
            % next line is documented in 090512 6dof launch to touchdown with engine 1 out.ppt 
            % and 0905136dof launch to touchdown with engine 2 out.ppt
            config.mode_fw = [ 0 modes.direct ; config.engage_time modes.vel ; 140 modes.att ; t_taem_sw modes.pos ] ; % engine 1 or 2 out
        end

        % add 5 sec pad after changing to pos mode before changing to
        % new gain set with feed forward gains employed for TAEM, sgs, al
        config.gain_set_fw = [ config.gain_set_fw ; t_taem_sw+5 2 ] ;
            
        % uncomment following two lines for on-the-fly trajectory replan
%         config.assertion_time = t_taem_sw - get_value('dt') ;
%         config.HACcase = 0;

        if(~isfield(config,'HACcase'))
            
            % Note: any of the old stored TAEM trajectories may require
            % reverting other parameters to work properly

            switch(bad_engine)
                case '' % nominal rocketback
                    config.BAI_version = 5 ;
                    config.HACcase = '091013rt_baseline' ;
                    
                    % documented in 0905126dof launch to touchdown.ppt
%                     config.BAI_version = 3 ;
%                     config.HACcase = '090512ref_trajectory' ;

                case 'throt1' % engine 1 out
                    config.BAI_version = 4 ;
                    config.HACcase = '090717E1_rt_260' ;
                case 'throt2' % engine 2 out
                    config.BAI_version = 4 ;
                    config.HACcase = '090717E2_rt_270' ;
                otherwise
                    error('we are not set up to run bad_engine = %s', bad_engine)
            end
        end
        
        config.pos_cmd_select = 1 ; % use stored Barron Associates position trajectory

        config.use_eow_as_iv = 1 ;
        
        config.use_pos_fltpath_lim = 1 ;
        config.pos_fltpath_u_ulim = [ 0 100 100 ] ;
        config.pos_u_ulim = [ 2e3 2e3 1e3 ] ;

        config.att_min.mba_bank = [ -75*pi/180 5*pi/180 ] ; % [ bank alpha ] % 5 deg minimum alpha
%         config.att_min.mba_bank = [ -75*pi/180 2*pi/180 ] ; % [ bank alpha ] % 2 deg minimum alpha
        config.att_max.mba_bank = [ 75*pi/180 0.35 ] ; % [ bank alpha ]

%         config.tsim_max = t_taem_sw + pos_cmd_fw(end,1) + 100 ; % padded with 100 sec so landing occurs for nominal
        config.tsim_max = 1000 ; % hardwire so not dependent on running setup_taem_sgs_al
        config.altitude_stop = 2299 ; % since launch at 2300 and land at 2302 feet
        config.plot_landing = 1 ;

        % modifications to actuator properties to use actuators with hinge moments
        config.use_hm_actuators = 1 ;
        if(config.use_hm_actuators)
            switch(get_value('sim_name'))
                case 'main_sim_lumped'
                    config.SERVO.servo_type = 'models/hinge moment discrete actuator model' ;
                otherwise
                    config.SERVO.servo_type = 'models/hinge moment actuator model' ;
            end
        else
            switch(get_value('sim_name'))
                case 'main_sim_lumped'
                    config.SERVO.servo_type = 'variable rate limit discrete servo model' ;
                otherwise
                    config.SERVO.servo_type = 'variable rate limit servo model' ;
            end
        end
        
        % simulate float of RIE, followed by test signal
        if(0)
            % set torque limits on RIE to zero at 350 seconds
            config.fail_surfs = vertcat(config.fail_surfs,{350 'RIE torque' 0 0 'trac'}) ;

            % set RIE limits back to nominal at 360
            config.fail_surfs = vertcat(config.fail_surfs,{360 'RIE' 'set' 'spec' 'obac'});

            % set RIE preferred value to 10 at 360
            config.fail_surfs = vertcat(config.fail_surfs,{360 'RIE' 'pref' 10 'obac'});

            % set RIE preferred value to full_surf_cmd value at 360, and raise
            % pref wght to 1000
            config.fail_surfs = vertcat(config.fail_surfs,{360 'RIE' 'pref' 'cmd' 'obac'});
            config.fail_surfs = vertcat(config.fail_surfs,{360 'RIE' 'pref_wght' 1000 'obac'});

            % return RIE to nominal preference values at 365
            config.fail_surfs = vertcat(config.fail_surfs,{365 'RIE' 'pref' 0 'obac'});
            config.fail_surfs = vertcat(config.fail_surfs,{365 'RIE' 'pref_wght' 1 'obac'});

            % lock RIE position limits (and thus command) to measured RIE position at 370 seconds
            config.fail_surfs = vertcat(config.fail_surfs,{370 'RIE' 'set' 'meas' 'obac'}) ;
        end
       
        % set body flap preference to 10 deg, ignoring schedule
%         config.fail_surfs = vertcat(config.fail_surfs,{680 'BF' 'pref' 10 'obac'});
%         config.fail_surfs = vertcat(config.fail_surfs,{680 'BF' 'pref_wght' 1000 'obac'});
%         config.use_preference_schedule_fw = [ 0 1 ; 680 0 ] ;
        
        % set speed brake preference to -15
%         config.fail_surfs = vertcat(config.fail_surfs,{680 'SB' 'pref' -15 'obac'});
%         config.fail_surfs = vertcat(config.fail_surfs,{680 'SB' 'pref_wght' 1000 'obac'});

        % uncomment to set actuator bandwidth to 50 (instead of 100) rad/sec
        config.SERVO.w = 50 ; 

        % turn on steady winds
        if(0)
            config.wind_heading = (58 + 180)/constants.r2d ;
            config.wind_slope = 0.1 ;
            config.wind_steady = 10*constants.knots2fps ; % 10 knots
            config.use_steady = 1 ;
        end
        
        % turn on wind gusts
        if(0)
            config.wind_slope = 0.1 ;
            config.wind_sigma = 6 ; % 6 ft/sec
            config.use_gusts = 1 ;
        end
        
        config.MACH_att_fb = 0.5 ;
        
        % uncomment to use auto selection of att_type
        config.use_auto_att_type = 1 ;

    otherwise
        error('config_case = %d is not defined') ;
end

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

% uncomment to fix aero environment (rho, sos, ...) at values for initial altitude
% config.use_held_aero_obac = [0 1] ;

try
    % choose OBAC model and initialize CLAW
    setup_claw

    % choose TRAC model and initialize sim
    setup_sim
    
    % set links to proper models
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

disp(sprintf('sim_name = %s',sim_name))
eval(sim_name)
commandwindow

% Summary of config struct variables:
%
% config.aero_file (set_aero_params.m)
%   define which .mat file to use for aero tables and other aero data
%
% config.altitude_stop (setup_sim.m, main_sim/Stop Sim on Crash)
%   stop sim if altitude goes below this value (default -Inf)
%
% config.angular_rate_stop (setup_sim.m, main_sim/Stop Sim on Crash)
%   stop sim if angular rate goes above this value (default 2)
%
% config.att_cmd_fw (setup_claw.m, main_sim/Inputs/inputs/att cmd select)
%   workspace variable defining attitude cmd input when att_cmd_select == 1
%
% config.att_cmd_select (main_sim/Inputs/inputs)
%   source of attitude command input
%
% config.att_type_fw (setup_claw.m, main_sim/Inputs/inputs)
%   attitude type profile using elements of att_type struct)
%
% config.BF_schedule (setup_claw.m, ../MISC/mkplt.m,
%      main_sim/claw_main/rate_loops/set rate loop params/preference schedule)
%   filename (including .mat extension) of file containing body flap
%   schedule and trimmability info (loaded into MACH.BF_schedule struct)
%
% config.command_time (setup_sim.m, main_sim/Inputs/inputs)
%   time for step command changes (defaults to 'engage_time + 2')
%
% config.dt (setup_claw.m)
%   CLAW sample rate
%
% config.dtsim (setup_sim.m)
%   simulation sample rate
%
% config.enable_bb_fw (setup_sim.m, main_sim/Inputs)
%   logical variable profile to enable bang-bang control in rate loop
%
% config.enable_homing_fw (setup_sim.m, main_sim/Inputs)
%   logical variable profile to enable homing (proportional nav) control
%   in rate loop
%
% config.energy_stop (setup_sim.m, main_sim/Stop Sim on Crash)
%   stop sim if energy goes below this value (default -Inf)
%
% config.engage_time (setup_sim.m, main_sim/Inputs/inputs)
%   time to change from modes.direct to 'mode'
%
% config.fail_surfs (setup_sim.m)
%   specification of surface failures (including forced values)
%
% config.fcase (setup_trim.m)
%   trim case selection
%
% config.gain_set (setup_claw.m)
%   specifies which gain sets to include in the gain matrix gain_mat.
%   If value is empty, all gain_sets (assumed to be contiguous,
%   starting at zero!) are included, and may be selected at runtime using
%   gain_set_fw.  Otherwise, a single specified gain set becomes
%   the fixed gain set.
%
% config.gain_set_fw (setup_claw.m, main_sim/claw_main/input processing)
%   specifies which gain_set to use as a function of time.  Values larger
%   the largest valid gain_set value will use the largest.  Values less
%   than zero will select the gain set (0 or 1) specified by the current
%   value of enable_bb
%   
% config.mode (setup_sim.m, main_sim/Inputs/inputs
%   mode initial value using element of modes struct
%
% config.mode_fw (setup_sim.m, main_sim/Inputs/inputs
%   mode profile using elements from modes struct
%
% config.pos_cmd_fw (setup_claw.m, main_sim/Inputs/inputs/pos cmd select)
%   workspace variable defining position cmd input when pos_cmd_select == 1
%
% config.pos_cmd_select (setup_sim.m, main_sim/Inputs/inputs)
%   source of position command input
%
% config.rcs_cvddes_thresh (main_sim/claw_main/rate_loops/allocation/RCS allocation)
%   deadband threshold on rate loop cvddes (after aero allocation)
%   for use of RCS jets
%
% config.rcs_efficiency_thresh (setup_claw.m)
%   efficiency threshold below which rcs combinations will not be used
%
% config.rcs_select (set_vehicle_params.m)
%   select subset of available RCS jets
%
% config.throt_max (setup_claw.m)
%   maximum value of throttle command by velocity loop (see use_throt)
%
% config.throt_min (setup_claw.m)
%   minimum value of throttle command by velocity loop (see use_throt)
%
% config.traj_name (doit.m)
%   name of variable that contains velocity commands used to set vel_cmd_fw
%
% config.tsim_max (setup_sim.m)
%   duration of simulation
%
% config.tvc_max (setup_claw.m)
%   minimal angles for thrust vector angles [delta_m delta_n]
%
% config.tvc_min (setup_claw.m)
%   maximum angles for thrust vector angles [delta_m delta_n]
%
% config.use_full_surf_cmd (setup_sim.m, main_sim/Inputs)
%   use full surface commands instead of pseudo commands if true
%
% config.use_held_aero_obac (setup_claw.m)
% config.use_held_aero_trac (setup_sim.m)
%   workspace variables defining time varying boolean value
%   0 = update aero environment continuously, 1 = hold last value
%   if trac is not set, it defaults to obac value
%
% config.use_NdEdh_pos (setup_claw.m, main_sim/Inputs/ideal responses/ideal pos vel response/get posvel cmd)
%   true if pos mode commands are NdEdh instead of (the usual) NEh
%
% config.use_throt (mkplt.m)
%   1 = this vehicle has a throttle input
%   0 = this vehicle has a throttle input (or don't use it)
%   use_throt == 0 => throt_min = 0; throt_max = 0
%
% config.use_tvc (setup_claw.m)
%   0 = do not use thrust vectoring, 1 = use thrust vectoring
%
% config.use_variable_mass (setup_claw.m, main_sim/claw_main/set scoped
% signals, main_sim/vehicle_model/set scoped signals)
%   adjust variable mass properties based on integrated fuel flow rate if
%   true
%   
% config.vcase (setup_mass_properties.m)
%   (Note: the variable config.weight is now the preferred way to set
%   vehicle mass properties)  Set mass properties corresponding to:
%   1 = GLOW, 2 = landing weight, 3 = landing weight with CG at aero reference center
%
% config.vehicle_type (setup_claw.m)
%   string which identifies the type of vehicle
%
% config.vel_cmd_fw (setup_claw.m, main_sim/Inputs/inputs/vel cmd select)
%   workspace variable defining velocity cmd input when vel_cmd_select == 1
%
% config.vel_cmd_select (setup_sim.m, main_sim/Inputs/inputs)
%   source of velocity command input
%
% config.weight (set_vehicle_params.m)
%   the initial weight of the vehicle in pounds, or the string 'maxprop'
%   (weight with max propellant) or 'noprop' (weight with min propellant)
