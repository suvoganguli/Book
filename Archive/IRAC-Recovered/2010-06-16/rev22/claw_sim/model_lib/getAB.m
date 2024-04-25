function [A,B] = getAB(x_nom, u_nom, model)

global MACH

if ~exist('model','var')
    model = 'obac' ;
end

% dfe added 1.e-3 to get pole to occur at -5.0000, i.e. quat constraint
x_pert = [
        0.02*ones(3,1) % pqr
        2*ones(3,1) % uvw
        [5 5 2]' % NEh
%         0.01*ones(4,1) % quat
        0.0001*ones(4,1) % quat
        ] *1.e-3 ;
    
% default pert for u
u_pert = 0.1*ones(size(u_nom)) ;

% overrides for specific u
% [2009-02-19 SGP] use the Bmat computation perts where defined
% u_pert(MACH.vane_idx) = 0.2 ;
% u_pert(MACH.tvc_idx) = 0.2 ;
% u_pert(MACH.throttle_idx) = 0.025 ;
u_pert(MACH.pqr_u_idx) = MACH.pqr_u_pert ;
u_pert(MACH.throttle_idx) = MACH.vel_u_pert(3:end) ;

eval(['xdot_',model,'( [], [], [], ''compile'');']) ;
%Linearization_Obac( [], [], [], 'compile');
%y2  = Linearization_Obac( 0, x2, u2, 'outputs');
%dx2 = Linearization_Obac( 0, x2, u2, 'derivs');
%Linearization_Obac( [], [], [], 'term');

xdot_nom = get_xdot([x_nom ; u_nom],model) ;

for i = 1:length(x_nom)
    del_x = zeros(size(x_nom)) ;
    del_x(i) = x_pert(i) ;
    xdot_pert(:,i) = get_xdot([x_nom+del_x ; u_nom],model) ;%get_xdot_obac([x_nom+del_x ; u_nom]) ;
    A(:,i) = (xdot_pert(:,i) - xdot_nom)/x_pert(i) ;
end

for i = 1:length(u_nom)
    del_u = zeros(size(u_nom)) ;
    del_u(i) = u_pert(i) ;
    xdot_pert(:,i) = get_xdot([x_nom ; u_nom+del_u],model) ;%get_xdot_obac([x_nom ; u_nom+del_u]) ;
    B(:,i) = (xdot_pert(:,i) - xdot_nom)/u_pert(i) ;
end

eval(['xdot_',model,'( [], [], [], ''term'');']);

function xdot = get_xdot(xu,model)

%[tdum, xdum, xdot] = sim(['xdot_',model], 0, [], [0 reshape(xu, 1, length(xu))]);
eval(['xdot = xdot_',model,'( 0, [], xu, ''outputs'');']);
if(isstruct(xdot))
    xdot = xdot.signals.values ;
end
xdot = reshape(xdot, length(xdot), 1); % make xdot a column vector
