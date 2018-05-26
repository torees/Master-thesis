%close all
x = eta_L1(:,1);

Fs = 100;
N = length(x);
xdft = fft(x);
xdft = xdft(1:N/2+1);
psdx = (1/(Fs*N)) * abs(xdft).^2;
psdx(2:end-1) = 2*psdx(2:end-1);
freq1 = 0:Fs/length(x):Fs/2;

a=10*log10(psdx);

x = eta(2,:);

Fs = 100;
N = length(x);
xdft1 = fft(x);
xdft1 = xdft1(1:N/2+1);
psdx1 = (1/(Fs*N)) * abs(xdft1).^2;
psdx1(2:end-1) = 2*psdx1(2:end-1);
freq = 0:Fs/length(x):Fs/2;

f =figure(7);
movegui(f,'northeast');
hold on
plot(freq1,a,'LineWidth',1.5)
plot(freq,10*log10(psdx1),'LineWidth',1.5)
grid on
legend("Simulation","Measurement");
title('Power Spectral Density Estimate Using FFT')
xlabel('Frequency (Hz)')
ylabel('Power/Frequency (dB/Hz)')
xlim([19 21])


x = eta_L1(:,2);

Fs = 100;
N = length(x);
xdft = fft(x);
xdft = xdft(1:N/2+1);
psdx = (1/(Fs*N)) * abs(xdft).^2;
psdx(2:end-1) = 2*psdx(2:end-1);
freq1 = 0:Fs/length(x):Fs/2;

a=10*log10(psdx);

x = eta(3,:);

Fs = 100;
N = length(x);
xdft1 = fft(x);
xdft1 = xdft1(1:N/2+1);
psdx1 = (1/(Fs*N)) * abs(xdft1).^2;
psdx1(2:end-1) = 2*psdx1(2:end-1);
freq = 0:Fs/length(x):Fs/2;

f =figure(8);
movegui(f,'southeast');
hold on
plot(freq1,a,'LineWidth',1.5)
plot(freq,10*log10(psdx1),'LineWidth',1.5)
grid on
legend("Simulation","Measurement");
title('Periodogram Using FFT')
xlabel('Frequency (Hz)')
ylabel('Power/Frequency (dB/Hz)')
xlim([19 21])

x = eta_L1(:,3);

Fs = 100;
N = length(x);
xdft = fft(x);
xdft = xdft(1:N/2+1);
psdx = (1/(Fs*N)) * abs(xdft).^2;
psdx(2:end-1) = 2*psdx(2:end-1);
freq1 = 0:Fs/length(x):Fs/2;

a=10*log10(psdx);

x = eta(4,:);

Fs = 100;
N = length(x);
xdft1 = fft(x);
xdft1 = xdft1(1:N/2+1);
psdx1 = (1/(Fs*N)) * abs(xdft1).^2;
psdx1(2:end-1) = 2*psdx1(2:end-1);
freq = 0:Fs/length(x):Fs/2;

f =figure(9);
movegui(f,'northeast');
hold on
plot(freq1,a,'LineWidth',1.5)
plot(freq,10*log10(psdx1),'LineWidth',1.5)
grid on
legend("Simulation","Measurement");
title('Periodogram Using FFT')
xlabel('Frequency (Hz)')
ylabel('Power/Frequency (dB/Hz)')
xlim([19 21])
