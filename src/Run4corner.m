%clear all
close all

rng('shuffle')
%Initial conditions
eta_initial = [5; -1; 0];
nu_initial = [0; 0; 0];

%Simulation parameters
t_sim = 250;
controller = 1; %L1 = 1, II = 2, 
mrs_select=0;


noise = 0.000015;
noisev = 0.000005;

gamma = 1.5;
sigma = 2;

posnoise = [0.001 0.004 0.001]*noise;
posnoise2 = [0.01 0.04 0.01]*noise*0.05;
velnoise=[0.0002 0.0002 0.01]*noisev;
velnoise2=[0.002 0.002 0.01]*noisev*0.05;
sim('NPNV_CSAD_model');

NPNV_IAE = e1_IAE;
NPNV_IAEW= e1_IAEW;
NPNV_IADC = e1_IADC;




sim('Adaptive_control_CSAD_model');

AD_IAE = e1_IAE;
AD_IAEW= e1_IAEW;
AD_IADC = e1_IADC;

eta_AB = eta_II;

L1u = "L1 unconstrained";
L1mr = "L1-MRS";
L1l = "L1-lowpass";
II = "I&I";
IIl = "I&I-lowpass";
IIm = "I&I-MRS";

if controller==2
    type =II;
end
if controller==1
    type =L1u;
end

filename = 'L1MRS2path';
filename2 ='L1MRS2tau';
filename3 = 'L1MRS2metric';


%% Pathplotter
f =figure(1);
movegui(f,'northeast');
hold on
xlabel('East [m]')
ylabel('North [m]')
pathtrackplotter_mclab_ref(eta_t, 10, 3000, 'k', 'k')
pathtrackplotter_mclab(eta_NPNV, 10, 2800, 'b', '-.b')
pathtrackplotter_mclab(eta_AB, 10, 3000,'r', '--r' )
h = zeros(3, 1);
h(1) = plot(NaN,NaN,'-.b','LineWidth',1.5);
h(2) = plot(NaN,NaN,'--r','LineWidth',1.5);
h(3) = plot(NaN,NaN,'k','LineWidth',1.5);
legend(h, 'NP-NV',type,'Reference','Location','none');
axis equal

saveas(gcf,filename,'epsc')



%% Tauplotter
g =figure(2);
movegui(g,'southeast');
surge = subplot(3,1,1);
hold on
plot(tau_ts_surge,'b','LineWidth',1.5)
plot(tau_ts_surge1,'-.r','LineWidth',1.5)
%title('Commanded input')
ylabel('\tau_1 [N]')
grid on
hold off
xlim([0 t_sim])
sway = subplot(3,1,2);
title('')
hold on
plot(tau_ts_sway,'b','LineWidth',1.5)
plot(tau_ts_sway1,'-.r','LineWidth',1.5)
title('')
ylabel('\tau_2 [N]')
legend('NP-NV',type,'Location','none')
grid on
hold off
xlim([0 t_sim])
ylim([-6 6])
yaw = subplot(3,1,3);
hold on
plot(tau_ts_yaw,'b','LineWidth',1.5)
plot(tau_ts_yaw1,'-.r','LineWidth',1.5)
ylabel('\tau_3 [Nm]')
title('')
grid on
xlabel('Time [s]')
xlim([0 t_sim])
hold off
saveas(gcf,filename2,'epsc')


%% Metric plotter
ts=0.01;
figure(3)
subplot(3,1,1);
hold on
plot(NPNV_IAE,'b','Linewidth',1.5)
plot(AD_IAE,'-.r','Linewidth',1.5)
ylabel('IAE')
grid on
title('Pose tracking metrics')
hold off
xlim([0 t_sim])
subplot(3,1,2);
hold on
plot(NPNV_IAEW,'b','Linewidth',1.5)
plot(AD_IAEW,'-.r','Linewidth',1.5)
title('')
legend('NP-NV',type,'Location','northwest')
ylabel('IAEW')
xlim([0 t_sim])
grid on
subplot(3,1,3);
title('')
hold on
plot(NPNV_IADC,'b','Linewidth',1.5)
plot(AD_IADC,'-.r','Linewidth',1.5)
ylabel('IADC')
%xlabel('Time[s]')
title('')
xlim([0 t_sim])
grid on

maxim = [max(NPNV_IAE) max(AD_IAE);
        max(NPNV_IAEW) max(AD_IAEW);
        max(NPNV_IADC) max(AD_IADC)]
posnoise
velnoise

f =figure(6);
movegui(f,'northwest');
bar(maxim)
barvalues;



g =figure(4);
movegui(g,'southwest');
set(gca,'XTickLabel',{0,50,100,150,200,250,300});
x = subplot(3,1,1);
hold on

plot(eta_t(1:250/ts,1),'--k','Linewidth',1.5)
plot(eta_t_NPNV(1:250/ts,1),'-.g','Linewidth',1.5)
plot(eta_NPNV(1:250/ts,1),'b','Linewidth',1.5)
plot(eta_AB(1:250/ts,1),'-.r','Linewidth',1.5)
grid on

y = subplot(3,1,2);
hold on
plot(eta_t(:,2),'--k','Linewidth',1.5)
plot(eta_t_NPNV(:,2),'-.g','Linewidth',1.5)
plot(eta_NPNV(:,2),'b','Linewidth',1.5)
plot(eta_AB(:,2),'-.r','Linewidth',1.5)
grid on

psi = subplot(3,1,3);
hold on
plot(eta_t(:,3),'--k','Linewidth',1.5)
plot(eta_t_NPNV(:,3),'-.g','Linewidth',1.5)
plot(eta_NPNV(:,3),'b','Linewidth',1.5)
plot(eta_AB(:,3),'-.r','Linewidth',1.5)
grid on


PSD_nu;






