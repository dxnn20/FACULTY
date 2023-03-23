clc
%1
MAIN = randi([-100 100] , 99,100);
MAIN
untitled3(MAIN);


fig = figure;
set(fig,'Name','EX2')

x = 0:0.1:3;
y = 1+x;
plot(x,y,'red--');
hold on
x = -3:0.1:0;
y = -2.*x;
plot (x,y,'red--');
hold off

disp("EX 3")
A = randi([-100 100],10,10);
B = randi([-100 100],10,1);

if(det(A)~=0)
disp("Compat det")
Sol = A\B
Sol  = inv(A)*B
elseif rank(A) == rank([A B])
disp("Compat nedet")
else 
    disp("Incomp")
end
