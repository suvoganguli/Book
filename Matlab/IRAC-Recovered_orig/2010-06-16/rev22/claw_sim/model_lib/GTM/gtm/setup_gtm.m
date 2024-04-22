% d.e.cox@larc.nasa.gov
% $Id: setup.m 437 2008-02-19 19:34:33Z cox $

% Change 1: suvo

% These paths are added by myaddpath.m
% % Add local dir's to matlab path
% path('./mfiles',path);
% path('../libs',path);
% rehash path

% Change 2: suvo
global config
gtm_model = config.model_name;

% Close model if open, prompt if changed.

% Change 3: suvo
%if  not(isempty(find_system('SearchDepth',0,'Name','gtm_design')))
%   if strcmp(get_param('gtm_design','Dirty'),'on');
if  not(isempty(find_system('SearchDepth',0,'Name',gtm_model)))    
   if strcmp(get_param(gtm_model,'Dirty'),'on');
        savechanges=input('  gtm_design model has been changed, save changes (y/N) ?','s');
        if ~isempty(savechanges) && strcmpi(savechanges(1),'y');
	  fprintf(1,'Saving System...');
	  clearmws % Suppreses warning mesage about model workspace
	  clear savechanges % clear temporary response variable
      
      
      % Change 4: suvo
	  % save_system('gtm_design');
      save_system(gtm_model);
      
	  fprintf(1,' Done.\n');
        end
   end
    
    
    % Change 5: suvo
   
    % terminate if left in paused state. matlab will not close paused model.
    %if strcmp(get_param('gtm_design','SimulationStatus'),'paused'),
    %    gtm_design([],[],[],'term');
    %end
    %bdclose('gtm_design');    
    if strcmp(get_param(gtm_model,'SimulationStatus'),'paused'),
        eval([gtm_model '([],[],[],''term'')']);
    end
    bdclose(gtm_model);
    
    
end

% Clear simout* variables to ensure clean initialization
clear simout simout_names SimWSout

% Clear precompiled functions, required to reflect changes in mfiles
% that exist outside working directory.
clear functions

% Open block diagram
warning('off','Simulink:SL_MdlFileNotOnPath'); % Suppress spurious warnings

% Change 6: suvo
%open_system('gtm_design');  
open_system(gtm_model);  

% Change 7: suvo
% The two commands below may not be not required for MACH
%
% load nominal starting point
% loadmws(init_design('GTM'),'gtm_design');
loadmws(init_design('GTM'),gtm_model);

% Trim model, and load trimmed conditions
%appendmws(trimgtm(struct('eas',75, 'gamma',0)));
appendmws(trimgtm(struct('eas',75, 'gamma',0)),gtm_model);

warning('on','Simulink:SL_MdlFileNotOnPath');





