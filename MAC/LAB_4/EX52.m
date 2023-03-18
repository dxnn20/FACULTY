clc
a = sym('a');
b = sym('b');
p = sym('p');
q = sym('q');
c = sym('c');

A = [a -b 0; -b b -c ; 0 c a];
b = [p; -2*q; p+q];

X = A\b
X = inv(A)*b
X = pinv(A)*b;
