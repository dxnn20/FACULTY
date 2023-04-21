clc,close all
%generating the vectors x and y (preallocating them to optimize the
%program)

x = zeros(1,11);
y = zeros(1,11);

for i  = 1:11
    x(i) = -1.1 +0.1*i;
    y(i) = (i*x(i)^2)/(x(i)-1) - 2/(i+1);
end

I = trapz(x,y)

plot(x,y);
xlabel('x');
ylabel('y');
title(['Definite Integral = ' num2str(I)]);
