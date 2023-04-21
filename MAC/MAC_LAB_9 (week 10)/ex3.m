clc ,close all

% tried using different numerical methods for each one

% a)
    y0 = 2;
    dom = [-1,5];
    [xval,yval] = ode113('ex3_func',dom,y0)
    plot(xval,yval)

% b)
    y0 = [-1,2]
    dom = [0,6];
    [xval,yval] = ode23('ex3_func2',dom,y0)
    plot(xval,yval)

% c)
    y0 = [0.5,-0.5,0.3];
    dom = [1,4];
    [xval,yval] = ode45('ex3_func3',dom,y0)
    plot(xval,yval)
    title('Points a,b and c')
    legend('point c ', 'point b','point a')

% d) -> not really sure if I did it correctly (check ex3_func4)
    y0 = [0,0.2,-0.1];
    dom = [0,3];
    [xval,yval] = ode23('ex3_func3',dom,y0)
    figure 
    plot(xval,yval)
    title('Point d');