function dy = untitled7_func(t,x0)

x = x0(1);
y = x0(2);
z = x0(3);

dy = [
    y-2*t+sin(t)-2*x;
    x+2*t-cos(t)-2*y;
    3*x-3*y+5*z;
]

end