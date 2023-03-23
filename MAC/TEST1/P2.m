clc
x = 0.1:0.1:100;
figure
plot(x,P2FUNC(x),'red--');


P2FUNC(0)
P2FUNC(-1)
P2FUNC(3+2*1i)
P2FUNC(2)

x = -1;
y = -1*P2FUNC(x);
figure


hold on
plot(x,y,'x',"Color",'blue');
x = 2;
y = 2*P2FUNC(x);
plot(x,y,'x')

hold off