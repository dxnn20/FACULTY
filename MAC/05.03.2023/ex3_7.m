clc 
close all

t = linspace(-10*pi, 10*pi);
x = t;
y = sin(0.5*t-3);
z = cos(0.5*t);
plot3(x,y,z);
