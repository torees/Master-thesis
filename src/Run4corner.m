clear
close all

%Initial conditions
eta_initial = [5; -1; 0];
nu_initial = [0; 0; 0];

%Simulation parameters
t_sim = 800;
controller = 2; %L1 = 1, II = 2, 
sim('Adaptive_control_CSAD_model');





publish1










