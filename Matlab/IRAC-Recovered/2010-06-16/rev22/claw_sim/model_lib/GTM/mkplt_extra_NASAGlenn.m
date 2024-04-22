% mkplt_extra - called after mkplt.m

gcf_vec = [200 200 560 600];

tf_plot = 50; %75;

% =======================================================

figure(100)
subplot(1,1,1); hold on

if( plot_photo )
    photo = imread('testarea.jpg') ;
    xx(1) = -611.0;
    xx(2) = 858.1;
    % N position of pad appears to be off by about 15 ft [2003-08-08 SGP]
    % yy(2)=-1173.5;
    % yy(1)=295.6;
    yy(2) = -1173.5 - 15;
    yy(1) = 295.6 - 15;
    %imshow(photo,'truesize');
    h = image(xx,yy,photo);
    axis xy
    axis image
end

axis equal

if( mode >= modes.pos )
    plot(x(tm,8),x(tm,7),['c' line1],cvc(tm1,cv_pos_idx(2)),cvc(tm1,cv_pos_idx(1)),['r' line2])
    legend_str = {'actual', 'cmd'} ;
else
    plot(x(tm,8),x(tm,7),['c' line1])
    legend_str = {'actual'} ;
end

legend_str = horzcat(legend_str, {'start', 'end'});
plot(x(tm(1),8),x(tm(1),7),'ko',x(tm(end),8),x(tm(end),7),'kx');
if(plot_homing)
    plot(target_pos_IC(2),target_pos_IC(1),'rx');
    legend_str = horzcat(legend_str, 'target');
end

update_legend(legend_str)
xlabel('E (ft)'), ylabel('N (ft)')
printpause

% =======================================================
figure(101);
rate_label = {'p', 'q', 'r'} ;

for iplot = 1:3    
    subplot(3,1,iplot); hold on
    if( show_rate_cmd )
        plot(t(tm),x_pqr(tm,iplot)*180/pi,line1,t1(tm1),cvc(tm1,cv_rate_idx(iplot))*180/pi,line2)
        if( iplot == 1 )
            update_legend('actual','cmd')
        end
    elseif( show_rate_ideal )
        plot(t(tm),x_pqr(tm,iplot)*180/pi,line1,t1(tm1),ideal_pqr(tm1,iplot)*180/pi,line2)
        if( iplot == 1 )
            update_legend('actual','ideal')
        end
    else
        plot(t(tm),x_pqr(tm,iplot))
        if( iplot == 1 )
            update_legend('actual')
        end
    end
    ylabel([rate_label{iplot} ' (deg/sec)'])
end

xlabel('time (sec)')
%set(gcf,'Position',gcf_vec);
subplot(311); v = axis; axis([0 tf_plot v(3) v(4)]);
subplot(312); v = axis; axis([0 tf_plot v(3) v(4)]);
subplot(313); v = axis; axis([0 tf_plot v(3) v(4)]);
printpause

% =======================================================

figure(102);

full_surf_obac_ulim = [u_ulim_rate u_ulim_vel(:,3:end)] ;
full_surf_obac_llim = [u_llim_rate u_llim_vel(:,3:end)] ;
full_surf_trac_ulim = max(u_servo,full_surf_trac_ulim) ;
full_surf_trac_llim = min(u_servo,full_surf_trac_llim) ;

% The following only works correctly with plot overlays if show_surf_limits
% is false.
pstr = strcat({'b', 'r', 'b', 'r', 'b', 'r'},{line1 line1 line2 line2 line2 line2}) ;
if(~show_surf_limits)
    pstr = pstr(1:end-4);
end

if(use_throt)
    % add throt plot
    uidx = [uidx MACH.throttle_idx] ;
end
unames = MACH.u_names(uidx);
uunits = MACH.u_units(uidx);

nsub = 3 ; % number of subplots per figure
isub = 0 ;
for i = [1 2 3]; %1:length(uidx)
    
    idx = uidx(i) ;
    
    isub = isub + 1 ;
    if( isub > nsub )
        figure(gcf+1)
        isub = 1 ;
    end

    plot_mat = [ u(tm1,idx) u_servo(tm1,idx) ] ;
    
    if(show_surf_limits)
        plot_mat = [ plot_mat ...
            full_surf_obac_ulim(tm1,i) ...
            full_surf_trac_ulim(tm1,idx) ...
            full_surf_obac_llim(tm1,i) ...
            full_surf_trac_llim(tm1,idx) ...
            ] ;
    end

    subplot(nsub,1,isub); hold on
    if(show_surf_limits)
        ulim = max(max(plot_mat)) ;
        llim = min(min(plot_mat)) ;
        if( ulim ~= llim )
            axis([t1min t1max 1.1*llim-0.1*ulim 1.1*ulim-0.1*llim]) ;
        end
    end

    % Note: (x+eps)-eps will round any abs(x) below eps^2 to zero, to avoid a
    % bug in plot for unnormalized numbers
    for iplot = 1:length(pstr)
        plot(t1plot, (plot_mat(:,iplot)+eps)-eps, pstr{iplot})
    end
    ylabel(sprintf('%s (%s)', unames{i}, uunits{i}))
    if( isub == 1 )
        update_legend('command','servo')
    end
    
    if( isub == nsub )
        xlabel('time (sec)')
        printpause
    end
end

%set(gcf,'Position',gcf_vec);
subplot(311); v = axis; axis([0 tf_plot v(3) v(4)]);
subplot(312); v = axis; axis([0 tf_plot v(3) v(4)]);
subplot(313); v = axis; axis([0 tf_plot -1 +1]);

% =======================================================


figure(103);

full_surf_obac_ulim = [u_ulim_rate u_ulim_vel(:,3:end)] ;
full_surf_obac_llim = [u_llim_rate u_llim_vel(:,3:end)] ;
full_surf_trac_ulim = max(u_servo,full_surf_trac_ulim) ;
full_surf_trac_llim = min(u_servo,full_surf_trac_llim) ;

pstr = [{'b-'},{'r-.'}];

if(use_throt)
    % add throt plot
    uidx = [uidx MACH.throttle_idx] ;
end
unames = MACH.u_names(uidx);  % 'elev'    'ail'    'rud'    'stab'    'elevgain'    'throtdiff'    'throt'    'tvc_m'    'tvc_n'    'rcs00'
uunits = MACH.u_units(uidx);

%nsub = 4 ; % number of subplots per figure
isub = 0 ;

% subplot 411
subplot(411); hold on
i = 7;
idx = uidx(i) ;
isub = isub + 1 ;
plot_mat = [ u(tm1,idx) u_servo(tm1,idx) ] ;
if(show_surf_limits)
    plot_mat = [ plot_mat ...
        full_surf_obac_ulim(tm1,i) ...
        full_surf_trac_ulim(tm1,idx) ...
        full_surf_obac_llim(tm1,i) ...
        full_surf_trac_llim(tm1,idx) ...
        ] ;
end
%subplot(nsub,1,isub); hold on
if(show_surf_limits)
    ulim = max(max(plot_mat)) ;
    llim = min(min(plot_mat)) ;
    if( ulim ~= llim )
        axis([t1min t1max 1.1*llim-0.1*ulim 1.1*ulim-0.1*llim]) ;
    end
end
% Note: (x+eps)-eps will round any abs(x) below eps^2 to zero, to avoid a
% bug in plot for unnormalized numbers
for iplot = 1:length(pstr)
    plot(t1plot, (plot_mat(:,iplot)+eps)-eps, pstr{iplot})
end

ylabel(sprintf('%s (%s)', unames{i}, uunits{i}))
if( isub == 1 )
    update_legend('command','servo')
end
plot_mat_C = plot_mat;

% subplot 412
subplot(412); hold on
i = 6;
idx = uidx(i) ;
isub = isub + 1 ;
plot_mat = [ u(tm1,idx) u_servo(tm1,idx) ] ;
if(show_surf_limits)
    plot_mat = [ plot_mat ...
        full_surf_obac_ulim(tm1,i) ...
        full_surf_trac_ulim(tm1,idx) ...
        full_surf_obac_llim(tm1,i) ...
        full_surf_trac_llim(tm1,idx) ...
        ] ;
end
%subplot(nsub,1,isub); hold on
if(show_surf_limits)
    ulim = max(max(plot_mat)) ;
    llim = min(min(plot_mat)) ;
    if( ulim ~= llim )
        axis([t1min t1max 1.1*llim-0.1*ulim 1.1*ulim-0.1*llim]) ;
    end
end
% Note: (x+eps)-eps will round any abs(x) below eps^2 to zero, to avoid a
% bug in plot for unnormalized numbers
for iplot = 1:length(pstr)
    plot(t1plot, (plot_mat(:,iplot)+eps)-eps, pstr{iplot})
end
ylabel(sprintf('%s (%s)', unames{i}, uunits{i}))
if( isub == 1 )
    update_legend('command','servo')
end
plot_mat_D = plot_mat;

% transformation
% D = (R-L)/2, C = (R+L)/2; 
% L = C - D;  R = C + D;
plot_mat_L = plot_mat_C - plot_mat_D; 
plot_mat_R = plot_mat_C + plot_mat_D; 

% subplot 413
subplot(413); hold on
% Note: (x+eps)-eps will round any abs(x) below eps^2 to zero, to avoid a
% bug in plot for unnormalized numbers
for iplot = 1:length(pstr)
    plot(t1plot, (plot_mat_R(:,iplot)+eps)-eps, pstr{iplot})
end
ylabel(sprintf('%s (%s)', 'throt-R','%'));
if( isub == 1 )
    update_legend('command','servo')
end

% subplot 414
subplot(414); hold on
% Note: (x+eps)-eps will round any abs(x) below eps^2 to zero, to avoid a
% bug in plot for unnormalized numbers
for iplot = 1:length(pstr)
    plot(t1plot, (plot_mat_L(:,iplot)+eps)-eps, pstr{iplot})
end
ylabel(sprintf('%s (%s)', 'throt-L','%'));
if( isub == 1 )
    update_legend('command','servo')
end

xlabel('time (sec)')
printpause
set(gcf,'Position',gcf_vec);

% ================================================

for ii = [2 23 25]
    figure(ii)
    subplot(311); v = axis; axis([0 tf_plot v(3) v(4)]);
    subplot(312); v = axis; axis([0 tf_plot v(3) v(4)]);
    subplot(313); v = axis; axis([0 tf_plot v(3) v(4)]);
end

%% Plots for NASA Glenn Visit (1/28/2010)

disp(' ');
disp('1. Blue - solid');
disp('2. Red - dashdot');
disp('3. Green - dashed');
ans_lspec = input('Enter choice [1-3]: ');

lw = 2;
mk = 10;
switch(ans_lspec)
    case 1
        lspec = {'b-'};        
    case 2
        lspec = {'r-.'};
    case 3
        lspec = {'g--'};
end


% Plot: beta, mu ================================================

figure(104); 

att_label = {'mu', 'alpha', 'beta'} ;
y_att = y_mab ;

ideal_att_active = [] ;
if( show_att_cmd )
    att_cmds = mab_cmds ;
elseif( show_att_ideal )
    ideal_att = ideal_mab ;
    ideal_att_active = intersect(find(att_type_tw == att_type.mba_bank | att_type_tw == att_type.mba_skid),tm1);
end

iplot_counter = 1;
for iplot = [3 1]
    subplot(2,1,iplot_counter); hold on
%     if( show_att_cmd )
%         plot(t(tm),att_scaling*y_att(tm,iplot),line1,t1(tm1),att_scaling*att_cmds(tm1,iplot),line2)
%         if( iplot == 1 )
%             update_legend('actual','cmd')
%         end
%     elseif( ~isempty(ideal_att_active) )
%         plot(t(tm),att_scaling*y_att(tm,iplot),line1,t1(ideal_att_active),att_scaling*ideal_att(ideal_att_active,iplot),line2)
%         if( iplot == 1 )
%             update_legend('actual','ideal')
%         end
%     else
        hp = plot(t(tm),att_scaling*y_att(tm,iplot),lspec{1});
        set(hp,'linewidth',lw);
        v = axis;
        axis([0 round(t(end)) v(3) v(4)]);
%         if( iplot == 1 )
%             update_legend('actual')
%         end
%     end
    ylabel([att_label{iplot} ' (' att_units ')'])
    iplot_counter = iplot_counter+1;
end

xlabel('time (sec)')
printpause

% Plot: circle ================================================

figure(105)
subplot(1,1,1); hold on

axis equal

legend_str = horzcat([], {'start', 'end'});
hp = plot(x(tm(1),8),x(tm(1),7),'ko',x(tm(end),8),x(tm(end),7),'kx');
set(hp,'linewidth',lw,'markersize',mk);

% if( mode >= modes.pos )
%     plot(x(tm,8),x(tm,7),['c' line1],cvc(tm1,cv_pos_idx(2)),cvc(tm1,cv_pos_idx(1)),['r' line2])
%     legend_str = {'actual', 'cmd'} ;
% else
    hp = plot(x(tm,8),x(tm,7),lspec{1});
    set(hp,'linewidth',lw);
    %legend_str = {'actual'} ;
%end


% if(plot_homing)
%     plot(target_pos_IC(2),target_pos_IC(1),'rx');
%     legend_str = horzcat(legend_str, 'target');
% end

if ans_lspec == 1
    update_legend(legend_str);
end
xlabel('E (ft)'), ylabel('N (ft)')
printpause

% Plot: throt C and D ================================================


figure(106);

% subplot 211
subplot(211); hold on
% Note: (x+eps)-eps will round any abs(x) below eps^2 to zero, to avoid a
% bug in plot for unnormalized numbers
for iplot = 1:length(lspec)
    hp = plot(t1plot, (plot_mat_C(:,iplot)+eps)-eps, lspec{1});
    set(hp,'linewidth',lw);
end
ylabel(sprintf('%s (%s)', 'throt-(R+L)/2','%'));
% if( isub == 1 )
%     update_legend('command','servo')
% end

% subplot 212
subplot(212); hold on
% Note: (x+eps)-eps will round any abs(x) below eps^2 to zero, to avoid a
% bug in plot for unnormalized numbers
for iplot = 1:length(lspec)
    hp = plot(t1plot, (plot_mat_D(:,iplot)+eps)-eps, lspec{1});
    set(hp,'linewidth',lw);
end
ylabel(sprintf('%s (%s)', 'throt-(R-L)/2','%'));
% if( isub == 1 )
%     update_legend('command','servo')
% end

xlabel('time (sec)')
printpause




% Plot: throt L and R ================================================

figure(107);

% subplot 211
subplot(211); hold on
% Note: (x+eps)-eps will round any abs(x) below eps^2 to zero, to avoid a
% bug in plot for unnormalized numbers
for iplot = 1:length(lspec)
    hp = plot(t1plot, (plot_mat_R(:,iplot)+eps)-eps, lspec{1});
    set(hp,'linewidth',lw);
end
ylabel(sprintf('%s (%s)', 'throt-R','%'));
% if( isub == 1 )
%     update_legend('command','servo')
% end

% subplot 212
subplot(212); hold on
% Note: (x+eps)-eps will round any abs(x) below eps^2 to zero, to avoid a
% bug in plot for unnormalized numbers
for iplot = 1:length(lspec)
    hp = plot(t1plot, (plot_mat_L(:,iplot)+eps)-eps, lspec{1});
    set(hp,'linewidth',lw);
end
ylabel(sprintf('%s (%s)', 'throt-L','%'));
% if( isub == 1 )
%     update_legend('command','servo')
% end

xlabel('time (sec)')
printpause










