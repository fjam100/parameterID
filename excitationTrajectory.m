Ts=0.001;

u=[];
index=1;
% for i=0:Ts:0.499
%     u(index)=0.3;
%     index=index+1;
% end
% 
% for i=0.5:Ts:0.999
%     u(index)=0.5;
%     index=index+1;
% end
% 
% 
% for i=1:Ts:1.499
%     u(index)=-0.8;
%     index=index+1;
% end
% 
% 
% for i=1.5:Ts:1.999
%     u(index)=0.7;
%     index=index+1;
% end
% 
% for i=0:Ts:0.499
%     u(index)=-0.9;
%     index=index+1;
% end
% 
% for i=0:Ts:0.499
%     u(index)=0.3;
%     index=index+1;
% end
% 
% for i=0:Ts:0.499
%     u(index)=0;
%     index=index+1;
% end
% 
% u=u*0;

Tperiod=0.5;
inp=[0.4 -0.5 0.3 -0.9 0.7 0];
CYCLES=60;
index=1;

for cycle=1:CYCLES
    for i=0:Ts:6*Tperiod-Ts
        inpindex=floor(mod((index-1)*0.001/Tperiod,6))+1;
        u(index)=inp(inpindex);
        index=index+1;
    end
end
    
u=u*0.1;
    
    