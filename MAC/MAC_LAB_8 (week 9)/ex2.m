clc
close all

% 8.2 and 8.3

x = [0,1,2,3,4,5,6]
y = [15, 30,75 ,60 ,60,40,55]
xi =[ 0.5,3.2,5.7]

fprintf("Linear:\n")
yi= interp1(x,y,xi,'linear')
plot(x,y,'bo',xi,yi,'ro',x,y)
legend('known points','approximated points')
title('Linear')

fprintf("Lagrange\n")
yi = ex1_func(x,y,xi)
figure
plot(x,y,'bo',xi,yi,'ro',x,y)
title('Lagrange')
legend('known points','approximated points')

fprintf("Hermite:\n");
yi= interp1(x,y,xi,'cubic')
figure
plot(x,y,'bo',xi,yi,'ro',x,y)
title('Hermite')
legend('known points','approximated points')

fprintf("cubic spline:\n");
yi= interp1(x,y,xi,'spline')
figure
plot(x,y,'bo',xi,yi,'ro',x,y)
title('spline')
legend('known points','approximated points')

P2 = polyfit(x,y,2);% 3 for cubic, and other for other powers

fprintf("parabolic regression:\n");
yi= polyval(P2,xi)
figure
plot(x,y,'bo',xi,yi,'ro',x,y)
title('parabolic regression')
legend('known points','approximated points')

P5 = polyfit(x,y,5); % this case we used 5

fprintf("polinomial method (power of 5):\n");
yi= polyval(P5,xi)
figure
plot(x,y,'bo',xi,yi,'ro',x,y)
title('polinomial method (power of 5):')
legend('known points','approximated points')
