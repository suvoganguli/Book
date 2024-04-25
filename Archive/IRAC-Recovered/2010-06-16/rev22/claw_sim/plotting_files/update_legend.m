function update_legend(varargin)

h = legend(gca);

if(nargin == 1 && iscell(varargin{1}))
    varargin = varargin{1};
end

if(isempty(h))
    legend(gca,varargin);
else
    legend(gca,horzcat(strcat(varargin,'\_1'),strcat(varargin,'\_2')));
end
       
    