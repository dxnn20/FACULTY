#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "complexnr.h"

int main() {
	complex x,y,aux;
	char opt;

	x = generateRand();
	printComplex(x);
	printf("Introduce your complex number:\nReal:\t");
	scanf("%d", &y.real);
	printf("Imaginary part:\t");
	scanf("%d", &y.img);

	while (1) {
		printf("\n---MENU---\n");
		printf("0.Exit\n");
		printf("1. Display the sum of the 2 complex numbers\n");
		printf("2. Display the product of the 2 complex numbers\n");
		getchar();
		scanf("%c", &opt);
		opt -= '0';
			switch (opt)
			{
			case 0:printf("Bye!"); exit(0);   break;
			case 1: printComplex(sum(x, y));  break;
			case 2: printComplex(mult(x, y)); break;
			default: printf("No such option!\n");
				break;
			}
	}

	return 0;
}