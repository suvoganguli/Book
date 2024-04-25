function outs = get_value(varargin)

global config vehicle_def MACH_def MACH constants

priority_list = {'config', 'vehicle_def', 'MACH_def', 'constants'};
all_context_list = horzcat(priority_list, 'base', 'caller', 'MACH');
struct_list = setdiff(all_context_list, {'caller', 'base'});

varnames = {};
if(nargin >= 1)
    varnames = varargin{1};
    if(isempty(varnames))
        % exclude empty arrays
    elseif(ischar(varnames))
        varnames = {varnames};
        dolist = 0;
    elseif(iscellstr(varnames))
        dolist = 1;
    else
        varnames = {};
    end
end

if(isempty(varnames))
    error('get_value requires at least one argument of type char or cellstr')
end

request_list = varargin(2:end);

context_list = {};

states.init = 0;
states.append = 1;
states.insert = 2;
states.exclude = 3;

onerror = 0;
showall = 0;
exclude = 0;
reverse = 0;
all_context = 0;
doeval = 0;
dostruct = 0;
fields = {};
idx = 0;

state = states.init;
insert_list = {};
append_list = {};
exclude_list = {};
default_list = priority_list;
while(idx < length(request_list))
    idx = idx + 1;
    item = request_list{idx};
    
    if(isstruct(item))
        if(state == states.exclude)
            error('get_values: cannot exclude a struct context')
        end
        context = 'special';
    else
        context = item;
    end
    
    if(~ischar(context))
        error('get_value: non-string encountered where string was expected');
    end
    
    switch(context)
        case {all_context_list{:}, 'special'}
            switch(state)
                case states.init
                    state = states.insert;
                    default_list = {};
                    insert_list = horzcat(insert_list,item);
                case states.insert
                    insert_list = horzcat(insert_list,item);
                case states.append
                    append_list = horzcat(append_list,item);
                case states.exclude
                    exclude_list = horzcat(exclude_list,item);
            end
        case 'onerror'
            idx = idx + 1;
            onerror = 1;
            if(idx <= length(request_list))
                error_value = request_list{idx};
                if(dolist && iscell(error_value))
                    if(~(isscalar(error_value) || length(error_value) == length(varnames)))
                        error('get_value: error_value cell array must be of length one or same length as varnames')
                    end
                end
            else
                error_value = NaN;
            end
        case 'struct'
            if(dolist)
                error('get_value: cannot use struct mode on a cell array input')
            end
            idx = idx + 1;
            dostruct = 1;
            dolist = 1;
            if(idx <= length(request_list))
                fields = request_list{idx};
                if(isstruct(fields))
                    fields = fieldnames(fields);
                end
            else
                fields = {};
            end
            if(isempty(fields) || ~(iscellstr(fields) || ischar(fields) && strcmp(fields,'union')))
                error('get_value: struct mode requires a struct, a cellstr of field names, or the string ''union''')
            end
        case 'all'
            default_list = all_context_list;
        case 'append'
            state = states.append;
        case 'insert'
            state = states.insert;
        case 'eval'
            doeval = 1;
        case 'exclude'
            state = states.exclude;
        case 'priority'
            default_list = priority_list;
        case 'reverse'
            reverse = 1;
        case 'showall'
            showall = 1;
        otherwise
            warning('get_value: unknown request ''%s'', ignored', context)
    end
end

context_list = horzcat(insert_list, default_list, append_list);
if(length(exclude_list))
    context_list = context_list(~ismember(context_list,exclude_list));
end
if(reverse)
    context_list = fliplr(context_list);
end
    
if(dostruct)
    varname = varnames{1};
    if(ischar(fields))
        % do union here
        fields = {};
        for idx = 1:length(context_list)
            context = context_list{idx};
            if(isstruct(context))
                fields = union(fields,fieldnames(context));
            else
                switch(context)
                    case {'base', 'caller'}
                        % cannot do union of fieldnames for base or caller, skip them
                    otherwise
                        try
                            fields = union(fields,fieldnames(eval([context '.' varname])));
                        end
                end
            end
        end
    end
    if(length(fields))
        varnames = strcat([varname '.'],fields);
    else
        varnames = {''};
    end
end

for vidx = 1:length(varnames)
    varname = varnames{vidx};

    s = [];
    nspecial = 0 ;
    if(~isempty(varname))
        for idx = 1:length(context_list)
            context = context_list{idx};

            if(isstruct(context))
                try
                    s.(['special' num2str(nspecial)]) = context.(varname);
                    nspecial = nspecial + 1;
                    if(~showall), break, end
                end
                continue
            end

            switch(context)
                case {'caller', 'base'}
                    try
                        s.(context) = evalin(context,varname);
                        if(~showall), break, end
                    end
                case struct_list
                    try
                        s.(context) = eval([context '.' varname]);
                        if(~showall), break, end
                    end
                otherwise
                    error('get_value: unexpected context encountered')
            end
        end
    end
    
    if(isempty(s) && onerror)
        if(iscell(error_value))
            if(isscalar(error_value))
                s.onerror = error_value{1};
            else
                s.onerror = error_value{vidx};
            end
        else
            s.onerror = error_value;
        end
    end

    if(showall)
        out = s;
    else
        if(isempty(s))
            if(dostruct)
                error('get_value: no fields were found for requested struct, and no ''onerror'' value was provided')
            else
                error('get_value: no value found for ''%s'', and no ''onerror'' value was provided', varname)
            end
        else
            out = struct2cell(s);
            out = out{1};
            if(doeval && ischar(out))
                out = evalin('caller',out);
            end
        end
    end

    if(dolist)
        if(dostruct)
            if(isempty(fields))
                outs = out;
            else
                outs.(fields{vidx}) = out;
            end
        else
            outs{vidx} = out;
        end
    else
        outs = out;
    end

end


    