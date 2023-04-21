function [linear ,cubic] = ex4_func(x,y,xi)

linear = interp1(x,y,xi,'linear');
cubic = interp1(x,y,xi,'cubic');

end

