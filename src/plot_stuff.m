close all
figure(8)
hold on
title('Signal jump in x [m]')
plot(eta(2,:))
plot(eta_hat(2,:))
legend('Measured pose','Estimated pose');
%xlim([14000 18000 ])


figure(9)
hold on
title('Surge speed estimate')
plot(nu(2,:))
%xlim([15500 16500 ])

for a = 1:1:length(freeze)
    if (freeze(2,a) ==1)
        a
    end
end