close all;
clc;
p = 9;
r = rem(p,3);
col = 0:0.1:r+1;

x = line([-2 -2 0 2 2 0 -2],[1 -1 -2 -1 1 2 1]);

x1 = line([-2 2], [-1 1]);
x2 = line([-2 2 ],[1 -1]);
x3 = line([0 0] ,[2 -2]);
switch r
    case 0
        x.Color = 'r';
        x1.Color = 'r';
        x2.Color = 'r';
        x3.Color = 'r';

    case 1
        x.Color = 'g';
        x1.Color = 'g';
        x2.Color = 'g';
        x3.Color = 'g';
    case 2
        x.Color = 'b';
        x1.Color = 'b';
        x2.Color = 'b';
        x3.Color = 'b';
    case 3
        x.Color = 'm';
        x1.Color = 'm';
        x2.Color = 'm';
        x3.Color = 'm';
end

