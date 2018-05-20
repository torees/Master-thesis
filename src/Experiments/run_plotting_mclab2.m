%% Load data
clear all
close all







%start 61


load('May_ex\NPNV_unconstrained\eta');
load('May_ex\NPNV_unconstrained\eta_ref');
load('May_ex\NPNV_unconstrained\nu');
load('May_ex\NPNV_unconstrained\alpha');
load('May_ex\NPNV_unconstrained\tau');
load('May_ex\NPNV_unconstrained\tau_dot');

eta1 = eta;
eta_t1 = eta_t;
nu1 = nu;
tau1 = tau;
tau_dot1 = tau_dot;

timestart1=77;
timeend1=length(eta)/100;
simtime1 = timeend1-timestart1;

% L1_CG_6highL2 155
% L1_MRS_highmag 77
% L1_MRS_lowmag 101
% L1_regular 126  This is probably a CG
% L1_regular_test2 92  This is probably a CG
% L1_unconstrained 84

load('May_ex\L1_MRS_lowmag\eta');
load('May_ex\L1_MRS_lowmag\eta_t');
load('May_ex\L1_MRS_lowmag\nu');
load('May_ex\L1_MRS_lowmag\alpha');
load('May_ex\L1_MRS_lowmag\tau');
load('May_ex\L1_MRS_lowmag\tau_dot');
eta_t=eta_d;

eta2 = eta;
eta_t2 = eta_t;
nu2 = nu;
tau2 = tau;
tau_dot2 = tau_dot;

timestart2=101;
timeend2=uint32(length(eta)/100-1);
ts = 0.01;
simtime2 = timeend2-timestart2;


%% Pathplotter
f =figure(1);
movegui(f,'northeast');
hold on
xlabel('East [m]')
ylabel('North [m]')
pathtrackplotter_mclab(eta1(2:4,timestart1/ts:timeend1/ts), 10, 3000, 'b', 'b')
pathtrackplotter_mclab(eta2(2:4,timestart2/ts:timeend2/ts), 10, 3000, 'k', 'k')
pathtrackplotter_mclab_ref(eta_t1(2:4,timestart1/ts:timeend1/ts), 10, 3000, '-.r', '--r')
h = zeros(3, 1);
h(1) = plot(NaN,NaN,'b','LineWidth',1.5);
h(2) = plot(NaN,NaN,'k','LineWidth',1.5);
h(3) = plot(NaN,NaN,'r','LineWidth',1.5);
legend(h, 'NPNV','NPNV-MRS','Reference','Location','best');
axis equal

%% Tau
g =figure(2);
movegui(g,'southeast');
surge = subplot(3,1,1);
hold on
plot(surge,tau1(1,1:timeend1/ts-timestart1/ts+1),tau1(2,timestart1/ts:timeend1/ts),'b','LineWidth',1.5)
plot(surge,tau2(1,1:timeend2/ts-timestart2/ts+1),tau2(2,timestart2/ts:timeend2/ts),'r','LineWidth',1.5)
ylabel('\tau_1 [N]')
grid on
hold off
xlim([0 (tau2(1,timeend2/ts)-timestart2+1)])
sway = subplot(3,1,2);
hold on
plot(sway,tau1(1,1:timeend1/ts-timestart1/ts+1),tau1(3,timestart1/ts:timeend1/ts),'b','LineWidth',1.5)
plot(sway,tau2(1,1:timeend2/ts-timestart2/ts+1),tau2(3,timestart2/ts:timeend2/ts),'r','LineWidth',1.5)
ylabel('\tau_2 [N]')
legend('NPNV','NPNV-MRS','Location','best')
grid on
hold off
xlim([0 (tau2(1,timeend2/ts)-timestart2+1)])
yaw = subplot(3,1,3);
hold on
plot(yaw,tau1(1,1:timeend1/ts-timestart1/ts+1),tau1(4,timestart1/ts:timeend1/ts),'b','LineWidth',1.5)
plot(yaw,tau2(1,1:timeend2/ts-timestart2/ts+1),tau2(4,timestart2/ts:timeend2/ts),'r','LineWidth',1.5)
ylabel('\tau_3 [Nm]')
grid on
xlabel('Time [s]')
xlim([0 (tau2(1,timeend2/ts)-timestart2+1)])

%% Performance metrics IAE+IAEW+IADC
eta_iae = eta1(:,timestart1/ts:timeend1/ts);
eta_t_iae = eta_t1(:,timestart1/ts:timeend1/ts);
nu_iae = nu1(:,timestart1/ts:timeend1/ts);
tau_iae = tau1(1:4,timestart1/ts:timeend1/ts);
tau_dot_iae = tau_dot1(1:4,timestart1/ts:timeend1/ts);
%alpha_iae = alpha(:,timestart1/ts:timeend1/ts);

 eta_iae(1,1) = 0;

for i = 2:length(eta_iae(1,:))
    eta_iae(1,i) = eta_iae(1,i)-timestart1+ts; 
end

eta_t_iae(1,:) = eta_iae(1,:);
nu_iae(1,:) = eta_iae(1,:);
tau_iae(1,:) = eta_iae(1,:);
tau_dot_iae(1,:) = eta_iae(1,:);
%alpha_iae(1,:) = eta_iae(1,:);  

eta_iae = eta_iae';
eta_t_iae = eta_t_iae';
nu_iae = nu_iae';
%alpha_iae = alpha_iae';
tau_iae = tau_iae';
tau_dot_iae = tau_dot_iae';

sim('performancemetricsmclab')
eta_iae1 = eta_iae;
e1_IAE1 = e1_IAE;
e1_IAEW1 = e1_IAEW;
e1_IADC1 = e1_IADC;

eta_iae = eta2(:,timestart2/ts:timeend2/ts);
eta_t_iae = eta_t2(:,timestart2/ts:timeend2/ts);
nu_iae = nu2(:,timestart2/ts:timeend2/ts);
tau_iae = tau2(1:4,timestart2/ts:timeend2/ts);
tau_dot_iae = tau_dot2(1:4,timestart2/ts:timeend2/ts);
%alpha_iae = alpha(:,timestart2/ts:timeend2/ts);

 eta_iae(1,1) = 0;

for i = 2:length(eta_iae(1,:))
    eta_iae(1,i) = eta_iae(1,i)-timestart2+ts; 
end

eta_t_iae(1,:) = eta_iae(1,:);
nu_iae(1,:) = eta_iae(1,:);
tau_iae(1,:) = eta_iae(1,:);
tau_dot_iae(1,:) = eta_iae(1,:);
%alpha_iae(1,:) = eta_iae(1,:);  

eta_iae = eta_iae';
eta_t_iae = eta_t_iae';
nu_iae = nu_iae';
%alpha_iae = alpha_iae';
tau_iae = tau_iae';
tau_dot_iae = tau_dot_iae';
simtime1 = double(simtime2);

sim('performancemetricsmclab')
eta_iae2 = eta_iae;
e1_IAE2 = e1_IAE;
e1_IAEW2 = e1_IAEW;
e1_IADC2 = e1_IADC;

%Do the figure of Metrics

p =figure(3);
movegui(p,'center');
IAE1 = subplot(3,1,1);
hold on
plot(IAE1,eta_iae1(:,1),e1_IAE1,'Linewidth',1.5)
plot(IAE1,eta_iae2(:,1),e1_IAE2,'Linewidth',1.5)
ylabel('IAE')
grid on
title('Pose tracking metrics')
hold off
xlim([0 eta_iae2(end,1)])
IAEW1 = subplot(3,1,2);
hold on
plot(IAEW1,eta_iae1(:,1),e1_IAEW1,'Linewidth',1.5)
plot(IAEW1,eta_iae2(:,1),e1_IAEW2,'Linewidth',1.5)
ylabel('IAEW')
legend('NPNV','NPNV-MRS','Location','best')
xlim([0 eta_iae2(end,1)])
grid on
IADC = subplot(3,1,3);
hold on
plot(IADC,eta_iae1(:,1),e1_IADC1,'Linewidth',1.5)
plot(IADC,eta_iae2(:,1),e1_IADC2,'Linewidth',1.5)
ylabel('IADC')
xlabel('Time[s]')
xlim([0 eta_iae2(end,1)])
grid on



maxim = [max(e1_IAE1) max(e1_IAE2);
        max(e1_IAEW1) max(e1_IAEW2);
        max(e1_IADC1) max(e1_IADC2)]




