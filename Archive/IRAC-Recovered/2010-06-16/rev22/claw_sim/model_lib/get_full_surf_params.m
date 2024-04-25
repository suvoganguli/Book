function full_surf_params_fw = get_full_surf_params(full_surf_params_fw, full_surf_params, fail_surfs)

global MACH

if(~isempty(fail_surfs) && size(fail_surfs,2) ~= 5)
    error('get_full_surf_params: fail_surfs must be a cell array with 5 columns') ;
end

limit_types = {'lim', 'rlim', 'tlim'} ;
pref_types = {'pref', 'pref_wght'} ;
fail_models = {'trac', 'obac'};

% start with nominal params
if(isempty(full_surf_params_fw))
    for imodel = 1:length(fail_models);
        fail_model = fail_models{imodel};
        model_fields = fieldnames(full_surf_params.(fail_model));
        for i = 1:length(model_fields)
            fieldname = model_fields{i};
            full_surf_params_fw.(fail_model).(fieldname) = [ 0 full_surf_params.(fail_model).(fieldname) ] ;
        end
    end
end

full_surf_params_fw.obac.limit_select = [ 0 zeros(1,MACH.num_u) ] ;

use_preference_schedule = 0 ;

% following lines are an alternate to the current implementation for
% turning on preference schedule
% use_preference_schedule = get_value('use_preference_schedule') ;

full_surf_params_fw.obac.pref_select = [ 0 repmat(use_preference_schedule,1,MACH.num_u) ] ;

% specify surface failures as cell array rows of the form:
% {time idx llim ulim model_use_type}
% model_use_type == 'both' may be used to specify simultaneous failure

% if no additional failures are specified, return the input (or
% initialized) struct
if(~size(fail_surfs,1))
    return
end

% initialize the fail_times struct, which keeps track of transition times for
% each signal
for imodel = 1:length(fail_models);
    fail_model = fail_models{imodel};
    model_fields = fieldnames(full_surf_params_fw.(fail_model));
    for i = 1:length(model_fields)
        fieldname = model_fields{i};
        fail_times.(fail_model).(fieldname) = full_surf_params_fw.(fail_model).(fieldname)(:,1) ;
    end
end

% sort fail_surfs so that times are processed in the correct order
[ttmp, tidx] = sort(cell2mat(fail_surfs(:,1))) ;
fail_surfs = fail_surfs(tidx,:) ;

for ifail = 1:size(fail_surfs,1)
    fail_surf = fail_surfs(ifail,:) ;
    fail_time = fail_surf{1} ;
    fail_idx = fail_surf{2} ;
    fail_arg1 = fail_surf{3} ;
    fail_arg2 = fail_surf{4} ;
    fail_models = fail_surf(5) ;
    
    default_limit_type = 'lim' ;
    limit_type = '' ;
    limit_select = 0 ;
    pref_type = '' ;
    pref_select = 0 ;
    switch(fail_arg1)
        case {'set', 'limit_select'}
            limit_select = nan ;
            switch(fail_arg2)
                case 'spec'
                    limit_select = 0 ;
                case 'cmd'
                    limit_select = 1 ;
                case 'meas'
                    limit_select = 2 ;
            end

            if(isnan(limit_select))
                % old style default is specified limits
                % copy upper limit to lower limit
                limit_select = 0 ;
                fail_arg1 = fail_arg2 ;
            else
                if(~isempty(setdiff(fail_models,'obac')))
                    error('%s to ''spec'', ''cmd'', or ''meas'' is only available with obac model', fail_arg1) ;
                end
                limit_type = 'limit_select' ;
            end

        case 'sym'
            if(~isnumeric)
                error('''sym'' is only allowed with numeric argument') ;
            end
            fail_arg2 = abs(fail_arg2) ;
            fail_arg1 = -fail_arg2 ;
        case 'pref_select'
            if(~isempty(setdiff(fail_models,'obac')))
                error('pref_select is only available with obac model') ;
            end
            
            switch(fail_arg2)
                case 'spec'
                    pref_select = 0 ;
                case 'schedule'
                    pref_select = 1 ;
                case 'cmd'
                    pref_select = 2 ;
                otherwise
                    error('unknown pref_select: %s', fail_arg2)
            end
            
            pref_type = 'pref_select' ;
            default_limit_type = '' ;
        otherwise
            % if fail_arg1 is char and looks like a lower or upper form of
            % a generic limit_type, assume single limit assignment
            if(ischar(fail_arg1))
                if(ismember(fail_arg1(1),{'l','u'}) && ismember(fail_arg1(2:end),limit_types))
                    limit_type = fail_arg1 ;
                elseif(ismember(fail_arg1,pref_types))
                    pref_type = fail_arg1 ;
                end
            end
    end
    
    if(ischar(fail_idx))
        if(isempty(limit_type))
            [fail_idx, limit_type] = strtok(fail_idx) ;
            limit_type = strtok(limit_type) ;
            switch(limit_type)
                case {'torque', 'tlim'}
                    limit_type = 'tlim' ;
                case {'rate', 'rlim'}
                    limit_type = 'rlim' ;
                case {'', 'lim'}
                    limit_type = default_limit_type ;
                otherwise
                    error('bad limit type (%s) in definition of fail_surfs', limit_type) ;
            end
            
            if(~isempty(limit_type) && isempty(default_limit_type))
                error('limit_type modifier (%s) used in a non-limit definition', limit_type) ;
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
        % handle old style numeric spec
        if(any(fail_idx < 1) || any(fail_idx > MACH.num_u))
            error('bad surface index (%d) in definition of fail_surfs', fail_idx) ;
        end
        
        limit_type = default_limit_type ;
    end
    
    switch(limit_type)
        case ''
            % if empty, this isn't a limit case
        case 'limit_select'
            % for 'spec', 'cmd', or 'meas', all we have to do is set limit_select
            fail_keys = {'limit_select'} ;
            fail_values = {limit_select} ;
        case limit_types
            % specify limits for combined lower/upper limit case,
            % and set limit_select to 'spec'
            fail_keys = {'limit_select' ['l' limit_type] ['u' limit_type]} ;
            fail_values = {limit_select fail_arg1 fail_arg2} ;
        otherwise
            % specify a single limit, and set limit_select to 'spec'
            % Note: unspecified limit will revert to last specified value
            % (after a possible setting to 'cmd' or 'meas'), in the same
            % manner as a 'nan' specification
            fail_keys = {'limit_select' limit_type} ;
            fail_values = {limit_select fail_arg2} ;
            limit_type = limit_type(2:end) ; % make limit_type generic
    end
    
    switch(pref_type)
        case ''
            % if empty, this isn't a pref case
        case 'pref_select'
            % for 'spec', 'schedule', or 'cmd', all we have to do is set pref_select
            fail_keys = {'pref_select'} ;
            fail_values = {pref_select} ;
        case 'pref'
            % specify a preference for an effector, and set pref_select to
            % 'spec'
            fail_keys = {'pref_select' 'pref'} ;
            fail_values = {pref_select fail_arg2} ;
        case 'pref_wght'
            % specify a preference weighting for an effector
            fail_keys = {'pref_wght'} ;
            fail_values = {fail_arg2} ; 
    end

    if(strcmp(fail_models{1},'both'))
        fail_models = {'trac', 'obac'} ;
    end
    
    for imodel = 1:length(fail_models)
        fail_model = fail_models{imodel} ;
        for ikey = 1:length(fail_keys)
            fail_value = fail_values{ikey} ;
            if(isnan(fail_value))
                % no need to process this key
                continue
            end
            
            fail_key = fail_keys{ikey} ;
            if(isfield(fail_times.(fail_model),fail_key))
                fail_times_model = fail_times.(fail_model).(fail_key) ;
            else
                % skip this assignment, because it is not applicable
                % (like 'limit_select' for the trac model)
                continue
            end
            
            idx = max(find(fail_time >= fail_times_model)) ;

            % add a row for this time, if necessary, copying the values for the
            % most recent time
            if(fail_time ~= fail_times_model(idx))
                idx_all = sort([1:length(fail_times_model) idx]) ;
                idx = idx + 1 ;
                fail_times.(fail_model).(fail_key)(idx) = fail_time ;

                full_surf_params_fw.(fail_model).(fail_key) = full_surf_params_fw.(fail_model).(fail_key)(idx_all,:) ;
                full_surf_params_fw.(fail_model).(fail_key)(idx,1) = fail_time ;
            end

            switch(fail_value)
                case {'min', 'llim'}
                    fail_value = full_surf_params.(fail_model).(['l' limit_type])(fail_idx) ;
                case {'max', 'ulim'}
                    fail_value = full_surf_params.(fail_model).(['u' limit_type])(fail_idx) ;
                otherwise
                    if(ischar(fail_value))
                        error('unexpected char value (''%s'') specified', fail_value) ;
                    end
            end
            if(~isnan(fail_value))
                full_surf_params_fw.(fail_model).(fail_key)(idx,fail_idx+1) = fail_value;
            end
        end
    end
end
