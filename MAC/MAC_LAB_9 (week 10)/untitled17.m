function dy = untitled17(x,y)

dy = ones(3,1);

dy = [
    y(2);
    y(3);
    y(3)- y(2) - x*y(2) + 2*y(1)*sin(x) - x^3;
]
end