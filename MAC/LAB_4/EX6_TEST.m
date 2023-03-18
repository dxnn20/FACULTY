clc
% compatibil determinat
A = [4 3 -1; -1 1 1; 1 0 3];
termeni_liberi = [2;0;-1]; 

%compatibil nedeterminat
A_nedet=[2 -3 0; -6 8 -1; 0 3 4; -4 8 3];
termeni_liberi_A_nedeterm = [7; -5; 1; 3];

%incompatibil
A_inc = [1 1 1 ;1 2 3;1 3 5];
termeni_liberi_A_inc = [1;2;4];


disp("Prima matrice")
EX6_FUNC(A,termeni_liberi);
disp("A doua matrice");
EX6_FUNC(A_nedet,termeni_liberi_A_nedeterm)

disp("A treia matrice")
EX6_FUNC(A_inc,termeni_liberi_A_inc);