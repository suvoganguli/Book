function vehicle_params = define_model(model_use_type, model_type)

if(isempty(model_type))
    error('no ''%s'' model sub-directory has been specified', model_use_type)
end

model_def = get_value('model_def','struct','union');

model_type_dir = fullfile(model_def.model_dir, model_type);

if(~exist(model_type_dir, 'dir'))
    error('specified ''%s'' model sub-directory (%s) does not exist', model_use_type, model_type_dir)
end

addpath(fullfile(pwd,model_type_dir));

% throw away the model subtype (which is used only to specify path), if it exists
model_type = regexprep(model_type,'[\\/].*','') ; 

model_def.model_use_type = model_use_type ;
model_def.model_type = model_type ;
model_def.model_type_dir = model_type_dir ;
model_def.model_name = [ model_type '-' model_use_type ] ;

vehicle_params = start_vehicle_params(model_def) ; % default definitions required by all models
vehicle_params = set_vehicle_params(vehicle_params) ; % specific definitions for this vehicle
if(~isfield(vehicle_params,'aero'))
    vehicle_params.aero = set_aero_params(vehicle_params) ;
end
% vehicle_params = set_derived_params(vehicle_params) ; % hook for model specific cleanup
vehicle_params = end_vehicle_params(vehicle_params) ; % cleanup for all models
