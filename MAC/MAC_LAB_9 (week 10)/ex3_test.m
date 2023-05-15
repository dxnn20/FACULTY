clc
x0 = [0,0.2,-0.1];
tspan = [0,3];
[t, y] = ode45('untitled7_func', tspan, x0);

plot(t, y(:, 1),'h', t, y(:, 2));
figure
plot3(t, y(:, 1), y(:, 2))

figure
plot(t,y);
