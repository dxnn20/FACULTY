close all
clc
x = 0:0.1:3;
y = x+1;
x1 = -3:0.1:0;
y1 = -2*x1;

plot(x,y,Color= 'r',LineStyle='--');
hold on;
plot(x1,y1,Color= 'r',LineStyle='--');
hold off;