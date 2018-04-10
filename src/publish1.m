

figure(1)
hold on

eta_plot = [5 -1 0;eta_t];
x = eta_plot(:,1);
y = eta_plot(:,2);
plot(y,x,'-r','LineWidth',1.5)

tsamp=3;
dec = 5*t_sim;

switch controller
    
    case 1
        pathplotter(eta_L1, tsamp, dec, tout,'b')
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
title('')
surge = subplot(3,1,1);
hold on
plot(tau_ts_surge,'b','LineWidth',1.5)
ylabel('\tau_1 [N]')
grid on
hold off
xlim([0 t_sim])
sway = subplot(3,1,2);
hold on
plot(tau_ts_sway,'b','LineWidth',1.5)
ylabel('\tau_2 [N]')
grid on
hold off
xlim([0 t_sim])
yaw = subplot(3,1,3);
hold on
plot(tau_ts_yawrate,'b','LineWidth',1.5)
ylabel('\tau_3 [Nm]')
grid on
%xlabel('Time [s]')
xlim([0 t_sim])
hold off


% METRICS
eta_iae = eta_L1;

figure(3)
IAE1 = subplot(3,1,1);
hold on
plot(e1_IAE,'Linewidth',1.5)
ylabel('IAE')
grid on
title('Pose tracking metrics')
hold off
xlim([0 t_sim])
IAEW1 = subplot(3,1,2);
hold on
plot(e1_IAEW,'Linewidth',1.5)
ylabel('IAEW')
xlim([0 t_sim])
grid on
IADC = subplot(3,1,3);
hold on
plot(e1_IADC,'Linewidth',1.5)
ylabel('IADC')
xlabel('Time[s]')
xlim([0 t_sim])
grid on

MaxIAE = max(e1_IAE)
MaxIAEW = max(e1_IAEW)
MaxIADC = max(e1_IADC)


