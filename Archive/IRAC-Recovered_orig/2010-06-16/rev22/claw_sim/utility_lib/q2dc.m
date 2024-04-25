function [dircos] = q2dc(varargin)
% convert quaternions to direction cosine matrix

if(nargin == 4 && sum(cellfun(@isscalar,varargin)))
    evec = cell2mat(varargin);
elseif(nargin == 1 && isvector(varargin{1}) && length(varargin{1}) == 4)
    evec = varargin{1};
else
    disp('input to q2dc must be a single quaternion vector or the 4 individual elements');
    dircos = [];
    return
end

e0 = evec(1);
e1 = evec(2);
e2 = evec(3);
e3 = evec(4);

% convert quaternions to diagonals of direction cosine matrix
mat_diag = [ 1 1 1 1 ; 1 1 -1 -1 ; 1 -1 1 -1 ; 1 -1 -1 1 ] ;

tmp_d = mat_diag * [ e0*e0 ; e1*e1 ; e2*e2 ; e3*e3 ] ;
normsq_e = tmp_d(1) ;
c11 = tmp_d(2) ;
c22 = tmp_d(3) ;
c33 = tmp_d(4) ;

% convert quaternions to off-diagonals of direction cosine matrix
tmp1 = [ e1*e2 ; e3*e1 ; e2*e3 ] ;
tmp2 = [ e0*e3 ; e0*e2 ; e0*e1 ] ;
tmp_od = 2*[ tmp1 + tmp2 ; tmp1 - tmp2 ] ;
 
% set direction cosine matrix from quaternions
c12 = tmp_od(1) ; 
c31 = tmp_od(2) ; 
c23 = tmp_od(3) ; 
c21 = tmp_od(4) ; 
c13 = tmp_od(5) ; 
c32 = tmp_od(6) ;

% [2009-02-05 SGP] To ensure that it is unitary, we should really normalize
% the DCM with normsq_e.  Leave for now to maintain consistency with
% simulink block 'e2dc'
dircos = [ c11 c12 c13 ; c21 c22 c23 ; c31 c32 c33 ] ; % /normsq_e ;
