
load('L1_new\eta');
load('L1_new\nu');
%load('1\tau');
load('L1_new\eta_ref');




simtime = length(eta(2,:))/100;
eta=eta';
nu=nu';
eta_t=eta_t';
sim('Mclab_estimator_fix')

nu_hat = nu_hat';
% figure(7)
% hold on
% plot(nu_ts.Time,nu_ts.Data(:,2))
% plot(nu_hat.Time,nu_hat.Data(:,2))
% legend('gammel estimator','ny estimator','Location','best')



%NEW

load('L1_new2\eta');
load('L1_new2\nu');
%load('1\tau');
load('L1_new2\eta_ref');




simtime = length(eta(2,:))/100;
eta=eta';
nu=nu';
eta_t=eta_t';
sim('Mclab_estimator_fix')

nu_hat = nu_hat';
figure(8)
hold on
plot(nu_ts.Time,nu_ts.Data(:,1))
plot(nu_hat.Time,nu_hat.Data(:,1))
legend('gammel estimator','ny estimator','Location','best')


