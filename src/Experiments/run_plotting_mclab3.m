%% Load data
clear all
close all



%All\19

load('May_ex\NPNV_unconstrained\eta');
load('May_ex\NPNV_unconstrained\eta_ref');
load('May_ex\NPNV_unconstrained\eta_t');
load('May_ex\NPNV_unconstrained\nu');
load('May_ex\NPNV_unconstrained\alpha');
load('May_ex\NPNV_unconstrained\tau');
load('May_ex\NPNV_unconstrained\tau_dot');


%eta_t = eta_d;

timestart=75;
timeend=length(eta)/100;
ts = 0.01;
simtime1 = timeend-timestart;

%% Pathplotter
figure
hold on
xlabel('East [m]')
ylabel('North [m]')
pathtrackplotter_mclab(eta(2:4,timestart/ts:timeend/ts), 10, 3000, 'b', 'b')
pathtrackplotter_mclab_ref(eta_t(2:4,timestart/ts:timeend/ts), 10, 3000, '-.r', '--r')
h = zeros(2, 1);
h(1) = plot(NaN,NaN,'b','LineWidth',1.5);
h(2) = plot(NaN,NaN,'r','LineWidth',1.5);
legend(h, 'NP-NV','Reference','Location','best');
axis equal

%% Tau
figure
surge = subplot(3,1,1);
hold on
plot(surge,tau(1,1:timeend/ts-timestart/ts+1),tau(2,timestart/ts:timeend/ts),'b','LineWidth',1.5)
ylabel('\tau_1 [N]')
grid on
hold off
xlim([0 (tau(1,timeend/ts)-timestart+1)])
sway = subplot(3,1,2);
hold on
plot(sway,tau(1,1:timeend/ts-timestart/ts+1),tau(3,timestart/ts:timeend/ts),'b','LineWidth',1.5)
ylabel('\tau_2 [N]')
grid on
hold off
xlim([0 (tau(1,timeend/ts)-timestart+1)])
yaw = subplot(3,1,3);
hold on
plot(yaw,tau(1,1:timeend/ts-timestart/ts+1),tau(4,timestart/ts:timeend/ts),'b','LineWidth',1.5)
ylabel('\tau_3 [Nm]')
grid on
xlabel('Time [s]')
xlim([0 (tau(1,timeend/ts)-timestart+1)])

%% Performance metrics IAE+IAEW
eta_iae = eta(:,timestart/ts:timeend/ts);
eta_t_iae = eta_t(:,timestart/ts:timeend/ts);
nu_iae = nu(:,timestart/ts:timeend/ts);
tau_iae = tau(1:4,timestart/ts:timeend/ts);
%tau_dot_iae = tau_dot(1:4,timestart/ts:timeend/ts);
%alpha_iae = alpha(:,timestart/ts:timeend/ts);

 eta_iae(1,1) = 0;

for i = 2:length(eta_iae(1,:))
    eta_iae(1,i) = eta_iae(1,i)-timestart+ts; 
end

eta_t_iae(1,:) = eta_iae(1,:);
nu_iae(1,:) = eta_iae(1,:);
tau_iae(1,:) = eta_iae(1,:);
%tau_dot_iae(1,:) = eta_iae(1,:);
%alpha_iae(1,:) = eta_iae(1,:);  

eta_iae = eta_iae';
eta_t_iae = eta_t_iae';
nu_iae = nu_iae';
%alpha_iae = alpha_iae';
tau_iae = tau_iae';
%tau_dot_iae = tau_dot_iae';

sim('performancemetricsmclab2')

figure
IAE1 = subplot(3,1,1);
hold on
plot(IAE1,eta_iae(:,1),e1_IAE,'Linewidth',1.5)
ylabel('IAE')
grid on
title('Pose tracking metrics')
hold off
xlim([0 eta_iae(end,1)])
IAEW1 = subplot(3,1,2);
hold on
plot(IAEW1,eta_iae(:,1),e1_IAEW,'Linewidth',1.5)
ylabel('IAEW')
xlim([0 eta_iae(end,1)])
grid on
IADC = subplot(3,1,3);
hold on
plot(IADC,eta_iae(:,1),e1_IADC,'Linewidth',1.5)

ylabel('IADC')
xlabel('Time[s]')
xlim([0 eta_iae(end,1)])
grid on


MaxIAE = max(e1_IAE);
MaxIAEW = max(e1_IAEW);
MaxIADC = max(e1_IADC);

maxim = [MaxIAE MaxIAEW MaxIADC]'


