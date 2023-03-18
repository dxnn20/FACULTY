function [sol] = EX3(matrice_coef,matrice_termeni_liberi)

    if(rank(matrice_coef) == rank([matrice_coef matrice_termeni_liberi]))
        sol = (matrice_coef)\matrice_termeni_liberi
    else 
        disp("Nu poate fi rezolvat");
    end
end