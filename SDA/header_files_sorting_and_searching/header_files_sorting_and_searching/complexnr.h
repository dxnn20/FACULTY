#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct complex {
	int real, img;
}complex;

complex generateRand();
void printComplex(complex);
complex sum(complex, complex);
complex mult(complex, complex);

complex generateRand() {
	srand(time(NULL));
	complex x;
	x.real = rand() % 100;
	x.img = rand() % 100;
	return x;
}

complex sum(complex x, complex y) {
	complex aux;
	aux.real = x.real + y.real;
	aux.img = x.img + y.img;
	return aux;
}

complex  mult(complex x, complex y) {
	complex aux;
	aux.real = x.real*y.real - y.img*x.img;
	aux.img = x.img*y.real + x.real*y.img;
	return aux;
}

void printComplex(complex x) {
	printf("The complex number is\t%d + %d*i\n", x.real, x.img);

}



