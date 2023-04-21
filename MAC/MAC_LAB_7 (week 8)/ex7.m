clc,close all

%plotting the function we see we got a problem for x = 0
%so we're gonna treat it on intervals
%also I defined the negative equivalent of the function (its minimum is the
%normal function's maximum

f_aux = @(x) -(sin(x)+ sqrt(abs(x)));
y = @(x) f_aux(x);

%first interval
[xMin,fval_forxMin]= fminbnd('ex7_func',-6,0)
[xMax, fval_forxMax] = fminbnd(y,-6,0)

%second interval
fprintf('Second interval (0 6):\n')
[xMin,fval_forxMin]= fminbnd('ex7_func',0,6)
xMax = fminbnd(y,0,6)

%since we use fminbnd we are sure every point we discovered if either
%maximum or minimum (is not a saddle point) (șa)

fplot(@ex7_func,[-6 6])
hold on

fplot(y, [-6 6] ,'--r')

hold off