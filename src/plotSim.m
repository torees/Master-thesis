





%% Pathplotter
f =figure(1);
movegui(f,'northeast');
hold on
xlabel('East [m]')
ylabel('North [m]')
pathtrackplotter_mclab_ref(eta_t1, 10, 3000, 'k', 'k')
pathtrackplotter_mclab(eta1, 10, 3000, 'b', '-.b')
pathtrackplotter_mclab(eta2, 10, 3000,'r', '--r' )
h = zeros(3, 1);
h(1) = plot(NaN,NaN,'-.b','LineWidth',1.5);
h(2) = plot(NaN,NaN,'--r','LineWidth',1.5);
h(3) = plot(NaN,NaN,'k','LineWidth',1.5);
legend(h, 'NP-NV',type,'Reference','Location','none');
axis equal

saveas(gcf,filename,'epsc')

tau1 = tau1';
tau2 = tau2';
eta1 = eta1';
eta3 = eta2';
eta_t1 = eta_t1';








%Do the figure of Metrics

p =figure(3);
movegui(p,'center');
IAE1 = subplot(3,1,1);
hold on
plot(IAE1,e1_IAE1,'b','Linewidth',1.5)
plot(IAE1,e1_IAE2,'-.r','Linewidth',1.5)
ylabel('IAE')
grid on
title('Pose tracking metrics')
hold off
xlim([0 timeendmax-timestartmax])
IAEW1 = subplot(3,1,2);
hold on
plot(IAEW1,eta_iae1(:,1),e1_IAEW1,'b','Linewidth',1.5)
plot(IAEW1,eta_iae2(:,1),e1_IAEW2,'-.r','Linewidth',1.5)
ylabel('IAEW')
legend('NP-NV',type,'Location','best')
xlim([0 timeendmax-timestartmax])
grid on
IADC = subplot(3,1,3);
hold on
plot(IADC,eta_iae1(:,1),e1_IADC1,'b','Linewidth',1.5)
plot(IADC,eta_iae2(:,1),e1_IADC2,'-.r','Linewidth',1.5)
ylabel('IADC')
xlabel('Time[s]')
xlim([0 timeendmax-timestartmax])
grid on
saveas(gcf,filename3,'epsc')

%% Tau
g =figure(2);
movegui(g,'southeast');
surge = subplot(3,1,1);
hold on
plot(tau1(1,:),'b','LineWidth',1.5)
plot(tau2(1,:),'-.r','LineWidth',1.5)
ylabel('\tau_1 [N]')
grid on
hold off
ylim([-4 4])
xlim([0 t_sim])
sway = subplot(3,1,2);
hold on
plot(sway,tau1(2,:),'b','LineWidth',1.5)
plot(sway,tau2(2,:),'-.r','LineWidth',1.5)
ylabel('\tau_2 [N]')
legend('NP-NV',type,'Location','none')
grid on
hold off
ylim([-6 6])
xlim([0 t_sim])
yaw = subplot(3,1,3);
hold on
plot(yaw,tau1(3,:),'b','LineWidth',1.5)
plot(yaw,tau2(3,:),'-.r','LineWidth',1.5)
ylabel('\tau_3 [Nm]')
grid on
xlabel('Time [s]')
ylim([-3 3])
xlim([0 t_sim])
saveas(gcf,filename2,'epsc')


maxim = [max(e1_IAE1) max(e1_IAE2);
        max(e1_IAEW1) max(e1_IAEW2);
        max(e1_IADC1) max(e1_IADC2)]




