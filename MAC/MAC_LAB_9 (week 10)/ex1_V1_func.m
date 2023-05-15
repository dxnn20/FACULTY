function root = ex1_V1_func(c)

root =  roots (c);

for i= 1:length(root)

    if isreal(root(i))
    fprintf("Solution %d (%d) is real \n" , i,root(i));
    else
    fprintf("Solution %d is not real:",i);
    root(i)
    end
end

end