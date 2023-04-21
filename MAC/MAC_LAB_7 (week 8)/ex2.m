clc
x0 = rand(1,1)
y0= rand(1,1)
v =[x0 y0];
options = optimoptions('fsolve','Display','iter');
[x,fval,exitflag] = fsolve(@ex2_func,v,options)

%calculating random starting values then working our way until we find
%all sols