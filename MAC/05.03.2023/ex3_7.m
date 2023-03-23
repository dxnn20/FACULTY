clc 
close all

t = 10*pi:0.01:100*pi;
x = sqrt(t)+t.^2-100.*log(t);
y = sin(0.5*t-3);
z = cos(0.5*t);
plot3(x,y,z);
