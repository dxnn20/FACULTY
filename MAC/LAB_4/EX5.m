clc
a = sym('a');
b = sym('b');
g = sym('g');

A = [a -b 1; -g 1 b ; 1 -g -a];
B = [g; a ;b];

d = det(A)
s = A\B

