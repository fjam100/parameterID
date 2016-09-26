function res=sigma(v,lowerLt,upperLt)
res=1;
if v<=upperLt && v>=lowerLt
    res=0;
elseif v>upperLt
    res=1;
else
    res=-1;
end