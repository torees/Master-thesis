clear
close all

%Initial conditions
eta_initial = [5; -1; 0];
nu_initial = [0; 0; 0];

%Simulation parameters
t_sim = 250;
controller = 1; %L1 = 1, II = 2, 
sim('Adaptive_control_CSAD_model');



publish1




figure(77)
hold on
plot(eta_comp(2400:2560,1)+0.002);
plot(eta_hat(2401:2560,1));
hold off
legend("Measured position","Predicted position","Location","best");




