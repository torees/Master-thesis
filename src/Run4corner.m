clear
close all
%Simulation Scenarios



%Controller Gains
Gamma1 = diag([0.08,0.08,0.0698]);
Gamma2 = diag([0.2,0.2,0.1745]);

eta_initial = [5; -1; 0];
nu_initial = [0; 0; 0];

t_sim = 300;
sim('CSAD_model');



figure(1)
hold on

eta_plot = eta_t;
x = eta_plot(:,1);
y = eta_plot(:,2);
plot(y,x,'k','LineWidth',1.5)

tsamp=3;
dec = 4003;
pathplotter(eta_LPLV, tsamp, dec, tout,'r')
hold off
xlabel('East [m]')
ylabel('North [m]')
axis equal
saveas(gcf, 'Simulations/LPLV', 'epsc')











