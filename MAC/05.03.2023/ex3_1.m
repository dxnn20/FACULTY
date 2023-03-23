clc
close all
x1 = -9:0.01:-3;
y1 = sin(5*x1);
x2 = -3:0.1:3;
y2 = cos(x2) - cos(3) - sin(15);
x3 = 3:0.1:9;
y3 = sin(5*x3);

hold on
plot (x1,y1,'-b');
plot(x2,y2, '-b');
plot(x3,y3,'-b');
hold off


x4 = -3:0.01:3;
y4 = (sin(pi.*x4)).*cos(pi.*x4);
x5  = -3:0.01:3;
y5 =sin(pi.*x5+1).*cos(pi.*x5+1);

figure 
hold on
plot(x4,y4,'--',"Color",'m');
plot(x5,y5,'cs-',"Color",'c');


