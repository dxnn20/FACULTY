function [matricerand,det,prod] = untitled2(A)
randrowstart = randi(3,1)
randrowend = randi(3,1)
randcolstart = randi(3,1)
randcolend = randi(3,1)


if(randcolend > randcolstart)
max = randcolend;
min = randcolstart
else 
    max = randcolstart;
    min  = randcolend;

if(randrowend > randrowstart)
min1 = randrowstart;
max1 = randrowend;


else
    min1 = randrowend;
    max1 = randrowstart;

end


B = A(min1 : max1,min : max)





end