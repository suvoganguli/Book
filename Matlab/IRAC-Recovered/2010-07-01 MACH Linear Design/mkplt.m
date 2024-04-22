if( ~exist('tmin') )
    tmin = -Inf ;
end

if( ~exist('tmax') )
    tmax = Inf ;
end

if( ~exist('plt_title') )
    plt_title = ' ' ;
end

tm = find( t >= tmin & t <= tmax ) ;

figure
if( mode == 4 )
    subplot(3,1,1) , plot(t(tm),x(tm,10),'-',t(tm),posc(tm,1),':')
    title(plt_title)
    ylabel('N (feet)')
    legend('actual','cmd')
    subplot(3,1,2) , plot(t(tm),x(tm,11),'-',t(tm),posc(tm,2),':')
    ylabel('E (feet)')
    subplot(3,1,3) , plot(t(tm),x(tm,12),'-',t(tm),posc(tm,3),':')
    ylabel('h (feet)')
    xlabel('time (sec)')
else
    subplot(3,1,1) , plot(t(tm),x(tm,10))
    title(plt_title)
    ylabel('N (feet)')
    subplot(3,1,2) , plot(t(tm),x(tm,11))
    ylabel('E (feet)')
    subplot(3,1,3) , plot(t(tm),x(tm,12))
    ylabel('h (feet)')
    xlabel('time (sec)')
end

figure
if( mode == 4 )
    subplot(3,1,1) , plot(t(tm),x(tm,7),'-',t(tm),velc(tm,1),':')
    title(plt_title)
    ylabel('Ndot (ft/sec)')
    legend('actual','cmd')
    subplot(3,1,2) , plot(t(tm),x(tm,8),'-',t(tm),velc(tm,2),':')
    ylabel('Edot (ft/sec)')
    subplot(3,1,3) , plot(t(tm),x(tm,9),'-',t(tm),velc(tm,3),':')
    ylabel('hdot (ft/sec)')
    xlabel('time (sec)')
elseif( mode == 3 )
    subplot(3,1,1) , plot(t(tm),x(tm,7),'-',t(tm),velc_in(tm,1),':')
    title(plt_title)
    ylabel('Ndot (ft/sec)')
    legend('actual','cmd')
    subplot(3,1,2) , plot(t(tm),x(tm,8),'-',t(tm),velc_in(tm,2),':')
    ylabel('Edot (ft/sec)')
    subplot(3,1,3) , plot(t(tm),x(tm,9),'-',t(tm),velc_in(tm,3),':')
    ylabel('hdot (ft/sec)')
    xlabel('time (sec)')
else
    subplot(3,1,1) , plot(t(tm),x(tm,7))
    title(plt_title)
    ylabel('Ndot (ft/sec)')
    subplot(3,1,2) , plot(t(tm),x(tm,8))
    ylabel('Edot (ft/sec)')
    subplot(3,1,3) , plot(t(tm),x(tm,9))
    ylabel('hdot (ft/sec)')
    xlabel('time (sec)')
end

figure
if( mode >= 2 )
    subplot(3,1,1) , plot(t(tm),r2d*x(tm,4),'-',t(tm),r2d*attc(tm,1),':')
    title(plt_title)
    ylabel('phi (deg)')
    legend('actual','cmd')
    subplot(3,1,2) , plot(t(tm),r2d*x(tm,5),'-',t(tm),r2d*attc(tm,2),':')
    ylabel('theta (deg)')
    subplot(3,1,3) , plot(t(tm),r2d*x(tm,6),'-',t(tm),r2d*attc(tm,3),':')
    ylabel('psi (deg)')
    xlabel('time (sec)')
% % elseif( mode == 2 & att_type == 2 )
% %     subplot(3,1,1) , plot(t(tm),r2d*x(tm,4),'-',t(tm),r2d*attc_in(tm,1),':')
% %     title(plt_title)
% %     ylabel('phi (deg)')
% %     legend('actual','cmd')
% %     subplot(3,1,2) , plot(t(tm),r2d*x(tm,5),'-',t(tm),r2d*attc_in(tm,2),':')
% %     ylabel('theta (deg)')
% %     subplot(3,1,3) , plot(t(tm),r2d*x(tm,6),'-',t(tm),r2d*attc_in(tm,3),':')
% %     ylabel('psi (deg)')
% %     xlabel('time (sec)')
else
    subplot(3,1,1) , plot(t(tm),r2d*x(tm,4))
    title(plt_title)
    ylabel('phi (deg)')
    subplot(3,1,2) , plot(t(tm),r2d*x(tm,5))
    ylabel('theta (deg)')
    subplot(3,1,3) , plot(t(tm),r2d*x(tm,6))
    ylabel('psi (deg)')
    xlabel('time (sec)')
end

figure
if( mode >= 2 )
    subplot(3,1,1) , plot(t(tm),r2d*mu(tm),'-',t(tm),r2d*mab_cmd(tm,1),':')
    title(plt_title)
    ylabel('mu (deg)')
    legend('actual','cmd')
    subplot(3,1,2) , plot(t(tm),r2d*Vab(tm,2),'-',t(tm),r2d*mab_cmd(tm,2),':')
    ylabel('alpha (deg)')
    subplot(3,1,3) , plot(t(tm),r2d*Vab(tm,3),'-',t(tm),r2d*mab_cmd(tm,3),':')
    ylabel('beta (deg)')
    xlabel('time (sec)')
% % elseif( mode == 2 & att_type == 4 )
% %     subplot(3,1,1) , plot(t(tm),r2d*mu(tm),'-',t(tm),r2d*attc_in(tm,1),':')
% %     title(plt_title)
% %     ylabel('mu (deg)')
% %     legend('actual','cmd')
% %     subplot(3,1,2) , plot(t(tm),r2d*Vab(tm,2),'-',t(tm),r2d*attc_in(tm,2),':')
% %     ylabel('alpha (deg)')
% %     subplot(3,1,3) , plot(t(tm),r2d*Vab(tm,3),'-',t(tm),r2d*attc_in(tm,3),':')
% %     ylabel('beta (deg)')
% %     xlabel('time (sec)')
else
    subplot(3,1,1) , plot(t(tm),r2d*mu(tm))
    title(plt_title)
    ylabel('mu (deg)')
    subplot(3,1,2) , plot(t(tm),r2d*Vab(tm,2))
    ylabel('alpha (deg)')
    subplot(3,1,3) , plot(t(tm),r2d*Vab(tm,3))
    ylabel('beta (deg)')
    xlabel('time (sec)')
end

figure
if( mode >= 2 )
    subplot(3,1,1) , plot(t(tm),r2d*x(tm,1),'-',t(tm),r2d*pqrc(tm,1),':')
    title(plt_title)
    ylabel('p (deg/sec)')
    legend('actual','cmd')
    subplot(3,1,2) , plot(t(tm),r2d*x(tm,2),'-',t(tm),r2d*pqrc(tm,2),':')
    ylabel('q (deg/sec)')
    subplot(3,1,3) , plot(t(tm),r2d*x(tm,3),'-',t(tm),r2d*pqrc(tm,3),':')
    ylabel('r (deg/sec)')
    xlabel('time (sec)')
elseif( mode == 1 )
    subplot(3,1,1) , plot(t(tm),r2d*x(tm,1),'-',t(tm),r2d*pqrc_in(tm,1),':')
    title(plt_title)
    ylabel('p (deg/sec)')
    legend('actual','cmd')
    subplot(3,1,2) , plot(t(tm),r2d*x(tm,2),'-',t(tm),r2d*pqrc_in(tm,2),':')
    ylabel('q (deg/sec)')
    subplot(3,1,3) , plot(t(tm),r2d*x(tm,3),'-',t(tm),r2d*pqrc_in(tm,3),':')
    ylabel('r (deg/sec)')
    xlabel('time (sec)')
else
    subplot(3,1,1) , plot(t(tm),r2d*x(tm,1))
    title(plt_title)
    ylabel('p (deg/sec)')
    subplot(3,1,2) , plot(t(tm),r2d*x(tm,2))
    ylabel('q (deg/sec)')
    subplot(3,1,3) , plot(t(tm),r2d*x(tm,3))
    ylabel('r (deg/sec)')
    xlabel('time (sec)')
end

figure
subplot(4,1,1) , plot(t(tm),u(tm,1),'-',t(tm),uc(tm,1),':')
    title(plt_title)
ylabel('aileron (deg)')
legend('actual','cmd')
subplot(4,1,2) , plot(t(tm),u(tm,2),'-',t(tm),uc(tm,2),':')
ylabel('elevator (deg)')
subplot(4,1,3) , plot(t(tm),u(tm,3),'-',t(tm),uc(tm,3),':')
ylabel('rudder (deg)')
subplot(4,1,4) , plot(t(tm),u(tm,4),'-',t(tm),uc(tm,4),':')
ylabel('throt (deg)')
xlabel('time (sec)')

figure
subplot(3,1,1) , plot(t(tm),axyza(tm,1)/g)
    title(plt_title)
ylabel('axa (g)')
subplot(3,1,2) , plot(t(tm),axyza(tm,2)/g)
ylabel('aya (g)')
subplot(3,1,3) , plot(t(tm),axyza(tm,3)/g)
ylabel('aza (g)')
xlabel('time (sec)')


