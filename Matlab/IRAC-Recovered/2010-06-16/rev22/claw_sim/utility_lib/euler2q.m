function e = euler2q(att, quat_IC_in, att_type_int_in, dc_L2W_in)

% NOTE: The following must be set in workspace for att2e.mdl to work correctly!
%    att2e_quat_IC
%    att2e_att_type
%    att2e_dc_L2W
%    MACH.att_in_order

global MACH att_type

quat_IC = [1 0 0 0] ;
if(nargin >= 2)
    if(length(quat_IC_in) == 4)
       quat_IC = quat_IC_in ;
    end
elseif(isfield(MACH,'quat_IC'))
    quat_IC = MACH.quat_IC ;
end
assignin('base','att2e_quat_IC',quat_IC) ;

att_type_int = att_type.ypr_bank ;
if(nargin >= 3)
    if(length(att_type_int_in) == 1)
        att_type_int = att_type_int_in ;
    end
elseif(isfield(MACH,'att_type'))
    att_type_int = MACH.att_type ;
end
assignin('base','att2e_att_type',att_type_int) ;

dc_L2W = eye(3);
if(nargin >= 4)
    dc_L2W = dc_L2W_in ;
end
assignin('base','att2e_dc_L2W',dc_L2W) ;

if(isvector(att))
    att = reshape(att,1,3) ;
end

tmax = size(att,1) - 1 ;

[tdum, xdum, e] = sim('att2e',tmax,[],[[0:tmax]' att]);
