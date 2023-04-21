function dy = ex3_func2(x,y)

dy = zeros(2,1);
dy(1)= y(2);
dy(2)=2*y(2).*sin(x) - y(1);

end