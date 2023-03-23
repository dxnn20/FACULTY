function [MatriceExtrasa,detSubMatrice,prodScal] = untitled3(A)

MatriceExtrasa = A([1:4:100],[1:4:100])
detSubMatrice = det(MatriceExtrasa)
A = [A ; 1:100];

prodScal = dot(A(100,:),A(:,100))



end