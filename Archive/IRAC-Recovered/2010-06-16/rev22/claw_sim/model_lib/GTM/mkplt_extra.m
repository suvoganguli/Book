% mkplt_extra - called after mkplt.m

line3 = '-.';

flag_holdplot = 1;
flag_drawspeclines = 0;

% this needs to be updated when we change 'load MWS_fcase1'
% alpha_trim = 0; %atan(MWS_new.StatesInp(3)/MWS_new.StatesInp(1))*180/pi; % deg

% if config.flag_compare_with_lin
%      
%     dirname = pwd;
%     data_path = fullfile(dirname,'..','..','..',...
%         '2009 - Matured Analysis Software (Jun 2010)','data');
%     clear dir
%     dir(data_path);    
%     filename = input('Enter matfilename (or 0 to quit): ','s');
%     [dum1,name,ext,dum3] = fileparts(filename);
%     if strcmp(name,'0')
%         config.flag_compare_with_lin = 0;
%         return
%     end
% end
if config.flag_compare_with_lin
    
    load 06-24-2010_Expt1_Run4
%     if isempty(ext)
%         filename_ext = [filename '.mat'];
%     else
%         filename_ext = filename;
%     end
%     full_filename = fullfile(data_path,filename_ext);    
%     eval(['load(''' full_filename ''')']);

    t_lin   = dataall.simdata{1}.out.t;
    
    qc_lin  = dataall.simdata{1}.out.r;
    q_lin   = dataall.simdata{1}.out.q;    
    qm_lin  = dataall.simdata{1}.out.xm(:,2);
    
    alpha_lin   = dataall.simdata{1}.out.alpha;
    alpham_lin  = dataall.simdata{1}.out.xm(:,3);
    
    nz_lin      = dataall.simdata{1}.out.nz;
    
    elev_tot_lin    = dataall.simdata{1}.out.u;
    elev_nom_lin    = dataall.simdata{1}.out.ubl;
    elev_ad_lin     = dataall.simdata{1}.out.uad;
    
    elev_ad_lin = squeeze(elev_ad_lin);
        
    Kxhat1_lin  = dataall.simdata{1}.out.Kxhat(:,1);
    Kxhat2_lin  = dataall.simdata{1}.out.Kxhat(:,2);
    Kxhat3_lin  = dataall.simdata{1}.out.Kxhat(:,3);
    
    uw_lin      = dataall.simdata{1}.out.xp(:,[1 2]);
    u_lin       = uw_lin(:,1) + TrimPt.Xtrim(1);
    w_lin       = uw_lin(:,2) + TrimPt.Xtrim(3);
    V_lin       = (u_lin.^2 + w_lin.^2).^(0.5);
    
    % overwriting previous value
    alpha_trim = atan(TrimPt.Xtrim(3)/TrimPt.Xtrim(1))*180/pi;
    
end

if length(size(uad_x)) == 3
    uad_x = squeeze(uad_x);
    uad_x = uad_x';
end


if length(size(uad_xm)) == 3
    uad_xm = squeeze(uad_xm);
    uad_xm = uad_xm';
end

% =======================================================
% q and qm compared to qc
figure(101);

subplot(211)
if flag_holdplot, hold on; else hold off; end
plot(t1(tm1),cvc(tm1,2)*180/pi,'m',t(tm),x_pqr(tm,2)*180/pi,line1);
ylabel('q (deg/s)');
legend('cmd','NL','Location','Best');

if config.flag_compare_with_lin
   hold on
   plot(t_lin,q_lin*180/pi,line3);
   legend('cmd','NL','L','Location','Best');   
   plot(t_lin,qc_lin*180/pi,'m');   % can omit this if same
end


subplot(212)
if flag_holdplot, hold on; else hold off; end
plot(t1(tm1),cvc(tm1,2)*180/pi,'m',t1(tm1),uad_xm(tm1,2)*180/pi,line1);
ylabel('qm (deg/s)');
legend('cmd','NL','Location','Best');
xlabel('time (sec)')


if config.flag_compare_with_lin
   hold on
   plot(t_lin,qm_lin*180/pi,line3);
   legend('cmd','NL','L','Location','Best'); 
   plot(t_lin,qc_lin*180/pi,'m'); % can omit this if same
end

% =======================================================
% q-qm and de
figure(102)

subplot(211)
if flag_holdplot, hold on; else hold off; end
plot(t1(tm1),(uad_x(tm1,2)-uad_xm(tm1,2))*180/pi,line1);
ylabel('q-qm (deg/s)');

if config.flag_compare_with_lin
   hold on
   plot(t_lin,(q_lin-qm_lin)*180/pi,line3);
   legend('NL','L','Location','Best'); 
end

subplot(212)
if flag_holdplot, hold on; else hold off; end
plot(t1(tm1),elev_total(tm1),line1);
ylabel('elev: total (deg)');
xlabel('time (sec)')

if config.flag_compare_with_lin
   hold on
   plot(t_lin,elev_tot_lin,line3);
   legend('NL','L','Location','Best'); 
end

% =======================================================
% de_nom and de_adapt
figure(103);

subplot(211)
if flag_holdplot, hold on; else hold off; end
plot(t1(tm1),elev_nom(tm1),line1);
ylabel('elev: nom (deg)');

if config.flag_compare_with_lin
   hold on
   plot(t_lin,elev_nom_lin,line3);
   legend('NL','L','Location','Best'); 
end


subplot(212)
if flag_holdplot, hold on; else hold off; end
plot(t1(tm1),squeeze(elev_adap(tm1)),line1);
ylabel('elev: adapt (deg)');
xlabel('time (sec)')

if config.flag_compare_with_lin
   hold on
   plot(t_lin,elev_ad_lin,line3);
   legend('NL','L','Location','Best'); 
end


% =======================================================
% alpha, V

figure(104);

subplot(211)
plot(t1(tm1),uad_x(tm1,3)*180/pi+alpha_trim,line1);
ylabel('alpha (deg)');
xlabel('time (sec)')

if config.flag_compare_with_lin
   hold on
   plot(t_lin,alpha_lin*180/pi+alpha_trim,line3);
   legend('NL','L','Location','Best'); 
end

subplot(212)
plot(t(tm),vel_scaling(1)*vchigam(tm,1),line1)
ylabel('V (ft/s)');
xlabel('time (sec)')

if config.flag_compare_with_lin
   hold on
   plot(t_lin,V_lin,line3);
   legend('NL','L','Location','Best'); 
end

% =======================================================
% nz

figure(105);

subplot(1,1,1);
plot(t(tm),accel_scaling*y_accel_cg(tm,3),line1)
ylabel('nz (g)');
xlabel('time (sec)')

if config.flag_compare_with_lin
   hold on
   plot(t_lin,-nz_lin-1,line3);
   legend('NL','L','Location','Best'); 
end

disp('Need to check nz');

% =======================================================
% Kxhat

figure(106);

subplot(311);
if flag_holdplot, hold on; else hold off; end
plot(t1(tm1),uad_conv(tm1,2),['g' line1],t1(tm1),uad_conv(tm1,1),line1);
ylabel('Khat_{qerror}');

if config.flag_compare_with_lin
   hold on
   plot(t_lin,Kxhat1_lin,line3);
   %legend('Ideal','NL','L','Location','Best'); 
end

subplot(312);
if flag_holdplot, hold on; else hold off; end
plot(t1(tm1),uad_conv(tm1,4),['g' line1],t1(tm1),uad_conv(tm1,3),line1);
ylabel('Khat_{q}');

if config.flag_compare_with_lin
   hold on
   plot(t_lin,Kxhat2_lin,line3);
   %legend('Ideal','NL','L','Location','Best'); 
end

subplot(313);
if flag_holdplot, hold on; else hold off; end
plot(t1(tm1),uad_conv(tm1,6),['g' line1],t1(tm1),uad_conv(tm1,5),line1);
ylabel('Khat_{alpha}');
xlabel('time (sec)')

if config.flag_compare_with_lin
   hold on
   plot(t_lin,Kxhat3_lin,line3);
   legend('Ideal','NL','L','Location','Best'); 
end


% =======================================================
% p1, p2, p3

Calc_Kmatch
npt = length(t1);

figure(107)

subplot(311);
if flag_holdplot, hold on; else hold off; end
plot(t1(tm1),p1*ones(npt,1),['g' line1],t1(tm1),p1_est(tm1),line1);
v = axis; axis([v(1) v(2) -5 5]);
%axis tight
ylabel('p1');

subplot(312);
if flag_holdplot, hold on; else hold off; end
plot(t1(tm1),p2*ones(npt,1),['g' line1],t1(tm1),p2_est(tm1),line1);
v = axis; axis([v(1) v(2) -10 5]);
%axis tight
ylabel('p2');

subplot(313);
if flag_holdplot, hold on; else hold off; end
plot(t1(tm1),p3*ones(npt,1),['g' line1],t1(tm1),p3_est(tm1),line1);
v = axis; axis([v(1) v(2) -0.1 5]);
ylabel('p3');
%axis tight
xlabel('time (sec)')


if flag_drawspeclines
    
    if isempty(datain)
        disp('Need to run linear sim first');
        return
    end
    
    figure(102); subplot(211)
    v = axis;    
    t0p = datain.fix.tcmd2;
    t1p = t0p + datain.fix.acl_time_tr;
    t2p = t1p + (datain.fix.tlength2 - datain.fix.acl_time_tr);    
    % transient spec-line
    hl = line([t0p t1p],fac*[datain.fix.acl_error_tr(tspec_idx) datain.fix.acl_error_tr(tspec_idx)]*180/pi);
    set(hl,'linestyle','-.','color','r');
    hl = line([t0p t1p],-fac*[datain.fix.acl_error_tr(tspec_idx) datain.fix.acl_error_tr(tspec_idx)]*180/pi);
    set(hl,'linestyle','-.','color','r');    
    % steady-state spec-line
    hl = line([t1p t2p],fac*[datain.fix.acl_error_ss(tspec_idx) datain.fix.acl_error_ss(tspec_idx)]*180/pi);
    set(hl,'linestyle','-.','color','r');
    hl = line([t1p t2p],-fac*[datain.fix.acl_error_ss(tspec_idx) datain.fix.acl_error_ss(tspec_idx)]*180/pi);
    set(hl,'linestyle','-.','color','r');
    
    
    figure(104);
    spvec = [1:2];  % vector for subplots
    
    % draw spec line - max alpha during adaptation
    if ~isempty(t_adapton) && ~isempty(t_adaptoff)
        subplot(length(spvec),1,1);
        v = axis;
        hl = line([t_adapton t_adaptoff],[in_alp_adaptphasemax in_alp_adaptphasemax]+alpha_trim);
        set(hl,'linestyle','-.','color','r');
        hl = line([t_adapton t_adaptoff],-[in_alp_adaptphasemax in_alp_adaptphasemax]+alpha_trim);
        set(hl,'linestyle','-.','color','r');
    end
    
    figure(105)
    % draw spec line - max nz during adaptation
    if ~isempty(t_adapton) && ~isempty(t_adaptoff)
        v = axis;
        hl = line([t_adapton t_adaptoff],[in_nzmax in_nzmax]-1);
        set(hl,'linestyle','-.','color','r');
        hl = line([t_adapton t_adaptoff],-[in_nzmax in_nzmax]-1);
        set(hl,'linestyle','-.','color','r');
        %axis(v)  
    end      
    
    
    for ii = 101:103
        figure(ii);
        spvec = [1:2];  % vector for subplots
        % draw time-slots
        for jj = spvec
            subplot(length(spvec),1,jj);
            hold on
            v = axis;
            hl = line([in_tfault in_tfault],[v(3) v(4)]);
            set(hl,'linestyle','-.','color','r');
            if ~isempty(t_adapton)
                hl = line([t_adapton t_adapton],[v(3) v(4)]);
                set(hl,'linestyle','-.','color','k');
            end
            if ~isempty(t_adaptoff)
                hl = line([t_adaptoff t_adaptoff],[v(3) v(4)]);
                set(hl,'linestyle','-.','color','g');
            end
            axis(v)
        end
    end    
    
    for ii = 105:105
        figure(ii);
        spvec = [1:1];  % vector for subplots
        % draw time-slots
        for jj = spvec
            subplot(length(spvec),1,jj);
            hold on
            v = axis;
            hl = line([in_tfault in_tfault],[v(3) v(4)]);
            set(hl,'linestyle','-.','color','r');
            if ~isempty(t_adapton)
                hl = line([t_adapton t_adapton],[v(3) v(4)]);
                set(hl,'linestyle','-.','color','k');
            end
            if ~isempty(t_adaptoff)
                hl = line([t_adaptoff t_adaptoff],[v(3) v(4)]);
                set(hl,'linestyle','-.','color','g');
            end
            axis(v)
        end
    end
    
    for ii = 106:107
        figure(ii);
        spvec = [1:3];  % vector for subplots
        % draw time-slots
        for jj = spvec
            subplot(length(spvec),1,jj);
            hold on
            v = axis;
            hl = line([in_tfault in_tfault],[v(3) v(4)]);
            set(hl,'linestyle','-.','color','r');
            if ~isempty(t_adapton)
                hl = line([t_adapton t_adapton],[v(3) v(4)]);
                set(hl,'linestyle','-.','color','k');
            end
            if ~isempty(t_adaptoff)
                hl = line([t_adaptoff t_adaptoff],[v(3) v(4)]);
                set(hl,'linestyle','-.','color','g');
            end
            axis(v)
        end
    end
    
    
end

