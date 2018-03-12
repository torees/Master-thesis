%plot mclab

%load data (add paths)
%load(\...\'eta');
%load(\...\'eta_t')

%plot track
% figure
% hold on
% xlabel('East [m]')
% ylabel('North [m]')
% trackplotter_mclab(eta_real, '--g')
% trackplotter_mclab(eta_ref_real, '-.k')
% h = zeros(2, 1);
% h(1) = plot(NaN,NaN,'--g');
% h(2) = plot(NaN,NaN,'-.k');
% legend(h, 'Track','Reference');
% 
% %plot path
% figure
% hold on
% xlabel('East [m]')
% ylabel('North [m]')
% pathplotter_mclab(eta_real, 10, 3000, '--g')
% pathplotter_mclab(eta_ref_real, 10, 3000, '-.k')
% h = zeros(2, 1);
% h(1) = plot(NaN,NaN,'--g');
% h(2) = plot(NaN,NaN,'-.k');
% legend(h, 'Track', 'Reference');

%plot path+track
figure
hold on
xlabel('East [m]')
ylabel('North [m]')
% pathtrackplotter_mclab(eta_real, 10, 3000, '--g', 'k')
pathtrackplotter_mclab(eta_ref_real, 10, 3000, '-.k', '--k')
% h = zeros(4, 1);
% h(1) = plot(NaN,NaN,'--g');
% h(2) = plot(NaN,NaN,'k');
% h(3) = plot(NaN,NaN,'-.r');
% h(4) = plot(NaN,NaN,'--b');
% legend(h, 'Track', 'Track','Reference','Reference');
