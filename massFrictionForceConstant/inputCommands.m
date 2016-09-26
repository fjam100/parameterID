inputMin=0;
Ts=0.001;
inputMax=1;
stay=1000;
incr=0.01;
count=1;
signal=inputMin;
Ttotal=(inputMax-inputMin)/incr;
while signal<=inputMax
    u(count)=signal;
    if floor(count/stay)~=floor((count-1)/stay)
        signal=signal+incr;
    end
    count=count+1;
end

calMatrix=csvread('calibration.csv');
    