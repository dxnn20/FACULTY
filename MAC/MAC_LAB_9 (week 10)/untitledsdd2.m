syms x y z;

clc
s = solve (x+z,x^2+z,y - x*z,x,y,z)

for i = 1:length(s.x)
disp ([s.x(i) s.y(i)])

end