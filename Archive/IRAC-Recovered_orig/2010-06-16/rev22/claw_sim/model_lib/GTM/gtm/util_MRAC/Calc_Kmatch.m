% CALCULATES HOW WELL THE ADAPTATION MATCHES WITH THE IDEAL VALUE

% Kxnom  - baseline controller feedback gain
% Kxstar - total ideal feedback gain (baseline + adaptive)
% Kxhat  - adaptive controller feedback gain
%
% Need to compare:
%
% Kxhat with (Kxstar-Kxnom)
%

warning off

flag_disp = 0;

Kxhat = uad_conv(:,[1 3 5]);

% ====================================================
% Controller parameter match
for ii = 1:3
    Kmatch(ii) = Kxhat(end,ii)/(Kxstar(ii)-Kxnom(ii))*100;
end


% ====================================================
% Plant parameter match:
%
% Find p1, p2, p3 - given K1, K2, K3

% Use the following:
% K1 = 1/p3;
% K2 = ((1-p2)*Mq + Md*Kq)/(p3*Md*Kq);
% K3 = ((1-p1)*Ma + Md*Ka)/(p3*Md*Ka);
% 
% KqIstar = K1*KqI;
% Kqstar  = K2*Kq;
% Kastar  = K3*Ka;
% Kxstar  = [KqIstar Kqstar Kastar]';

K1_est = Kxhat(:,1)/KqI;
K2_est = Kxhat(:,2)/Kq;
K3_est = Kxhat(:,3)/Ka;

p3_est = 1./K1_est;
p2_est = 1 - (K2_est./K1_est - 1)*Md*Kq/Mq;
p1_est = 1 - (K3_est./K1_est - 1)*Md*Ka/Ma;

p_true = [p1 p2 p3];
p_est  = [p1_est p2_est p3_est];

if flag_disp
    fprintf('\nK param match (KqI,Kq,Ka) : %.1f%% %.1f%% %.1f%%\n',...
        Kmatch(1),Kmatch(2),Kmatch(3));
    fprintf('Injected fault (p1,p2,p3) : %.2f %.2f %.2f\n' ,p1,p2,p3);
    fprintf('Estimated fault (p1,p2,p3): %.2f %.2f %.2f\n' ,p1_est(end),p2_est(end),p3_est(end));
end

warning on














