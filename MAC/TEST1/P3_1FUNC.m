function suma = P3_1FUNC(x)

suma = 0;
i = 1;
j = 0;

while  i <= length(x) && x(i) <= 4
    suma = suma + x(i);
    i = i+1;
end

if i == length(x) + 1
    disp('nu exista nr mai mari ca 4')
else
suma
prim_elem_mai_mare_ca_4 = i
end

end