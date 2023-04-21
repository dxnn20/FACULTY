clc
close all

% 8.5

x = [0,1,2,3,4,5,6]
y = [15, 30,75 ,60 ,60,40,55]
xi =[ 0.5,3.2,5.7]

fprintf("Hermite:\n");
yi= interp1(x,y,xi,'cubic')
figure
plot(x,y,xi,yi,'ro')
title('Hermite')


fprintf("cubic spline:\n");
yi = spline(x,y,xi)

hold on

plot(xi,yi,'h')
legend('known points','hermite approx.','spline approx.')
hold off

