function [varargout] = vec2dc(varargin)
% convert vector direction to cosine matrix (and optional auxilliary info)

if(nargin == 3 && sum(cellfun(@isscalar,varargin)))
    vec = cell2mat(varargin);
elseif(nargin == 1 && isvector(varargin{1}) && length(varargin{1}) == 3)
    vec = varargin{1};
else
    disp('input to vec2dc must be a single vector or the 3 individual elements');
    dircos = [];
    return
end

Rground = hypot(vec(1),vec(2));
Rslant = hypot(Rground,vec(3));
az_angle = atan2(vec(2),vec(1));
el_angle = atan2(-vec(3),Rground);

varargout{1} = rot2dc([0 el_angle az_angle],'zyx');
switch(nargout)
    case {1, 0}
        % already done
    case 2
        varargout{2} = struct('az_angle', az_angle, 'el_angle', el_angle, 'Rground', Rground, 'Rslant', Rslant);
    otherwise
    error('vec2dc takes 1 or 2 output arguments')
end
