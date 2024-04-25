function out = q2euler(evec_mat, att_type_int, att_out_order, dc_L2W)
% Q2EULER: convert quaternions to Euler angles

global MACH att_type

if(nargin < 2)
    att_type_int = MACH.att_type ;
end

if(nargin < 3)
    att_out_order = MACH.att_out_order(att_type_int,:) ;
end

if(nargin < 4)
    dc_L2W = [] ;
end

if(nargin < 1)
    disp('usage: q2euler(quat, att_type_int, att_out_order)')
    s = [] ;
    return
end

evec_size = size(evec_mat) ;
if(evec_size(1) == 4)
    % assume each column is a quaternion and loop over columns
    evec_orient = 1 ;
    nevec = evec_size(2) ;
    out = zeros(3, nevec) ;
elseif(evec_size(2) == 4)
    % assume each row is a quaternion and loop over rows
    evec_orient = 2 ;
    nevec = evec_size(1) ;
    out = zeros(nevec, 3) ;
elseif(sum(evec_size == 3) >= 2)
    % the input is really a dircos matrix!
    dircos_idx_col = find(evec_size ~= 3) ;
    if(isempty(dircos_idx_col))
        % Note: this ignores the case where dircos is 3x3x3!
        dircos_idx_col = 3 ;
        nevec = 1 ;
    else
        nevec = evec_size(dircos_idx_col) ;
    end
    evec_orient = 0 ;
    out = zeros(nevec, 3) ;
else
    error('evec_mat must be an nx4 or 4xn matrix of quaternions, or 3x3xn matrix of dircos');
end

dc_L2W_size = size(dc_L2W) ;
if(~isempty(dc_L2W))
    if(sum(dc_L2W_size == 3) >= 2)
        dc_L2W_idx_col = find(dc_L2W_size ~= 3) ;
        if(isempty(dc_L2W_idx_col))
            % Note: this ignores the case where dc_L2W is 3x3x3!
            dc_L2W_idx_col = 3 ;
            nL2W = 1 ;
        else
            nL2W = dc_L2W_size(dc_L2W_idx_col) ;
            if(nL2W > 1 && nL2W ~= nevec)
                error('dc_L2W must have the same number of mats as q/dircos')
            end
        end
    else
        error('dc_L2W must be 3x3, nx3x3, 3xnx3, or 3x3xn')
    end
end

for i = 1:nevec
    switch evec_orient
        case 1
            evec = evec_mat(:,i) ;
        case 2
            evec = evec_mat(i,:) ;
    end
    
    if( evec_orient > 0 )
        evec = evec/norm(evec) ; % normalize quaternion
        dircos = q2dc(evec) ;
    else
        switch(dircos_idx_col)
            case 1
                dircos = evec_mat(i,:,:) ;
            case 2
                dircos = evec_mat(:,i,:) ;
            case 3
                dircos = evec_mat(:,:,i) ;
        end
        dircos = squeeze(dircos) ;
    end
        
    switch(att_type_int)
        case att_type.tiltcam
            dircos = MACH.body2vert*dircos ;
            rot_order = 'xyz' ;
            att_sign = 1 ;
        case {att_type.ypr_bank, att_type.ypr_skid}
            dircos = MACH.body2horz*dircos ;
            rot_order = 'zyx' ;
            att_sign = 1 ;
        case {att_type.mba_bank, att_type.mba_skid}
            % define angles relative to wind axis rotation, if available
            if(~isempty(dc_L2W))
                idx = min(i,nL2W) ;
                switch(dc_L2W_idx_col)
                    case 1
                        dc_L2W_tmp = dc_L2W(idx,:,:) ;
                    case 2
                        dc_L2W_tmp = dc_L2W(:,idx,:) ;
                    case 3
                        dc_L2W_tmp = dc_L2W(:,:,idx) ;
                end
                dircos = dircos*squeeze(dc_L2W_tmp)' ; 
            end
            
            rot_order = 'xzy' ;
            att_sign = [1 1 -1] ; % flip the sign of the beta rotation
        otherwise
            rot_order = 'zyx' ;
            att_sign = 1 ;
    end
    
    out_vec = att_sign.*dc2rot(dircos, rot_order) ;
    out_vec = out_vec(att_out_order) ;
    
    switch evec_orient
        case 1
            out(:,i) = out_vec ;
        case {0, 2}
            out(i,:) = out_vec ;
    end
end
