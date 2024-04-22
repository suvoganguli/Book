function full_surf_limits_fw = get_full_surf_limits(full_surf_limits_fw, full_surf_limits, fail_surfs)

global MACH

if(size(fail_surfs,2) ~= 5)
    error('get_full_surf_limits: fail_surfs must be a cell array with 5 columns') ;
end

limit_types = {'lim', 'rlim', 'tlim'} ;

% start with nominal limits
if(isempty(full_surf_limits_fw))
    for i = 1:length(limit_types)
        limit_type = limit_types{i} ;
        if(~strcmp(limit_type,'tlim'))
            full_surf_limits_fw.obac.(['u' limit_type]) = [ 0 full_surf_limits.obac.(['u' limit_type]) ] ;
            full_surf_limits_fw.obac.(['l' limit_type]) = [ 0 full_surf_limits.obac.(['l' limit_type]) ] ;
        end
        full_surf_limits_fw.trac.(['u' limit_type]) = [ 0 full_surf_limits.trac.(['u' limit_type]) ] ;
        full_surf_limits_fw.trac.(['l' limit_type]) = [ 0 full_surf_limits.trac.(['l' limit_type]) ] ;
    end
end

full_surf_limits_fw.obac.lock = zeros(1,MACH.num_u+1) ;

% specify surface failures as cell array rows of the form:
% {time idx llim ulim model_use_type}
% model_use_type == 'both' may be used to specify simultaneous failure

% if no additional failures are specified, return the input (or
% initialized) struct
if(~size(fail_surfs,1))
    return
end

for i = 1:length(limit_types)
    limit_type = limit_types{i} ;
    if(~strcmp(limit_type,'tlim'))
        fail_times.(['obac_' limit_type]) = full_surf_limits_fw.obac.(['l' limit_type])(:,1) ;
    end
    fail_times.(['trac_' limit_type]) = full_surf_limits_fw.trac.(['l' limit_type])(:,1) ;
end
fail_times.obac_lock = full_surf_limits_fw.obac.lock(:,1) ;

% sort fail_surfs so that times are processed in the correct order
[ttmp, tidx] = sort(cell2mat(fail_surfs(:,1))) ;
fail_surfs = fail_surfs(tidx,:) ;

for ifail = 1:size(fail_surfs,1)
    fail_surf = fail_surfs(ifail,:) ;
    fail_time = fail_surf{1} ;
    fail_idx = fail_surf{2} ;
    fail_llim = fail_surf{3} ;
    fail_ulim = fail_surf{4} ;
    fail_models = fail_surf(5) ;
    
    limit_type = 'lim' ;
    switch(fail_llim)
        case {'set', 'lock'}
            switch(fail_ulim)
                case 'cmd'
                    fail_llim = 1 ;
                    limit_type = 'lock' ;
                case 'meas'
                    fail_llim = 2 ;
                    limit_type = 'lock' ;
                otherwise
                    fail_llim = fail_ulim ;
            end
            if(strcmp(limit_type,'lock') && ~isempty(setdiff(fail_models,'obac')))
                error('%s to ''cmd'' or ''meas'' is only available with obac model', fail_ulim) ;
            end
        case 'sym'
            fail_ulim = abs(fail_ulim) ;
            fail_llim = -fail_ulim ;
    end
    
    if(ischar(fail_idx))
        if(~strcmp(limit_type,'lock'))
            [fail_idx, limit_type] = strtok(fail_idx) ;
            limit_type = strtok(limit_type) ;
            switch(limit_type)
                case {'torque', 'tlim'}
                    limit_type = 'tlim' ;
                case {'rate', 'rlim'}
                    limit_type = 'rlim' ;
                case {'', 'lim'}
                    limit_type = 'lim' ;
                otherwise
                    error('bad limit type (%s) in definition of fail_surfs', limit_type) ;
            end
            if(strcmp(limit_type,'tlim') && ~isempty(setdiff(fail_models,'trac')))
                error('torque limit is only available with trac model') ;
            end
        end
        
        switch(fail_idx)
            case {'all'}
                fail_idx = 1:MACH.num_u ;
            case {'allaero', 'aero'}
                fail_idx = MACH.vane_idx ;
            case {'alltvc', 'tvc'}
                fail_idx = MACH.tvc_idx ;
            case {'allrcs', 'rcs'}
                fail_idx = MACH.rcs_idx ;
            case {'allthrot', 'throt'}
                fail_idx = MACH.throttle_idx ;
            otherwise
                tmp_names = textscan(fail_idx,'%s','delimiter',',') ;
                tmp_names = tmp_names{1} ;
                [tf,fail_idx] = ismember(tmp_names, MACH.u_names) ;
                if(~all(tf))
                    disp('bad surface name in definition of fail_surfs:') ;
                    disp(tmp_names(~tf))
                    error(' ')
                end
        end
    else
        if(any(fail_idx < 1) || any(fail_idx > MACH.num_u))
            error('bad surface index (%d) in definition of fail_surfs', fail_idx) ;
        end
    end
    
    switch(limit_type)
        case 'lock'
            lower_lim = 'lock' ;
            upper_lim = '' ;
        otherwise
            lower_lim = ['l' limit_type] ;
            upper_lim = ['u' limit_type] ;
    end

    if(strcmp(fail_models{1},'both'))
        fail_models = {'trac', 'obac'} ;
    end
    
    for imodel = 1:length(fail_models)
        fail_model = fail_models{imodel} ;
        fail_times_model = fail_times.([fail_model '_' limit_type]) ;
        idx = max(find(fail_time >= fail_times_model)) ;
        
        % add a row for this time, if necessary, copying the values for the
        % most recent time
        if(fail_time ~= fail_times_model(idx))
            idx_all = sort([1:length(fail_times_model) idx]) ;
            idx = idx + 1 ;
            fail_times.([fail_model '_' limit_type])(idx) = fail_time ;
            
            full_surf_limits_fw.(fail_model).(lower_lim) = full_surf_limits_fw.(fail_model).(lower_lim)(idx_all,:) ;
            full_surf_limits_fw.(fail_model).(lower_lim)(idx,1) = fail_time ;
            
            if(~isempty(upper_lim))
                full_surf_limits_fw.(fail_model).(upper_lim) = full_surf_limits_fw.(fail_model).(upper_lim)(idx_all,:) ;
                full_surf_limits_fw.(fail_model).(upper_lim)(idx,1) = fail_time ;
            end
        end

        switch(fail_llim)
            case {'min', 'llim'}
                tmp_llim = full_surf_limits.(fail_model).(lower_lim)(fail_idx) ;
            case {'max', 'ulim'}
                tmp_llim = full_surf_limits.(fail_model).(upper_lim)(fail_idx) ;
            otherwise
                tmp_llim = fail_llim ;
        end
        if(~isnan(fail_llim))
            full_surf_limits_fw.(fail_model).(lower_lim)(idx,fail_idx+1) = tmp_llim ;
        end

        if(isempty(upper_lim))
            continue ;
        end
        
        switch(fail_ulim)
            case {'min', 'llim'}
                tmp_ulim = full_surf_limits.(fail_model).(lower_lim)(fail_idx) ;
            case {'max', 'ulim'}
                tmp_ulim = full_surf_limits.(fail_model).(upper_lim)(fail_idx) ;
            otherwise
                tmp_ulim = fail_ulim ;
        end
        if(~isnan(fail_ulim))
            full_surf_limits_fw.(fail_model).(upper_lim)(idx,fail_idx+1) = tmp_ulim ;
        end
    end
end
