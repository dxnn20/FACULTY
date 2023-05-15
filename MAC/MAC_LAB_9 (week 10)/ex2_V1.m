clc
fplot(@untitled11);

%verifying if we can see the function touching 0

[x,y] = ginput()

close all
sol = fzero('untitled11',-3)