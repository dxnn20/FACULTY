syms  x y z a
e1 = x.^2 + y.*a-z;
e2 = x./z -a;

sol = solve(e1, e2, x ,y)