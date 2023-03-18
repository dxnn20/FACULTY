close all;
clc
t = linspace(0,2*pi);
x = 2*cos(t);
y = 2*sin(t);
plot(x,y,'b-');
xlabel('Xvalue');
ylabel('Yvalue');
hold on
w = 10*cos(t)+2;
v = 5*sin(t)+5;
plot (w,v,'b-',2,5,'+','lineWidth',5,'Color','red');
axes = 'equal';
hold off

