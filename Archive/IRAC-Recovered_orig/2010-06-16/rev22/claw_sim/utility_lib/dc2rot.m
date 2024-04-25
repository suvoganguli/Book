% intended to be identical in functionality to utility_lib/dc2rot
function att_out = dc2rot(dc_in, rot_order)

% derive rot_order related quantities
% this code is the same as that in the initialization of
% the utility_lib blocks dc2rot and rot2dc
rot_def = {
    'zyx',[1 2 3],[1 2 3],1
    'yxz',[3 1 2],[2 3 1],1
    'xzy',[2 3 1],[3 1 2],1
    'xyz',[3 2 1],[3 2 1],-1
    'yzx',[1 3 2],[1 3 2],-1
    'zxy',[2 1 3],[2 1 3],-1
};
[tf,rot_idx] = ismember(rot_order,rot_def(:,1));
rot_in_order = rot_def{rot_idx,2};
rot_out_order = rot_def{rot_idx,3};
rot_sign = rot_def{rot_idx,4};

% set Euler angles
% reorder the direction cosine matrix, dc, so
% that the order of rotation is c = R(x,attx)*R(y,atty)*R(z,attz),
% (the zyx order) outputs will be reordered to original order
% in input dircos

dc_size = size(dc_in);

do_many = length(dc_size) == 3;
if(do_many) 
    ndc = dc_size(1);
else
    ndc = 1;
end

att_out = zeros(ndc,3);
for i = 1:ndc
    if(do_many)
        dc = squeeze(dc_in(i,:,:));
    else
        dc = dc_in;
    end
    dc = dc(rot_in_order, rot_in_order) ;        
    attx = atan2(dc(2,3),dc(3,3)) ;
    atty = atan2(-dc(1,3),hypot(dc(1,1),dc(1,2))) ;
    attz = atan2(dc(1,2),dc(1,1)) ;
    att = [attx atty attz] ;
    att = att(rot_out_order) ;
    att_out(i,:) = rot_sign*att ;
end
