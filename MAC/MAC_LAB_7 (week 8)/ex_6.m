clc, close all

%setting x0 -> 0.5
x0 = 0.5;

%using  fminsearch we find out and display the minimum of the function then
%the value it gets in that point

xmin= fminsearch(@ex6_func,x0)
ymin= ex6_func(xmin)