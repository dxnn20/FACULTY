clc
rc1 = 2;
rc2 = 1;
h = 3;
figure
[x,y,z] = cylinder([rc1 rc2],1000);
surf(x,y,z);
figure
[x1,y1,z1] = cylinder([3 0], 6);
surf(x1,y1,z1);
