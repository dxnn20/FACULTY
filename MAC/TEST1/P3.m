clc
close all
%1 

x = randi([-10,10],1,10);
x
P3_1FUNC(x);

%2
%{
x = 0:0.1:5;
y = P3_2FUNC(x);

plot(x,y,'b:');

x = -5:0.1:0;
y = P3_2FUNC(x);

hold on 
plot(x,y,'b:');
hold off

%}

fplot(@t,[-5,5],'b:');


%3
A = [1 3 1;2 1 3;3 2 2]
b = [0;1;5];

if det(A)~= 0
    disp("Sistem compatibil det")
    sol  = A\b
elseif rank(A) == rank([A b])
    disp("Sistem compatibil nedet.")
    sol = pinv(A)*b
else
    disp("Incompat")
end



function y = t(x)

if x <= 0 
y = x.^2+x+1;
else
y = exp(-x);
end

end