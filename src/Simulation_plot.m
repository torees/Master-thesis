%Run simulation and plot path
clear 
close all
%Simulation Scenarios

t_sim = 350;

Scenario = 0;
dec = 0;
tsamp=0;

nominal =0;
metric_type=0;
%% Scenario selection
if Scenario==0
    eta_initial = [0; 0; 0];
    nu_initial = [0; 0; 0];
    dec = 3400;
    tsamp=5;
elseif Scenario == 1
     eta_initial = [0.5; 0; pi/8];
     nu_initial = [0; 0; 0];
     dec = 2900;
     tsamp=5;
elseif Scenario ==2
    eta_initial = [-4; -2; 0.6*pi];
    nu_initial = [0; 0; 0];
    dec = 3400;
    tsamp=5;
end

%%Plotting
sim('CS2_multiple');

figure(1)
hold on
%pathplotter(eta_LPLV, tsamp, dec, tout,'b')
%pathplotter(eta_NPLV, tsamp, dec, tout,'-.k')
%pathplotter(eta_NPNV, tsamp, dec, tout,'--g')
%pathplotter(eta_AB, tsamp, dec, tout,'c')
pathplotter(eta_t, tsamp, dec, tout,'k')
pathplotter(eta_LPLV_MRAC_BS, tsamp, dec, tout,'-b')
pathplotter(eta_LPLV_MRAC_CASCADE, tsamp, dec, tout,'-.r')
h = zeros(3, 1);
h(1) = plot(NaN,NaN,'k');
h(2) = plot(NaN,NaN,'-b');
 h(3) = plot(NaN,NaN,'-.r');
% h(4) = plot(NaN,NaN,'c');
% h(5) = plot(NaN,NaN,'r');
%legend(h, 'LP-LV','NP-LV','NP-NV','AB','Target');
legend(h,'Target', 'Backstepping MRAC','Cascade MRAC')






hold off
xlabel('East [m]')
ylabel('North [m]')
axis equal


figure(2)
subplot(2,2,1);
hold on 
plot(IAE_LPLV_MRAC_CASCADE) 
plot(IAE_LPLV_MRAC_BS) 
%plot(IAE_NPLV)
%plot(IAE_NPNV)
%plot(IAE_AB)
%plot(IAE_L1AB)
%legend('LP-LV','NP-LV','NP-NV','AB')
legend('Cascade MRAC','Backstepping MRAC')
ylabel('IAE')
subplot(2,2,2)
hold on
plot(IAEW_LPLV_MRAC_CASCADE)
plot(IAEW_LPLV_MRAC_BS)
%plot(IAEW_NPLV)
%plot(IAEW_NPNV)
%plot(IAEW_AB)
%plot(IAEW_L1AB)
%legend('LP-LV','NP-LV','NP-NV','AB')
legend('Cascade MRAC','Backstepping MRAC')
ylabel('IAEW')
subplot(2,2,3)
hold on
plot(ISE_LPLV_MRAC_CASCADE)
plot(ISE_LPLV_MRAC_BS)
%plot(ISE_NPLV)
%plot(ISE_NPNV)
%plot(ISE_AB)
%plot(ISE_L1AB)
%legend('LP-LV','NP-LV','NP-NV','AB')
ylabel('ISE')
legend('Cascade MRAC','Backstepping MRAC')
subplot(2,2,4)
hold on
plot(ITAE_LPLV_MRAC_CASCADE)
plot(ITAE_LPLV_MRAC_BS)
%plot(ITAE_NPLV)
%plot(ITAE_NPNV)
%plot(ITAE_AB)
%plot(ITAE_L1AB)
%legend('LP-LV','NP-LV','NP-NV','AB')
legend('Cascade MRAC','Backstepping MRAC')
ylabel('ISE')
hold off

