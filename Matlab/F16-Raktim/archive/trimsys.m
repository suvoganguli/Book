function trimsys()

clear

% x = phi tht psi p q r u v w Xe Ye Ze

x0 = [0
      0
      0
      0
      0
      0
      91.44
      0
      0
      0
      0
      -1000];

u0 = [0; 0];
Vt = 91.44;

figure(1); clf

options = optimset('Display','iter');
U = fminunc(@(u) cost(u,Vt),u0,options)

end

function f = cost(u,Vt)

assignin('base',ele = u(1));
assignin('base',ail = u(2));
assignin('base',rud = 0);
assignin('base',lef = 0);

sim('F16_trim');

figure(1);
clf
subplot(211); hold on
plot(omega_out.Time,omega_out.Data(:,:)*180/pi)
ylim([-2 2])
legend('p','q','r')
subplot(212); hold on
plot(Vt_out.Time,Vt_out.Data)
ylim([80 100])

f = 180/pi*norm(omega_out.Data(:,1)) + ...
    180/pi*norm(omega_out.Data(:,2)) + ...
    180/pi*norm(omega_out.Data(:,3)) + ...
    0*180/pi*norm(beta_out.Data) + ...
    norm(Vt_out.Data-Vt) + ...
    180/pi*max(abs(omega_out.Data(:,1))) + ...
    180/pi*max(abs(omega_out.Data(:,2))) + ...
    180/pi*max(abs(omega_out.Data(:,3))) + ...
    max(abs(Vt_out.Data-Vt));

end
