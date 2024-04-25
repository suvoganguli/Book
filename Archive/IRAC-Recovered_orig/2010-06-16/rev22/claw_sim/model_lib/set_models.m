function set_models(model_name,verbose)
% this function should be run from any system block diagram
% that has references to OBAC ('cl model') or TRAC ('vehicle model') blocks

global MACH

if(~exist('model_name'))
    model_name = gcs;
else
    try
        find_system(model_name);
    catch
        load_system(model_name);
    end
end

if(~exist('verbose'))
    verbose = 0;
end

if(verbose)
    disp(['running set_models from ' model_name]);
end

% block_name
% block_link_name
% blocks

try
    block_name = 'cl model';
    block_link_name = ['models/' evalin('base','obac_params.model_name')];
    set_block_links(block_name,block_link_name,model_name,verbose);
end

try
    block_name = 'vehicle model';
    block_link_name = ['models/' evalin('base','trac_params.model_name')];
    set_block_links(block_name,block_link_name,model_name,verbose);
end

try
    block_name = 'actuator model';
    block_link_name = evalin('base','SERVO.servo_type');
    if(isempty(fileparts(block_link_name)))
        block_link_name = ['model_lib/' block_link_name];
    end
    set_block_links(block_name,block_link_name,model_name,verbose);
end

try
    block_name = 'preference schedule';
    block_link_name = evalin('base','preference_schedule_name');
    if(isempty(fileparts(block_link_name)))
        block_link_name = ['model_lib/' block_link_name];
    end
    set_block_links(block_name,block_link_name,model_name,verbose);
end

try
    block_name = 'limit schedule';
    block_link_name = evalin('base','limit_schedule_name');
    if(isempty(fileparts(block_link_name)))
        block_link_name = ['model_lib/' block_link_name];
    end
    set_block_links(block_name,block_link_name,model_name,verbose);
end

try
    att_angles = MACH.att_angles(MACH.att_type,:);

    att_input_blocks = {'att1 cmd', 'att2 cmd', 'att3 cmd', 'att3d cmd'};
    att_input_num = [1 2 3 3];

    for i = 1:length(att_input_blocks)
        block_name = find_system(model_name,'Name',att_input_blocks{i});
        block_name = block_name{1};
        set_param(block_name,'Tag',att_angles{att_input_num(i)});
    end
end

function set_block_links(block_name,block_link_name,model_name,verbose)

blocks = find_system(model_name,'Name',block_name);

if(verbose)
    if(length(blocks))
        disp(['setting ''' block_name ''' link = ''' block_link_name ''' in:']);
    else
        disp(['no ''' block_name ''' blocks found']);
    end
end

for idx = 1:length(blocks)
    if(verbose)
        disp(['    ' blocks{idx}]);
    end
    set_param(blocks{idx},'ReferenceBlock',block_link_name);
    link_status = get_param(blocks{idx},'LinkStatus');
    if(strcmp(link_status,'unresolved'))
        set_param(blocks{idx},'SourceBlock',block_link_name);
    end
end

if(verbose)
    disp(['done with ''' block_name ''' blocks']);
end
