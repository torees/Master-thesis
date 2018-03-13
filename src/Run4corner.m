clear
close all
%Simulation Scenarios


a = 0.050;
%Controller Gains
Gamma1 = diag([0.08,0.08,0.0698]);
Gamma2 = diag([0.2,0.2,0.1745]);

eta_initial = [5; -1; 0];
nu_initial = [0; 0; 0];

t_sim = 800;
sim('Adaptive_control_CSAD_model');



figure(1)
hold on

eta_plot = eta_t;
x = eta_plot(:,1);
y = eta_plot(:,2);
plot(y,x,'k','LineWidth',1.5)

tsamp=3;
dec = 2003;
pathplotter(eta_L1, tsamp, dec, tout,'r')
hold off
xlabel('East [m]')
ylabel('North [m]')
axis equal
%saveas(gcf, 'Simulations/LPLV', 'epsc')

% figure(2) 
% plot(x_tilde)
% figure(3)
% plot(y_tilde)











