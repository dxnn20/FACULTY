function [] = EX6_FUNC(matrice_coef,matrice_termeni)
rang = rank(matrice_coef)
rang_extins = rank([matrice_coef matrice_termeni])
[x,y] = size(matrice_termeni);

if rang == rang_extins && x == rang
disp("Sistem compatibil determinat");

elseif rang == rang_extins && x ~= rang
    disp("Sistem compatibil nedeterminat");
    X = pinv(matrice_coef)*matrice_termeni
else 
    disp("Sistem incompatibil");
end

end