function dy = ex3_func3(x,y)

dy = zeros(3,1);
y_normal = y(1);  %normal value
dy(1) = y(2);     % 1st derivative
dy(2)= y(3);      % 2nd derivative

dy(3) = dy(2)- x.*dy(1) +2.*y_normal.*sin(x)- x.^3;

end