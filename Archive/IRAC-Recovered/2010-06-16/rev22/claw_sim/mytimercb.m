function varargout = mytimercb(varargin)

persistent figure_handle file_datenum_old mytimer

BAI_dir = get_value('BAI_dir','all','onerror','');

if(isempty(BAI_dir))
    error('BAI_dir is not set')
end

if(nargin < 2)
    % code to create and start timer
    if(nargin > 0)
        period = varargin{1};
    else
        period = 1;
    end
    
    % kill any existing timer that wasn't properly terminated
    mytimer = timerfind('TimerFcn',@mytimercb);
    if(~isempty(mytimer))
        stop(mytimer)
        delete(mytimer)
    end
    
    mytimer = timer('TimerFcn',@mytimercb,'ExecutionMode','fixedSpacing','Period',period,'TasksToExecute',intmax);
    start(mytimer)
    
    try
        delete(figure_handle)
    end
    figure_handle = figure;
    set(figure_handle,'Visible','off');
    varargout = {figure_handle};
    return
end

file_dir = dir(fullfile(BAI_dir,'ref_trajectory.mat'));
if(isempty(file_dir))
    return
end

if(isfield(file_dir,'datenum'))
    file_datenum = file_dir.datenum;
else
    file_datenum = datenum(file_dir.date);
end

if(isempty(file_datenum_old))
    file_datenum_old = file_datenum;
elseif(file_datenum > file_datenum_old)
    file_datenum_old = file_datenum;
    disp('ref_trajectory file changed, proceeding with trajectory update ...')
    try
        delete(figure_handle);
        figure_handle = [];
        stop(mytimer)
        delete(mytimer)
    catch
        disp('error while stopping mytimer')
        last_error = lasterror;
        disp(last_error.message)
    end
end

% sim_name = get_value('sim_name');
% 
% simstatus = get_param(sim_name,'SimulationStatus');
% if(ismember(simstatus,{'stopped','paused'}))
%     return
% end
% 
% time = get_param(sim_name,'SimulationTime');
% disp(sprintf('t = %g',time)); % show sim time
% 
% disp(sprintf('debug_flag = %g',evalin('base','debug_flag')))
% 
% trigger write of data logs, then check size of the sensors log
% set_param(sim_name,'SimulationCommand','WriteDataLogs')
% disp(sprintf('size(sensors) = %s',mat2str(evalin('base','size(sensors)'))))
