clc
close all
r = 6371;
[x,y,z] = sphere(24);
x = r*x;
y = r*y;
z = r*z;
x = surf(x,y,z);
x.color = 'none';