function res=positiveVel(v,lowerLt,upperLt)
for i=1:length(v)
    res(i)=1/2*sigma(v(i),lowerLt,upperLt)*(1+sigma(v(i),lowerLt,upperLt));
end