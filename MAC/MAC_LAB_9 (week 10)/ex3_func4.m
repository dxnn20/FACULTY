function dy = exr_func4(x,y)

dy = zeros(3,1)
x_init = y(1);
y_init = y(2);
z_init =y(3);

dy = [ 
    y_init - 2*z_init + sin(x) - 2*x_init;
    x_init+2*z_init- cos(x) - 2*y_init;
    3*x_init -3*y_init - 5.*z_init;
    ];


end