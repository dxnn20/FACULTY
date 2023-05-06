clc
close all

beta = [10 ; 28; 8/3];
x0 = [0; 1; 0];
dt = 0.1;

tspan = [0, 1000];

[t,x] = ode45(@(t,x) f1(t,x,beta), tspan, x0);

plot3(x(:,1), x(:,2), x(:,3));
xlabel('x');
ylabel('y');
zlabel('z');
title('Lorenz Attractor');

tspan = [0, 1000];
[t,x] = ode45(@(t,x) f2(t,x,beta), tspan, x0);

figure
plot3(x(:,1), x(:,2), x(:,3));
xlabel('x');
ylabel('y');
zlabel('z');
title('Test Attractor');

function dx = f1(t,x,beta)
dx = [
  beta(1) * (x(2) - x(1));
  x(1) * (beta(2) - x(3)) - x(2);
  x(1) * x(2) - beta(3) * x(3);
];
end

function dx = f2(t,x,beta)
dx = [
  beta(1)*(-x(2) + x(3));
  x(1) * (beta(1) + x(3)) + x(2);
  x(1) * x(2) - beta(3) * x(3);
];
end