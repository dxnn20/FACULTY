function sol = untitled2(vx)

sol = ones(1,2);
x = vx(1);
y = vx(2);

sol(1) = sin(x+y)-1.1*x-0.2;
sol(2) = 1.1*x^2+2*y^2-1;
end