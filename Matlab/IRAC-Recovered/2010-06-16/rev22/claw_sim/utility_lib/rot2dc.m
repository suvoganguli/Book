% intended to be identical in functionality to utility_lib/rot2dc
function dc_out = rot2dc(att_in, rot_order)

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

natt = size(att_in,1);

dc_out = zeros(natt,3,3);
for i = 1:natt
    att = rot_sign*att_in(i,:) ;
    att = att(rot_in_order) ;

    sattx = sin(att(1)) ;
    cattx = cos(att(1)) ;
    satty = sin(att(2)) ;
    catty = cos(att(2)) ;
    sattz = sin(att(3)) ;
    cattz = cos(att(3)) ;

    cattz_cattx = cattz*cattx ;
    sattz_cattx = sattz*cattx ;
    cattz_sattx = cattz*sattx ;
    sattz_sattx = sattz*sattx ;

    dc(1,1) = catty*cattz ;
    dc(2,1) = satty*cattz_sattx - sattz_cattx ;
    dc(3,1) = satty*cattz_cattx + sattz_sattx ;
    dc(1,2) = catty*sattz ;
    dc(2,2) = satty*sattz_sattx + cattz_cattx ;
    dc(3,2) = satty*sattz_cattx - cattz_sattx ;
    dc(1,3) = -satty ;
    dc(2,3) = catty*sattx ;
    dc(3,3) = catty*cattx ;

    dc_out(i,:,:) = dc(rot_out_order, rot_out_order) ;
end

if(natt == 1)
    dc_out = squeeze(dc_out) ;
end