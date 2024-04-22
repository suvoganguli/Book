% Filename  : plotter2.m
% Author    : S. Ganguli
% Date      : Feb 17, 05
%
% Note      : This file plots the data corresponding
%             to NASA LaRC Piloted Sim Runs (Feb 2005)
%

cc1 = 'b';
cc2 = 'r--';
cc3 = 'k-.';

lw = 1;
fs = 12;

hold_flag = [];
hold_flag = input('Hold? [0/1, default=0]: ');
if isempty(hold_flag)
    hold_flag = 0;
end
if hold_flag
    %lw = input('Enter linewidth: ');
    lw = 1;
end

LASTLAP = 1;
if LASTLAP ~= 1
    t_st  = [];
    t_end = [];
    t_st  = input('Enter start time (default=0) : ');
    t_end = input('Enter end time (default=full): ');
    idx1 = round(t_st/0.02);
    if isempty(t_st)
        idx1 = 1;
    else
        idx1 = round(t_st/0.02);
    end
    if isempty(t_end)
        idx2 = length(TIME);
    else
        idx2 = sum(TIME<t_end);
    end
else
    lw = 1;
    TABLE = [4	5	6	11	12	13	14	15	16	17	8	9	10	18	19;
             78.4	76.5	77.4	73.8	75.12	75.34	75.62	83.12	76.26	74.72	74.24	74.92	76.68	75.24	77.5;];         

    if isempty(str2num(FNAME(end-1)))  % run no. has 1 digit
        RNO = str2num(FNAME(end));
    else
        RNO = str2num(FNAME(end-1:end));
    end
    dummy = find(RNO==TABLE(1,:));
    t_end = TABLE(2,dummy);
    t_st  = t_end-20;
    idx1 = round(t_st/0.02);
    idx2 = sum(TIME<t_end);
end


TIME        = TIME(idx1:idx2);
QDEG_CR     = QDEG_CR(idx1:idx2);
NZ_PDN_CR   = NZ_PDN_CR(idx1:idx2);
CSTAR_CMD   = CSTAR_CMD(idx1:idx2);
THETADGCR   = THETADGCR(idx1:idx2);
ALPHA_CR    = ALPHA_CR(idx1:idx2);
ELEVATOR    = ELEVATOR(idx1:idx2);
PDEG_CR     = PDEG_CR(idx1:idx2);
P_CMD       = P_CMD(idx1:idx2);
BETA_CR     = BETA_CR(idx1:idx2);
BETA_CMD    = BETA_CMD(idx1:idx2);
PHIDGCR     = PHIDGCR(idx1:idx2);
RUDDER      = RUDDER(idx1:idx2);
AILERONR    = AILERONR(idx1:idx2);
SPLR_RO     = SPLR_RO(idx1:idx2);
SPLR_LO     = SPLR_LO(idx1:idx2);
ID_SIGNAL   = ID_SIGNAL(idx1:idx2);
ID_TH_OUT   = ID_TH_OUT(idx1:idx2);
ID_FLAG     = ID_FLAG(idx1:idx2);
PSTICKF     = PSTICKF(idx1:idx2);
WHEELF      = WHEELF(idx1:idx2);
PEDALF      = PEDALF(idx1:idx2);
ALT_CR      = ALT_CR(idx1:idx2);
CAS_CR      = CAS_CR(idx1:idx2);
QBAR_CR     = QBAR_CR(idx1:idx2);
SX          = SX(idx1:idx2);
SY          = SY(idx1:idx2);
SZ          = SZ(idx1:idx2);


figure(1);
hs=subplot(211); if hold_flag, hold on, else hold off, end
hp=plot(TIME,QDEG_CR+32.2/400*(-1-NZ_PDN_CR)*180/pi,cc1,TIME,CSTAR_CMD*180/pi,cc2);
set(hp,'linewidth',lw); %grid on;
set(hs,'fontsize',fs);
ylabel('(deg/s)');
title('C*, C*_c (--)')
axis tight
%set(hs,'xticklabel',[]);
hs=subplot(212); if hold_flag, hold on, else hold off, end
hp=plot(TIME,QDEG_CR,cc1,TIME,-(NZ_PDN_CR+1)*4.6123,cc2);
set(hp,'linewidth',lw); %grid on;
set(hs,'fontsize',fs);
ylabel('(deg/s)');
xlabel('t (sec)');
title('q, -4.6123(nz+1) (--)');
axis tight

figure(2);
hs=subplot(211); if hold_flag, hold on, else hold off, end
hp=plot(TIME,THETADGCR,cc1,TIME,ALPHA_CR,cc2);
set(hp,'linewidth',lw); %grid on;
set(hs,'fontsize',fs);
ylabel('(deg)');
title('\theta, \alpha (--)')
axis tight
%set(hs,'xticklabel',[]);
hs=subplot(212); if hold_flag, hold on, else hold off, end
hp=plot(TIME,ELEVATOR,cc1);
set(hp,'linewidth',lw); %grid on;
set(hs,'fontsize',fs);
ylabel('(deg)');
xlabel('t (sec)');
title('\delta_e');
axis tight


figure(3);
hs=subplot(211); if hold_flag, hold on, else hold off, end
hp=plot(TIME,PDEG_CR,cc1,TIME,P_CMD*180/pi,cc2);
set(hp,'linewidth',lw); %grid on;
set(hs,'fontsize',fs);
ylabel('(deg/s)');
title('p, p_c (--)')
axis tight
%set(hs,'xticklabel',[]);
hs=subplot(212); if hold_flag, hold on, else hold off, end
hp=plot(TIME,BETA_CR,cc1,TIME,BETA_CMD*180/pi,cc2);
set(hp,'linewidth',lw); %grid on;
set(hs,'fontsize',fs);
ylabel('(deg)');
xlabel('t (sec)');
title('\beta, \beta_c (--)');
axis tight


figure(4);
hs=subplot(211); if hold_flag, hold on, else hold off, end
hp=plot(TIME,PHIDGCR,cc1,TIME,5*RUDDER,cc2);
set(hp,'linewidth',lw); %grid on;
set(hs,'fontsize',fs);
ylabel('(deg)');
title('\phi, 5\delta_r (--)')
axis tight
%set(hs,'xticklabel',[]);
hs=subplot(212); if hold_flag, hold on, else hold off, end
hp=plot(TIME,AILERONR,cc1,TIME,SPLR_RO,cc2,TIME,SPLR_LO,cc3);
set(hp,'linewidth',lw); %grid on;
set(hs,'fontsize',fs);
ylabel('(deg)');
xlabel('t (sec)');
title('\delta_{aR}, \delta_{spR} (--), \delta_{spL} (-.)');
axis tight


figure(5); 
hs=subplot(211); if hold_flag, hold on, else hold off, end
hp=plot(TIME,ID_SIGNAL,cc1,TIME,ID_TH_OUT,cc2);
set(hp,'linewidth',lw); %grid on;
set(hs,'fontsize',fs);
ylabel(' ');
title('ID-signal, ID-threshold (--)');
axis tight
%set(hs,'xticklabel',[]);
hs=subplot(212); if hold_flag, hold on, else hold off, end
hp=plot(TIME,ID_FLAG,cc1);
set(hp,'linewidth',lw); %grid on
set(hs,'fontsize',fs);
ylabel(' ');
xlabel('t (sec)');
title('ID-flag')
axis tight

PSTICKF_LP = [];
WHEELF_LP  = [];
PEDALF_LP  = [];
WORKLOAD   = [];
TIME_SFT = TIME-TIME(1);
sim('workload');
if length(TIME_SFT) ~= length(PSTICKF_LP)
    PSTICKF_LP(end+1) = PSTICKF_LP(end);
    WHEELF_LP(end+1)  = WHEELF_LP(end);
    PEDALF_LP(end+1)  = PEDALF_LP(end);
    WORKLOAD(end+1)   = WORKLOAD(end);    
end

figure(6);
hs=subplot(211); if hold_flag, hold on, else hold off, end
hp=plot(TIME,PSTICKF_LP,cc1,TIME,WHEELF_LP,cc2,TIME,PEDALF_LP,cc3);
set(hp,'linewidth',lw); %grid on;
set(hs,'fontsize',fs);
ylabel('(lbf)');
title('Stick Force, Wheel Force (--), Pedal Force (-.)');
axis tight
%set(hs,'xticklabel',[]);
hs=subplot(212); if hold_flag, hold on, else hold off, end
hp=plot(TIME,WORKLOAD,cc1);
set(hp,'linewidth',lw); %grid on
set(hs,'fontsize',fs);
ylabel('(lbf)');
xlabel('t (sec)');
title('Integrated Workload')
axis tight


figure(7);
hs=subplot(211); if hold_flag, hold on, else hold off, end
hp=plot(TIME,QBAR_CR,cc1);
set(hp,'linewidth',lw); %grid on;
set(hs,'fontsize',fs);
ylabel('lbf/ft^2');
title('Qbar');
axis tight
%set(hs,'xticklabel',[]);
hs=subplot(212); if hold_flag, hold on, else hold off, end
hp=plot(TIME,CAS_CR,cc1);
set(hp,'linewidth',lw); %grid on
set(hs,'fontsize',fs);
ylabel('(knots)');
xlabel('t (sec)');
title('CAS')
axis tight

figure(8);
hs=subplot(211); if hold_flag, hold on, else hold off, end
hp=plot(TIME,ALT_CR,cc1);
set(hp,'linewidth',lw); %grid on;
set(hs,'fontsize',fs);
ylabel('(ft)');
title('h');
axis tight
%set(hs,'xticklabel',[]);
% hs=subplot(212);
% hp=plot(TIME,SY,cc1);
% set(hp,'linewidth',lw); %grid on
% set(hs,'fontsize',fs);
% ylabel('y (ft)');
% xlabel('t (sec)');
% title('y')
% axis tight
ALTDOT_CR = [];
for ii=1:(length(ALT_CR)-1)
    ALTDOT_CR(1,ii) = (ALT_CR(ii+1)-ALT_CR(ii))/0.02;
end
ALTDOT_CR(1,ii+1) = 0;
hs=subplot(212); if hold_flag, hold on, else hold off, end
hp=plot(TIME,ALTDOT_CR,cc1);
set(hp,'linewidth',lw); %grid on
set(hs,'fontsize',fs);
ylabel('(ft)');
xlabel('t (sec)');
title('dh/dt')
axis tight

figure(9)
hs=subplot(1,1,1); if hold_flag, hold on, else hold off, end
hp=plot3(SX,SY,-SZ,cc1);
set(hp,'linewidth',lw); grid on
set(hs,'fontsize',fs);
xlabel('x (ft)');
ylabel('y (ft)');
zlabel('h (ft)');
title('Trajectory')
axis tight
[AZ,EL] = view;
view(-AZ,EL);

if FC == 1
    figure(10)
    if ~hold_flag
        hs=subplot(1,1,1); 
        %fill([0 10000 10000 0],[-150 -150 150 150],'r')
        fill([-500 500 500 -500]+3000,[-50 -50 50 50],'y')
        hold on;
        fill([-500 500 500 -500]/2+3000,[-25 -25 25 25],'g')        
        hp=plot(SX,SY,cc1);
        hold off
        set(hp,'linewidth',lw); grid on
        set(hs,'fontsize',fs);
        xlabel('x (ft)');
        ylabel('y (ft)');
        title('X-Y Trajectory')
        v = axis;
        axis([v(1) v(2)+1000 v(3) -v(3)]);
        hold on;
        fill([v(1) v(2) v(2) v(1)],[-1 -1 1 1],'k')
        hold off
    else
        hold on
        hp=plot(SX,SY,cc1);
        set(hp,'linewidth',lw); grid on
        set(hs,'fontsize',fs);
        xlabel('x (ft)');
        ylabel('y (ft)');
        title('X-Y Trajectory')
    end
end


% CALCULATIONS

H_4_16_ratio = (1-H_CT_4_16(end)/H_CT_4_16(1))*100;
H_5_17_ratio = (1-H_CT_5_17(end)/H_CT_5_17(1))*100;
H_6_18_ratio = (1-H_CT_6_18(end)/H_CT_6_18(1))*100;
H_4_18_ratio = (1-H_CT_4_18(end)/H_CT_4_18(1))*100;
H_6_16_ratio = (1-H_CT_6_16(end)/H_CT_6_16(1))*100;

disp(' ');
fprintf('CLda_old = %.2f \t CLda_new = %.2f \t Failure = %.2f %%\n',H_CT_4_16(1),H_CT_4_16(end),H_4_16_ratio);
fprintf('CMde_old = %.2f \t CMde_new = %.2f \t Failure = %.2f %%\n',H_CT_5_17(1),H_CT_5_17(end),H_5_17_ratio);
fprintf('CNdr_old = %.2f \t CNdr_new = %.2f \t Failure = %.2f %%\n',H_CT_6_18(1),H_CT_6_18(end),H_6_18_ratio);
fprintf('CLdr_old = %.2f \t CLdr_new = %.2f \t Failure = %.2f %%\n',H_CT_4_18(1),H_CT_4_18(end),H_4_18_ratio);
fprintf('CNda_old = %.2f \t CNda_new = %.2f \t Failure = %.2f %%\n',H_CT_6_16(1),H_CT_6_16(end),H_6_16_ratio);
disp(' ');



