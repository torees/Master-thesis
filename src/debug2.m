close all

figure(5)
hold on
plot(rad2deg(etaNPNV(4,4000:end)-etatNPNV(4,4000:end)),'LineWidth',1.5)
plot(rad2deg(etaL1(4,:)-etatL1(4,:)),'LineWidth',1.5)
plot(rad2deg(etaL1mrs(4,1800:end)-etatL1mrs(4,1800:end)),'LineWidth',1.5)
plot(rad2deg(etaII(4,19500:end)-etatII(4,19500:end)),'LineWidth',1.5)
legend("NP-NV","L1 unconstrained","L1 MRS","I&I",'Location','none')
xlim([20000 28300])
set(gca,'XTickLabel',{0,50,100,150,200,250,300});