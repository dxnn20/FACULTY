clc
close all
x = 0.01:0.01:100;
x1  = x;
y = sin(x);
z = cos(x./2);
figure
plot3(x1,y,z,'h');
xlabel('x')
ylabel('y')
zlabel('z')
figure
plot(x,y);
