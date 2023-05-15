
clc

eq1 = a*c - b^2;
eq2 =  -b-4 + 2*(a+c);
eq3 = -(b+4)^2 + a*(c+32);

 %  sol = fsolve(eq1,eq2,eq3,'a','b','c')
syms a b c
sol = solve(a*c - b^2 == 0, -b-4 + 2*(a+c) == 0, -(b+4)^2 + a*(c+32) == 0, a, b, c)

for i = 1: length(sol.a)
disp([sol.a(i) sol.b(i) sol.c(i)]);
end