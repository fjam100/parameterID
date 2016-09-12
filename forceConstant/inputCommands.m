inputMin=0;
Ts=0.001;
inputMax=3;
stay=1000;
incr=0.1;
count=1;
signal=inputMin;

while signal<inputMax
    u(count)=signal;
    if floor(count/stay)~=floor((count-1)/stay)
        signal=signal+incr;
    end
    count=count+1;
end
    