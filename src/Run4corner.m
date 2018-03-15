clear


%Initial conditions
eta_initial = [5; -1; 0];
nu_initial = [0; 0; 0];

%Simulation parameters
t_sim = 800;
controller = 1; %L1 = 1, II = 2, 
sim('Adaptive_control_CSAD_model');



figure(1)
hold on

eta_plot = [5 -1 0;eta_t];
x = eta_plot(:,1);
y = eta_plot(:,2);
plot(y,x,'k','LineWidth',1.5)

tsamp=3;
dec = 5*t_sim;

switch controller
    
    case 1
        pathplotter(eta_L1, tsamp, dec, tout,'r')
    case 2
        pathplotter(eta_II, tsamp, dec, tout,'r')
    otherwise
end

hold off
xlabel('East [m]')
ylabel('North [m]')
axis equal
%saveas(gcf, 'Simulations/LPLV', 'epsc')













