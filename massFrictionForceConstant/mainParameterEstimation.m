load('zeroinputnoise.mat');
Ts=0.001;
vel=zeroinputnoise.Y(2).Data;
upperLt=max(vel);
lowerLt=min(vel);
var=load('excitationdata5.mat');
name='excitationdata5';
v=var.(name).Y(1,2).Data.'/1000;
u=var.(name).Y(1,3).Data.'/1000;
Y=v(2:end);
PV=positiveVel(v,lowerLt,upperLt).';
NV=negativeVel(v,lowerLt,upperLt).';
phi=[v(1:end-1), u(1:end-1), -1*PV(1:end-1), -1*NV(1:end-1)];
thetaCap=(phi.'*phi)\phi.'*Y;
pvd=thetaCap(1);
Kvd=thetaCap(2);
dfplus=thetaCap(3)/Kvd;
dfminus=thetaCap(4)/Kvd;
[KaKt,~]=getKaKt();
J=((pvd-1)*KaKt*Ts)/(Kvd*log(pvd));
B=((1-pvd)*KaKt)/Kvd;
TplusC=KaKt*dfplus;
TminusC=KaKt*dfminus;