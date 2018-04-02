%% Load data
clear all
close all
%{
1: NPLV unconstrained
2: NPNV unconstrained
3: NPNV magnitude constraints = [1.1089 0.6387, 0.6176] 
4: NPNV fast MRS, magnitude constraints = [1, 0.58, 0.56]
5: NPLV fast MRS, magnitude constraints = [2, 1.5, 1]
6: NPNV fast MRS, magnitude constraints = [2, 1.5, 1]
7: NPLV slow MRS; magnitude constraints = [2, 1.5, 1]
8: NPNV slow MRS, magnitude constraints = [2, 1.5, 1]
9: NPLV, magnitude constraints = [2, 1.5, 1]
10: NPLV, magnitude constraints = [2, 1.5, 1]
%}
load('L1\1\eta');
load('L1\1\eta_ref');
load('L1\1\nu');
load('L1\1\alpha');
load('L1\1\tau');
load('L1\1\tau_dot');

load('All\20\eta');
load('All\20\eta_ref');
load('All\20\nu');
load('All\20\alpha');
load('All\20\tau');
load('All\20\tau_dot');
% load('L1\2\eta');
% load('L1\2\eta_ref');
% load('L1\2\nu');
% load('L1\2\alpha');
% load('L1\2\tau');
% load('L1\2\tau_dot');

% load('L1\4\eta');
% load('L1\4\eta_ref');
% load('L1\4\nu');
% load('L1\4\alpha');
% load('L1\4\tau');
% load('L1\4\tau_dot');

%{
time 
   start end
1: 44    405
2: 57    389
3: 68    417
4: 40    401
5: 49    395
6: 43    373   
7: 44    395
8: 55    392
9: 65    410
10:37    363
11:52    352
12:66    357
13:33    324
%}

timestart=71;
timeend=102+timestart;
ts = 0.01;
simtime = timeend-timestart;

%% Pathplotter
figure
hold on
xlabel('East [m]')
ylabel('North [m]')
pathtrackplotter_mclab(eta(2:4,timestart/ts:timeend/ts), 10, 3000, 'b', 'b')
pathtrackplotter_mclab(eta_t(2:4,timestart/ts:timeend/ts), 10, 3000, '-.r', '--r')
h = zeros(2, 1);
h(1) = plot(NaN,NaN,'b','LineWidth',1.5);
h(2) = plot(NaN,NaN,'r','LineWidth',1.5);
legend(h, 'CSAD','Reference','Location','best');
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
tau_dot_iae = tau_dot(1:4,timestart/ts:timeend/ts);
alpha_iae = alpha(:,timestart/ts:timeend/ts);

 eta_iae(1,1) = 0;

for i = 2:length(eta_iae(1,:))
    eta_iae(1,i) = eta_iae(1,i)-timestart+ts; 
end

eta_t_iae(1,:) = eta_iae(1,:);
nu_iae(1,:) = eta_iae(1,:);
tau_iae(1,:) = eta_iae(1,:);
tau_dot_iae(1,:) = eta_iae(1,:);
alpha_iae(1,:) = eta_iae(1,:);  

eta_iae = eta_iae';
eta_t_iae = eta_t_iae';
nu_iae = nu_iae';
alpha_iae = alpha_iae';
tau_iae = tau_iae';
tau_dot_iae = tau_dot_iae';

sim('performancemetricsmclab')

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

% figure
% IAE2 = subplot(2,1,1);
% hold on
% plot(IAE2,eta_iae(:,1),e2_IAE,'Linewidth',1.5)
% ylabel('IAE')
% grid on
% hold off
% title('Velocity tracking metrics')
% xlim([0 eta_iae(end,1)])
% IAEW2 = subplot(2,1,2);
% hold on
% plot(IAEW2,eta_iae(:,1),e2_IAEW,'Linewidth',1.5)
% ylabel('IAEW')
% xlabel('Time[s]')
% xlim([0 eta_iae(end,1)])
% grid on
