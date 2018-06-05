%%
close all;
load('DW_data\max nu test\nu_surge.mat')
figure(1)
hold on
time1 = linspace(0,46,4601);
plot(time1,nu(2,3570:4600+3570),'LineWidth',1.5)
test = 3.5996;
test_time = 60;
Tau_test = [test;0;0];
sim('test_CSAD')
figure(1)
plot(time,Nu(:,1),'-.','LineWidth',1.5)
sim('Copy_of_test_CSAD')
figure(1)
plot(time,Nu(:,1),'--','LineWidth',1.5)
xlabel('Time [s]')
ylabel('Surge speed [m/s]')
legend('Laboratory data','Lab 2 model','Lab 1 model','Location','best')
grid on
%%
load('DW_data\max nu test\nu_sway.mat')
figure(2)
hold on
time2 = linspace(0,50,5001);
plot(time2,nu(3,1610:5000+1610),'LineWidth',1.5)
test = 2.0032;
test_time = 50;
Tau_test = [0;test;0];
sim('test_CSAD')
figure(2)
plot(time,Nu(:,2),'-.','LineWidth',1.5)
sim('Copy_of_test_CSAD')
figure(2)
plot(time,Nu(:,2),'--','LineWidth',1.5)
xlabel('Time [s]')
ylabel('Sway speed [m/s]')
legend('Laboratory data','Lab 2 model','Lab 1 model','Location','best')
grid on
%%
figure(3)
hold on
load('DW_data\max nu test\pwm måling\nu.mat')
time3 = linspace(0,80,8001);
plot(time3,rad2deg(nu(4,72000:80000)),'LineWidth',1.5)
test = 1.7027;
test_time = 80;
Tau_test = [0;0;test];
sim('test_CSAD')
figure(3)
plot(time,rad2deg(Nu(:,3)),'-.','LineWidth',1.5)
sim('Copy_of_test_CSAD')
figure(3)
plot(time,rad2deg(Nu(:,3)),'--','LineWidth',1.5)
xlabel('Time [s]')
ylabel('Yaw rate [deg/s]')
legend('Laboratory data','Lab 2 model','Lab 1 model','Location','best')
grid on