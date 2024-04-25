function s = get_orientation(x, att_type_int, att_out_order)

global MACH

if(nargin < 2)
    att_type_int = MACH.att_type ;
end

if(nargin < 3)
    att_out_order = MACH.att_out_order(att_type_int,:) ;
end


if(nargin < 1)
    disp('usage: get_orientation(x, att_type_int, att_out_order)')
    s = [] ;
    return
end

% get uvw states from x as a column vector
s.uvw = reshape(x(4:6),1,3) ;

% get quat states from x as a row vector, and normalize
s.quat = reshape(x(10:13),1,4) ;
s.quat = s.quat/norm(s.quat) ;

% convert quaternions to direction cosine matrix
dircos = q2dc(s.quat) ;

% get north, east, and altitude velocities as a row vector
s.NdEdhd = (s.uvw*dircos).*[1 1 -1] ;
Nd = s.NdEdhd(1) ;
Ed = s.NdEdhd(2) ;
hd = s.NdEdhd(3) ;

V = norm(s.NdEdhd) ;
chi = atan2(Ed,Nd) ;
gamma = atan2(hd,norm([Ed Nd])) ;
s.Vchigam = [V chi gamma] ;
s.dc_L2W = [cos(gamma) 0 -sin(gamma); 0 1 0; sin(gamma) 0 cos(gamma)] ...
    * [cos(chi) sin(chi) 0; -sin(chi) cos(chi) 0; 0 0 1] ;

% get Euler angles as a row vector
s.att = reshape(q2euler(dircos, att_type_int, att_out_order, s.dc_L2W),1,3) ;
