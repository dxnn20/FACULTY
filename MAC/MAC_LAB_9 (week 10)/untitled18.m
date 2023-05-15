dom = [1,4];
x0 = [0.5,0.5, 0.3]

[x,y] = ode45('untitled17',dom , x0);

plot(x,y);
figure
plot3(x, y(:, 1),x, y(:, 2),x,y(:,3));