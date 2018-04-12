close all

figure(1)
hold on

eta_plot = [5 -1 0;eta_t];
x = eta_plot(:,1);
y = eta_plot(:,2);
%plot(y,x,'-r','LineWidth',1.5)
tsamp=3;
dec = 3000;
pathtrackplotter_mclab(eta_t', tsamp, dec, '-.r', '--r')


switch controller
    
    case 1
        %pathplotter(eta_L1, tsamp, dec, tout,'b')
        pathtrackplotter_mclab(eta_L1', tsamp, dec, '-.b', 'b')
    case 2
        pathplotter(eta_II, tsamp, dec, tout,'b')
    otherwise
end

h(1) = plot(NaN,NaN,'b','LineWidth',1.5);
h(2) = plot(NaN,NaN,'r','LineWidth',1.5);
legend(h, 'CSAD','Reference','Location','best');
hold off
xlabel('East [m]')
ylabel('North [m]')
axis equal
%saveas(gcf, 'Simulations/LPLV', 'epsc')


figure(2)

surge = subplot(3,1,1);
hold on
plot(tau_ts_surge,'b','LineWidth',1.5)
title('Commanded input')
ylabel('\tau_1 [N]')
grid on
hold off
xlim([0 t_sim])
sway = subplot(3,1,2);
title('')
hold on
plot(tau_ts_sway,'b','LineWidth',1.5)
title('')
ylabel('\tau_2 [N]')
grid on
hold off
xlim([0 t_sim])
yaw = subplot(3,1,3);
hold on
plot(tau_ts_yawrate,'b','LineWidth',1.5)
ylabel('\tau_3 [Nm]')
title('')
grid on
%xlabel('Time [s]')
xlim([0 t_sim])
hold off


% METRICS
eta_iae = eta_L1;

figure(3)
subplot(3,1,1);
hold on
plot(e1_IAE,'Linewidth',1.5)
ylabel('IAE')
grid on
title('Pose tracking metrics')
hold off
xlim([0 t_sim])
subplot(3,1,2);
hold on
plot(e1_IAEW,'Linewidth',1.5)
title('')
ylabel('IAEW')
xlim([0 t_sim])
grid on
subplot(3,1,3);
title('')
hold on
plot(e1_IADC,'Linewidth',1.5)
ylabel('IADC')
%xlabel('Time[s]')
title('')
xlim([0 t_sim])
grid on

MaxIAE = max(e1_IAE)
MaxIAEW = max(e1_IAEW)
MaxIADC = max(e1_IADC)


