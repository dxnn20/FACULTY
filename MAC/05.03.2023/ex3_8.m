clc 
tic
close all

[x1,y1] = meshgrid(-3:0.15:3);

z1 = ex3_8fun(x1,y1);

plot3(x1,y1,z1);

figure
mesh(x1,y1,z1);

figure
surf(x1,y1,z1);

figure
s1 = surfl(x1,y1,z1);
s1.EdgeColor = 'none';
toc