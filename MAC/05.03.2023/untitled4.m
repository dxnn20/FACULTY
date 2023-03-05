close all;
t = linspace(0,2*pi);
z = linspace(0,2*pi);
x = 2*cos(t);
y = 2*sin(t);
plot(x,y,'b-');
xlabel('Xvalue');
ylabel('Yvalue');
hold on
w = 10*cos(z)+2;
v = 5*sin(z)+5;
plot (w,v,'ro');
hold off

