% testing file
clc
close all

x = [0,1,2,3,4,5,6]
y = [15, 30,75 ,60 ,60,40,55]
xi =[ 0.5,3.2,5.7]

[linear,cubic] = ex4_func(x,y,xi)

plot(x,y,'--r',xi,linear,'h',xi,cubic,'s')
legend('original points(connected)','approximated linearly','approximated cubically')

