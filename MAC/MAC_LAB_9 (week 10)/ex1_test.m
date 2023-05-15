clc

x0 = [1,1];
options = optimset('Tolx',10^-100);
[x,VAL,exitflag,output] = fsolve('untitled2',x0,options)