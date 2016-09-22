%% Read recorded forces and perform linear fitting to obtain Ka*Kt for
%% linear motor+amplifier

clear all;
clc;

calMatrix=csvread('calibration.csv');
name='horizontal';
rec=load(strcat(name,'.mat'));

% for i=1:length(rec.rec1.Y(1).Data)
%     force(:,i)=calMatrix*[rec.rec1.Y(1).Data(i);rec.rec1.Y(2).Data(i); ...
%         rec.rec1.Y(3).Data(i);rec.rec1.Y(4).Data(i);rec.rec1.Y(5).Data(i) ...
%         rec.rec1.Y(6).Data(i)];
% end
windowSize = 10;
b = (1/windowSize)*ones(1,windowSize);
a = 1;

Fx = filter(b,a,rec.(name).Y(1).Data);
Fy = filter(b,a,rec.(name).Y(2).Data);
windowSize = 20;
b = (1/windowSize)*ones(1,windowSize);
a = 1;
Fz = filter(b,a,rec.(name).Y(3).Data);
u=rec.(name).Y(4).Data;
force=sqrt(Fx.^2+Fy.^2);
forceOffset=mean(force(1:1000));
force=force-forceOffset;

A=[u(30000:end).', ones(size(u(30000:end))).'];
B=force(30000:end).';
x=pinv(A)*B;

% coeffs = polyfit(u(30000:end), force(30000:end), 1);
% fittedX = linspace(min(u), max(u), 200);
% fittedY = polyval(coeffs, fittedX);
% figure();
% plot(fittedX, fittedY, 'r-', 'LineWidth', 3);