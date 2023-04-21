function [yi] = ex1_func(x,y,vx)

n = length(x)-1;
m = length(vx);

for t = 1:m
    L = ones(1,n+1);
    for i  = 1: n+1
        for j = 1:n+1
            if j ~= i
                L(i) = L(i) *((vx(t)-x(j))/(x(i)-x(j)));
            end
        end
    end
yi(t) = sum(y.*L);
end

end



%below is the first implementation (for 1 point)
%{
 sum= 0
n = length(x) -1
for i = 1:n+1
    pr = 1;
    for j = 1 : n+1
        if  i ~= j
            pr = pr*(x - xi(i)/(xi(i)-xi(j)))
        end
    end
    sum = sum + y(i)*p
end
%}