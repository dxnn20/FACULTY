#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
 
int cautare(int* x, int* y,int  sizeX, int element) {
	int i;
	for (i = 0; i < sizeX; i++) {
		if (*(y + element) == *(x + i)) {
			return 1;
		}
	}
	return 0;
}


void main() {
	int *x = NULL, *y = NULL;
	int sizeX = 0, sizeY = 0, i;

	do {
		
		scanf("%d", &sizeX);
	} while (sizeX <1 || sizeY > 25000 );

	x = (int*)malloc(sizeof(int)*sizeX);

	for (i = 0; i < sizeX; i++) {
		do {
			
			scanf("%d", (x + i));
		} while (*(x+i)>1000000000);
		
	}

	do {
		
		scanf("%d", &sizeY);
	} while (sizeY <1 || sizeY >200000);
	y = (int*)malloc(sizeof(int)*sizeY);

	for (i = 0; i < sizeY; i++) {
		do {
			
			scanf("%d", (y + i));
			
		} while (*(y + i) > 1000000000);
	}

	for (i = 0; i < sizeY; i++) {
		printf("%d ",cautare(x, y, sizeX, i));
	}
}