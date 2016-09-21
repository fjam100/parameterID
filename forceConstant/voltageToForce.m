%% Read recorded forces and perform linear fitting to obtain Ka*Kt for
%% linear motor+amplifier

clear all;
clc;

calMatrix=csvread('calibration.csv');
name='horizontal';
rec=load(strcat(name,'.mat'));
rec1=genvarname(name);
% for i=1:length(rec.rec1.Y(1).Data)
%     force(:,i)=calMatrix*[rec.rec1.Y(1).Data(i);rec.rec1.Y(2).Data(i); ...
%         rec.rec1.Y(3).Data(i);rec.rec1.Y(4).Data(i);rec.rec1.Y(5).Data(i) ...
%         rec.rec1.Y(6).Data(i)];
% end