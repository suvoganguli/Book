%
%------- CLAW experiment ------------
%
% Create linear model, design pitch-axis controller, and
% test at different trim points.
%
% Done in a more systematic way.

% $ my_ex2.m - 8/25/09 $
% subhabrata.ganguli@honeywell.com

%% Initial setup

setup

%% Design Trim Point

% Trim to nominal condition: level flight, alpha=3
mws_designpoint = trimgtm(struct('eas',90, 'gamma',0),'elev',1);

% Load Simulation Variables (at trim condition) into Model Workspace
loadmws(mws_designpoint);

% Linearize model about this condition
fprintf(1,'Linearizing...')
[sys,londyn,latdyn]=linmodel(mws_designpoint);
fprintf(1,' Done\n');


%% Baseline Control Law - Pitch-axis - Design

Alon    = londyn.a;
Blon    = londyn.b;
Alon_sp = Alon([3 2],[3 2]);   % q w
Blon_sp = Blon([3 2],1);       % q w <- de

ub_trim = mws_designpoint.StatesInp(1); % fps
vb_trim = mws_designpoint.StatesInp(2); % fps
wb_trim = mws_designpoint.StatesInp(3); % fps
tas_fps = norm([ub_trim,vb_trim,wb_trim],2); % fps
K.alpha_trim = atan(wb_trim/ub_trim)*180/pi; % deg

T_wtoalp = [1 0;0 tas_fps];
Alon_sp2 = inv(T_wtoalp) * Alon_sp * (T_wtoalp);  % q alp
Blon_sp2 = inv(T_wtoalp) * Blon_sp;               % q alp <- de
sys_sp2  = ss(Alon_sp2,Blon_sp2,eye(2),[0 0]'); 

% Inversion gains
K.CA = [1 0]*Alon_sp2;
K.invCB = inv([1 0]*Blon_sp2);

K.CA(2) = 0;
disp('Alpha feedback-gain = 0');

% Desired Dynamics
K.Kb = 4;
K.fi = 1/4;
K.fc = 1/2*0;


%% Baseline Control Law - Pitch-axis - Simulation

% Open block diagram
open_system('gtm_design_baseline'); 

% Load Simulation Variables (at trim condition) into Model Workspace
loadmws(mws_designpoint,'gtm_design_baseline');

% Add Control Law Parameters into Model Workspace
appendmws(K,'gtm_design_baseline');

% Construct Command Signal
a=[0.5 0 0]; % pulse amplitude(deg/sec), [pitch-rate]
tfinal = 15;

% Construct doublet sequence
set_param('gtm_design_baseline/Input Generator/Doublet Generator','timeon','[2 0 0]'); 
set_param('gtm_design_baseline/Input Generator/Doublet Generator','pulsewidth','[4 0 0]');
set_param('gtm_design_baseline/Input Generator/Doublet Generator','amplitude',sprintf('[%f %f %f]',a(1),a(3),a(2)));

% Simulation Closed Loop GTM
[tsimcl,xsimcl,ysimcl]=sim('gtm_design_baseline',[0 tfinal]);

% Grab state in ysim First 6 are trim outputs, next 12 are state.
ysimcl=ysimcl(:,7:18);

% Simulate Desired Dynamics
dummy = tf(K.Kb/2,[1 K.Kb/2]);
sysdes = dummy*dummy;
ulin = pitchcmd.signals.values';
tlin = pitchcmd.time';
ylin = lsim(sysdes,ulin,tlin);


%% Closed-loop Plots

set(figure(1),'Position',[20 20 900 700]);
subplot(321),
plot(tsimcl,ysimcl(:,1)); grid on
title('Linear Velocity to Doublet Sequence [elevator,rudder,aileron]');
xlabel('Time (sec)');ylabel('u (ft/sec)')
legend('Simulation');
subplot(323),
plot(tsimcl,ysimcl(:,2)); grid on
xlabel('Time (sec)');ylabel('v (ft/sec)')
subplot(325),
plot(tsimcl,ysimcl(:,3)); grid on
xlabel('Time (sec)');ylabel('w (ft/sec)')

subplot(322),
plot(tsimcl,180/pi*ysimcl(:,4)); grid on
title('Angular Velocity to Doublet Sequence [elevator,rudder,aileron]');
xlabel('Time (sec)');ylabel('p (deg/sec)')
subplot(324),
plot(tsimcl,180/pi*ysimcl(:,5),tlin,ylin); grid on
xlabel('Time (sec)');ylabel('q (deg/sec)')
subplot(326),
plot(tsimcl,180/pi*ysimcl(:,6)); grid on
xlabel('Time (sec)');ylabel('r (deg/sec)')


set(figure(2),'Position',[20 20 900 700]);
subplot(211)
plot(tsimcl,180/pi*ysimcl(:,5),tlin,ylin,'r'); grid on
xlabel('Time (sec)');ylabel('q (deg/sec)')
subplot(212);
plot(tsimcl,sout.ELLOB);  grid on % all elevs are same
xlabel('Time (sec)');ylabel('\deltae (deg)');

return

%% CLAW Evaluation at Several Trim Conditions

load modeldata
ntp = length(fields(modeldata));

% Construct Command Signal
a=[0.5 0 0]; % pulse amplitude(deg/sec), [pitch-rate]
tfinal = 15;

% Construct doublet sequence
set_param('gtm_design_baseline/Input Generator/Doublet Generator','timeon','[2 0 0]'); 
set_param('gtm_design_baseline/Input Generator/Doublet Generator','pulsewidth','[4 0 0]');
set_param('gtm_design_baseline/Input Generator/Doublet Generator','amplitude',sprintf('[%f %f %f]',a(1),a(3),a(2)));


%% for-loop starts

for ii = 1:ntp

% Load Varying Trim Point into Model Workspace
eval(['mws_trimpoint = modeldata.tp' num2str(ii) ';']);
loadmws(mws_trimpoint);

% Calculate new alpha_trim
ub_trim = mws_trimpoint.StatesInp(1); % fps
vb_trim = mws_trimpoint.StatesInp(2); % fps
wb_trim = mws_trimpoint.StatesInp(3); % fps
tas_fps = norm([ub_trim,vb_trim,wb_trim],2); % fps
K.alpha_trim = atan(wb_trim/ub_trim)*180/pi; % deg

% Add Control Law Parameters into Model Workspace
appendmws(K,'gtm_design_baseline');

% Simulation Closed Loop GTM
[tsimcl,xsimcl,ysimcl]=sim('gtm_design_baseline',[0 tfinal]);

% Grab state in ysim First 6 are trim outputs, next 12 are state.
ysimcl=ysimcl(:,7:18);

figure(2);
subplot(211); hold on
plot(tsimcl,180/pi*ysimcl(:,5),'k'); grid on
xlabel('Time (sec)');ylabel('q (deg/sec)')
subplot(212); hold on
plot(tsimcl,sout.ELLOB,'k');  grid on % all elevs are same
xlabel('Time (sec)');ylabel('\deltae (deg)');
    
end

%% Close Diagrams

% Close open-loop block diagram
bdclose('gtm_design');
bdclose('gtm_design_baseline');
