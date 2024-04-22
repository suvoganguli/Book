% part_doit_GTM

use_shortcut = 1;

if use_shortcut % This bypasses full calls to setup_claw and setup_sim
    
    % ================================================
    % Hacked original code
    mode = get_value('mode');
    engage_time = get_value('engage_time');
    mode_fw = [ 0 modes.direct ; engage_time mode ] ;  % overwrite mode_fw (only this is used by sim)
    tsim_max = get_value('tsim_max') ;
    use_NdEdh_pos = get_value('use_NdEdh_pos');
    fail_surfs = get_value('fail_surfs');    
        
    % ================================================
    % From setup_claw (L550-552)
    if(use_NdEdh_pos)
        % use NdEdh cmd instead of NEh cmd in pos mode
        MACH.select_cmd_array([10 11 14 15],5) = [1 1 0 0] ;
    end
    
    % ================================================
    % From setup_sim (L156-157)
    full_surf_limits_fw = get_full_surf_params([], full_surf_params, fail_surfs) ;
    
    % ================================================
    % Copy-paste of setup_sim (L209-L246)
    
    % parameters for rate cmd select
    rate_cmd_select = get_value('rate_cmd_select') ;
    rate_cmd_fw = get_value('rate_cmd_fw','onerror',[0 pqr_trim_IC' throttle_trim_IC(1)']) ;
    
    % default canned att_type sequence
    att_type_fw = get_value('att_type_fw','onerror',[0 MACH.att_type]) ;
    
    % parameters for att cmd select
    att_cmd_select = get_value('att_cmd_select') ;
    att_cmd_fw = get_value('att_cmd_fw','onerror',[0 att_trim_IC' throttle_trim_IC(1)']) ;
    
    % parameters for vel cmd select
    vel_cmd_select = get_value('vel_cmd_select') ;
    vel_cmd_fw = get_value('vel_cmd_fw','onerror',[0 Nd_trim_IC Ed_trim_IC att_trim_IC(3) hd_trim_IC]) ;
    
    % set ideal gain parameter required by pos_cmd_select = 2 (ramp pos cmd)
    ideal_vel_Kb = MACH_vel_Kb(1) ;
    
    setup_landing_profile
    setup_wind
    setup_homing
    
    if(get_value('enable_ideal'))
        setup_ideal
    end
    
    assertion_time = get_value('assertion_time') ;
    HACcase = [] ;
    setup_taem_sgs_al
    
    % parameters for pos cmd select
    % Note: pos_cmd_select must be done after setup_taem_sgs_al, which may set
    % a value for pos_cmd_fw
    pos_cmd_select = get_value('pos_cmd_select') ;
    if(use_NdEdh_pos)
        pos_cmd_fw = get_value('pos_cmd_fw','onerror',[0 Nd_trim_IC Ed_trim_IC att_trim_IC(3) h_trim_IC]) ;
    else
        pos_cmd_fw = get_value('pos_cmd_fw','onerror',[0 N_trim_IC E_trim_IC att_trim_IC(3) h_trim_IC]) ;
    end
    
    % ================================================
    
else % This re-runs setup_claw and setup_sim
    
    % ================================================
    % Hacked original code
    set_vehicle_type('GTM') ; % config.model_name needs to be defined
    
    % ================================================
    % Code below is a copy-paste of doit_GTM (approx. L69-141)
    
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
                case modes.att
                    [cmd_nr, cmd_nc] = size(config.att_cmd_fw); % rows, cols
                    config.att_cmd_fw(1:cmd_nr,5) = ...
                        ones(cmd_nr,1)*obac_params.u_trim(obac_params.throttle_idx);  % add trim throttle
                    
                case {3,4}
                    % keyboard
            end
        end
        
        % ------------------------------------------
        
        % choose TRAC model and initialize sim
        setup_sim
        
        % ------------------------------------------
        
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
    
    % ================================================
    
end % end if