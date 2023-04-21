% we have to use a quasi-Newton method so we're gonna use fminunc

clc

v0 = [1,0];
options = optimset('Largescale','off');

[xmin,ymin,exitflag,output]=fminunc('ex8_func',v0,options);

xmin
ymin

fprintf('we evaluated the function %d times using the algorighm %s',output.funcCount,output.algorithm);
