clc
A=[4 3 -1; -1 1 1; 1 0 3; 4 4 3];
b=[2; 0; -1; 1];

rank(A)
rank([A b])

if rank(A)==rank([A b])
 disp('metoda impartirii la stanga')
 X=A\b
else
 disp('Sistemul nu este compatibil.')
end

A1 = [-6 8 -1; 2 -3 0];
b1 =[-5;7];

if rank(A1)==rank([A1 b1])
 disp('metoda impartirii la stanga')
 X=A1\b1
else
 disp('Sistemul nu este compatibil.')
end
