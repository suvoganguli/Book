function new_values = set_named_values(old_values,varargin)

group_names = get_value('group_names','onerror',{});

if(nargin < 1)
    error('set_named_values: input must be a cellstr of names, with optional name/value pairs')
end

if(iscellstr(old_values))
    old_values = cell2struct(cell(1,length(old_values)),old_values,2);
end

if(isstruct(old_values))
    names = fieldnames(old_values)';
    new_values = struct2cell(old_values)';
else
    error('set_named_values: first input must be a cellstr of names or a struct')
end

num_names = length(names);

arg_list = {};
array_output = 0;
while(~isempty(varargin))
    % if first optional arg is a cell, process the cell as a list and repeat.
    % otherwise, process all of the remaining arguments as one list.
    
    % if arg list is empty, get next arg
    if(isempty(arg_list))  
        arg_list = varargin{1};
        
        if(ischar(arg_list))
            switch(arg_list)
                case 'get_value'
                    % do a get_value lookup
                    var_name = varargin{2};
                    if(ischar(var_name))
                        varargin = horzcat(struct2cell(get_value(var_name,'showall','reverse','onerror',{{}}))', varargin(3:end));
                    end
                    arg_list = {};
                    continue
                case 'array'
                    array_output = 1;
                    arg_list = {};
            end
        end

        if(isempty(arg_list))
            varargin = varargin(2:end);
            continue
        end
        
        % if the first element is numeric, make it a list, so that it will
        % be treated as a default below
        if(isnumeric(arg_list))
            arg_list = {arg_list};
        end
            
        % if arg is not a cell, process the rest of the input as one list
        if(~iscell(arg_list))
            arg_list = varargin;
            varargin = {};
        else
            % make sure that cell is a row vector, and remove it from
            % varargin
            arg_list = reshape(arg_list,1,length(arg_list));
            varargin = varargin(2:end);
        end
    end
    
    assigns = arg_list{1};
    
    if(isstruct(assigns))
        % convert the struct to a list, process, and then process the rest
        % of the list
        assign_names = fieldnames(assigns);       
        assign_values = struct2cell(assigns);
        arg_list = arg_list(2:end);
    else
        % assume that this is a simple list, and convert it to a struct
        if(~ischar(assigns))
            % if first arg is not a string, assume that it is a default
            % vector
            arg_list = horzcat('default',arg_list);
        end

        assign_names = arg_list(1:2:end);
        assign_values = arg_list(2:2:end);
        
        if(length(assign_names) ~= length(assign_values))
            error('set_named_values: missing last value in name/value pairs');
        end
                
        arg_list = {};
    end
   
    if(isempty(assign_names))
        continue
    end

    for i = 1:length(assign_names)
        assign_name = assign_names{i};
        assign_name = regexprep(assign_name,'all$','.*');
        for j = 1:length(group_names)
            assign_name = regexprep(assign_name,group_names{j},[group_names{j} '.*']);
        end
        assign_value = assign_values{i};

        if(strcmp(assign_name,'default'))
            idx = 1:num_names;
        else
            assign_name = ['^' assign_name '$']; % force exact match
            idx = find(~cellfun('isempty',regexp(names,assign_name)));
        end
        
        try
            if(isnumeric(assign_value))
                new_values(idx) = num2cell(assign_value.*ones(1,length(idx)));
            else
                new_values(idx) = strcat(assign_value,cell(1,length(idx)));
            end
        catch
            error('set_named_values: number of values specified does not match number of names')
        end       
    end
end

if(array_output)
    if(isnumeric(new_values{1}))
        new_values = cell2mat(new_values);
    end
else
    new_values = cell2struct(new_values,names,2);
end
