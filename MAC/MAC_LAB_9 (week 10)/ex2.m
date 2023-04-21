clc,close all

I = quad('ex2_func',pi/3,pi/2)

%apparently quad isn't recommended so:

I = integral(@ex2_func,pi/3,pi/2)

fplot(@ex2_func,'--r');
hold on
fplot(@ex2_func,[pi/3 pi/2],'b');
hold off
legend('whole function','area of interest')