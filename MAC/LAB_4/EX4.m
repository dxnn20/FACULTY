clc
A = [-6 8 -1;2 -3 0];
b = [-5; 7];

if(rank(A) == rank([A b]))
disp("metoda PSEUDO-inversarii:")
X = pinv(A)*b
else 
    disp("e incomp sau comp nedet");
end
