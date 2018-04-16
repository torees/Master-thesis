
load('1\eta');
load('1\nu');
%load('1\tau');
load('1\eta_ref');



load('pwm måling/eta')
load('pwm måling/nu')

simtime = length(eta(1,:))/100;
eta=eta';
nu=nu';
eta_t=eta_t';
sim("Mclab_estimator_fix")

nu_hat = nu_hat';
figure(7)
hold on
plot(nu_ts.Time,nu_ts.Data(:,1))
plot(nu_hat.Time,nu_hat.Data(:,1))
legend('gammel estimator','ny estimator','Location','best')






