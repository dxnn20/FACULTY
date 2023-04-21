clc

%sol = solve('m+p-2*n','n*q-p^2','m+q-37','n+p-36','m','n','p','q') 
%tried and had hella errors

syms m n p q ;
eq1 = m + p - 2*n;
eq2 = n*q - p^2;
eq3 = m + q - 37;
eq4 = n + p - 36;
sol = solve(eq1, eq2, eq3, eq4, m, n, p, q)

m_sol = double(sol.m)
n_sol = double(sol.n)
p_sol = double(sol.p)
q_sol = double(sol.q)

%since sol is a struct and each value is 2x1 means it has 2 solutions  for
%each variable we solved the system for

