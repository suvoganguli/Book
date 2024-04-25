function myaddpath

dir = fileparts(mfilename('fullpath'));

addpath(fullfile(dir,'mfiles'));
addpath(fullfile(dir,'libs'));

% addpath(fullfile(dir,'aircraft','matfiles'));
% addpath(fullfile(dir,'aircraft','models'));
% addpath(fullfile(dir,'aircraft','scripts'));
% addpath(fullfile(dir,'engine','matfiles'));
% addpath(fullfile(dir,'engine','models'));
% addpath(fullfile(dir,'engine','scripts'));
