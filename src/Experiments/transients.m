clear
close all;
load('All\16\eta');
load('All\16\eta_ref');

load('May_ex\L1_MRS_highmag\eta');
load('May_ex\L1_MRS_highmag\eta_t');
eta_t=eta_d;
load('May_ex\L1_MRS_highmag\eta_ref');
ts=0.01;
timestart1=65;
timeend1=length(eta)/100;
%timeend1 =350;
simtime1 = timeend1-timestart1;
endval = simtime1/ts;

eta_AB=eta;
L1u = "L1 unconstrained";
L1c = "L1-CG";
L1mr = "L1-MRS";
L1l = "L1-lowpass";
II = "I&I unconstrained";
IIl = "I&I-lowpass";
IIm = "I&I-MRS";
type =L1mr;
g =figure(4);
movegui(g,'southwest');
%set(gca,'XTickLabel',{0,50,100,150,200,250,300,350,400,450,500,550});
x = subplot(3,1,1);
hold on
plot(eta_t(2,timestart1/ts:timeend1/ts),'--k','Linewidth',1.5)
plot(eta_AB(2,timestart1/ts:timeend1/ts),'-.r','Linewidth',1.5)
grid on
xlim([0 endval])
ylabel(' Surge [m]')
set(gca,'XTickLabel',{0,50,100,150,200,250,300,350,400,450,500,550});
y = subplot(3,1,2);
hold on
plot(eta_t(3,timestart1/ts:timeend1/ts),'--k','Linewidth',1.5)
plot(eta_AB(3,timestart1/ts:timeend1/ts),'-.r','Linewidth',1.5)
grid on
xlim([0 endval])
ylabel(' Sway [m]')
legend(type,'Reference','Location','none');
set(gca,'XTickLabel',{0,50,100,150,200,250,300,350,400,450,500,550});
psi = subplot(3,1,3);
hold on
plot(rad2deg(eta_t(4,timestart1/ts:timeend1/ts)),'--k','Linewidth',1.5)
plot(rad2deg(eta_AB(4,timestart1/ts:timeend1/ts)),'-.r','Linewidth',1.5)
grid on
xlim([0 endval])
ylabel(' Yaw [deg]')
set(gca,'XTickLabel',{0,50,100,150,200,250,300,350,400,450,500,550});
xlabel('Time [s]')