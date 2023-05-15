clc
fplot(@untitled14);

[x,y] = ginput();

close all

sol = ones(length(x),1);

options = optimset('TolX',10^-10);

for i = 1: length(x)
sol(i) = fzero('untitled14',x(i),options);
end

sol