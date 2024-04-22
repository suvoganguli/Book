function sout = get_toworks

sim_name = get_value('sim_name');

toworks = find_system(sim_name,'FollowLinks','on','BlockType','ToWorkspace');
varnames = get_param(toworks,'VariableName');
maxdatapoints = get_param(toworks,'MaxDataPoints');
sout = cell2struct(horzcat(maxdatapoints,toworks),varnames)

return

% code to set MaxDataPoints in each ToWorkspace
tmp = struct2cell(sin);
maxdatapoints = tmp{:,1};
toworks = tmp{:,2};
cellfun(@(x,y) set_param(x,'MaxDataPoints',y),toworks,maxdatapoints)