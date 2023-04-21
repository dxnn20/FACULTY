clc
close all

x = [1, 2, 3, 4,5];
y = [1, 4, 9, 16,25];
xi = [6 ,7,8,9,0];
yi = ex1_func(x, y, xi);


plot(x, y, 'bo',x,y,'--r');
hold on
plot(xi, yi, 'ro');
hold off

%then I tried something
xi = linspace(5,20,1000);
yi = ex1_func(x, y, xi);

figure 
plot(x,y,'ro',xi,yi)

%I first tried for 1 variable to see how the algorithm works (was
%pretty surprised to see it actually did a great job,then added one more
%for cycle make it approximate me a set of points
