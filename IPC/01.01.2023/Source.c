#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void citire(int **matrice, int size) {
	int i, j;

	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			scanf("%d", (matrice + i * size + j));
		}
	}
}


int main() {
	int **matrice= NULL;
	int *vector;
	char *sir;
	char buffer[51];
	int i,j,size,size2;
	printf("Ordinul matricei:\n");
	scanf("%d", &size);
	matrice = (int*)malloc(sizeof(int*)*size);
	for (i = 0; i < size; i++) {
		matrice[i]= (int*)malloc(sizeof(int) * size);
	}
	citire(matrice, size);
	//afisare
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			printf("%d   ", *(matrice + i * size + j));
		}
		printf("\n");
	}
	printf("Sirul:\n");
	
	scanf("%s", buffer);
	sir = (char*)malloc(sizeof(char)*strlen(buffer) + 2 );
	strcpy(sir, buffer);
	sir[strlen(buffer)] = 'i';
	sir[strlen(buffer)+1] = '\0';
	printf("%s\n", sir);
	
	printf("Marimea Vectorului de numere alocat dinamic:\n");
	scanf("%d", &size2);
	vector = (int*)malloc(sizeof(int)*size2);
	for (i = 0; i < size2; i++) {
		printf("Elementul %d\n", i + 1);
		scanf("%d", (vector + i));
	}
	for (i = 0; i < size2; i++) {
		printf("%d   ", *(vector + i));
	}


	exit(0);
}
