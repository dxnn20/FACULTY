clc
A = [4 3 -1; -1 1 1; 1 0 3];
termeni_liberi = [2;0;-1];
if det(A)~=0 
 X=inv(A)*termeni_liberi;
else
 disp('Sistemul nu este compatibil determinat.')
end

X