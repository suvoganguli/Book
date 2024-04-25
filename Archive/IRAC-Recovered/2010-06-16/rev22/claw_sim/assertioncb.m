function assertioncb

set_param(get_value('sim_name'),'SimulationCommand','WriteDataLogs')

evalin('base','update_taem_tables')

% keyboard

disp('updating sim ...')
set_param(get_value('sim_name'),'SimulationCommand','update')

return

foo = Simulink.Parameter;
foo.RTWInfo.StorageClass = 'ImportedExtern';
foo.Value = [0:100].^2;
