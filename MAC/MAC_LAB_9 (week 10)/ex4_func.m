function dy  = ex4_func(t,y)

m1 = 10;
m2 = 4.15;
m3 = 0.5;
g = 9.81;
J3 = 0.004;

F1 = @(t) -58.6*sin(2*t);
F2 = @(t) 23.25*exp(-t)*(sin(4*t) - 3*cos(4*t)) + 45.601;
M3 = @(t) 0.004.*t.^2;

dy = zeros(1,3);
y_normal = y(1);
y_der = y(2);
y_der2 = y(3);



end