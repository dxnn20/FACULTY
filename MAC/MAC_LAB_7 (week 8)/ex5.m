clc
% arithm =>   b= (a+c)2;
% geom => b^2 = a*c;
% arithm 2 var =>  y-x = d constant
syms a b c;
e1 = a*c - b^2;
e2 = (a+c)/2 - b-4;
e3 = -(b+4)^2 + a *(c+32);

sol  = solve(e1,e2,e3,a,b,c)

sol_a = double(sol.a)
sol_b = double(sol.b)
sol_c = double(sol.c)

%shows 2x1 means it found 2 sols for each var