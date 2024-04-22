close all hidden

disp('Warning this will close all Simulink models without saving')
resp = input('Are you sure this is what you want to do? [y or n]: ','s');
if strcmp(resp,'y')
    bdclose('all')
else
    disp(' ')
    disp('Simulink diagrams were not cleared from workspace')
    disp('Save all diagrams, and run reset_workspace again')
    disp('Hit any key to continue')
    pause
end

clear all

% get rid of any non Matlab related directories in path
p = path ;
while p
    [dirname, p] = strtok(p,';') ;
    if ~strncmp(dirname, fullfile(matlabroot,'toolbox'), length(fullfile(matlabroot,'toolbox')))
        rmpath(dirname)
    end
end
clear p dirname

addpath(fullfile(matlabroot,'work'));

clc
