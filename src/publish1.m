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

figure(4)
plot(e1_IAE)
legend("IAE")
figure(5)
plot(e1_IAEW)
legend("IAEW")

figure(7)
plot(tau_ts)
legend("tau time series")