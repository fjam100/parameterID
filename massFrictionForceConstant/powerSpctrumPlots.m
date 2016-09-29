figure()
% load('forfftdspacenosensor.mat');
% X=forfftdspace.Y(3).Data;
M=csvread('data.csv');
X=M(:,3);
Fs = 10000;            % Sampling frequency
T = 1/Fs;  
L=length(X);

Y = fft(X);
P2 = abs(Y/L);
P1 = P2(1:floor(L/2)+1);
P1(2:end-1) = 2*P1(2:end-1);
f = Fs*(0:(L/2))/L;
plot(f,P1)
title('Single-Sided Amplitude Spectrum of X(t)')
xlabel('f (Hz)')
ylabel('|P1(f)|')
