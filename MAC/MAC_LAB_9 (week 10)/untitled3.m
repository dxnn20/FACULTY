clc
f = @(x) x^2;
neg = @(x) -f(x);

x = fminbnd(neg, -1,1)
