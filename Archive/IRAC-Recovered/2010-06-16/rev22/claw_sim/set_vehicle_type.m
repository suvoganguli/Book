function set_vehicle_type(vehicle_type)

if(~exist('vehicle_type') || ~ischar(vehicle_type) || isempty(vehicle_type))
    error('set_vehicle_type: argument vehicle_type must be a character string of non-zero length') ;
end

disp(['vehicle_type = ' vehicle_type])

% get rid of any directories in path related to the current directory
this_dir = pwd ;
p = path ;
while p
    [dirname, p] = strtok(p,pathsep) ;
    if strncmp(dirname, this_dir, length(this_dir))
        rmpath(dirname)
    end
end

clear functions

try
    close_system('models',0)
end
try
    close_system('claw_main_sfunc',0)
end

addpath(this_dir) ;

set_MACH_def

model_home = get_value('model_home') ;

model_dir = fullfile(model_home,vehicle_type) ;

if(~exist(model_dir,'dir'))
    error('unknown vehicle type: %d\n', vehicle_type)
end

addpath(fullfile(this_dir,model_home)) ;
addpath(fullfile(this_dir,model_dir)) ;

set_vehicle_def

path_dirs = struct2cell(get_value('path_dirs','showall')) ;
path_dirs = horzcat(path_dirs{:}) ;
for i = 1:length(path_dirs)
    path_dir = path_dirs{i} ;
    try  
        addpath(fullfile(pwd, path_dir)) ;
    end
end

global vehicle_def

vehicle_def.vehicle_type = vehicle_type ;
vehicle_def.model_def.model_dir = model_dir ;
