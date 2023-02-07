#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void afisare(char *matrice, int size) {
	int i, j;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {

			printf(" %c   ", *(matrice + i * size + j));
		}
		printf("\n");
	}

}

void diag_princ(char* matrice, int size) {
	int i,j;
	char aux;
	char *vector = (char*)malloc(sizeof(char)*size + 1);
	for (i = 0; i < size; i++) {
		*(vector + i) = *(matrice + i * size + i);
	}
	printf("Vectorul format din elem. diag. princ.\n");
	for (i = 0; i < size; i++) {
		printf("%c   ", *(vector+i));
	}printf("\n");

	for (i = 0; i < size - 1; i++) {
		for (j = i + 1; j < size; j++) {
			if (*(vector + i) > *(vector + j)) {
				aux = *(vector + i);
				*(vector + i) = *(vector + j);
				*(vector + j) = aux;
			}
		}
	}
	for (i = 0; i < size; i++) {
		printf("%c    ", *(vector+i));
	}
	printf("\n");

}
 
void colturi_matrice(char* matrice, int size) {
	char caracter;
	int i, j;

	printf("Cu ce element inlocuim ?\n");
	getchar();
	scanf("%c", &caracter);

	for (i = 0; i < size; i = i + size-1) {
		for (j = 0; j < size; j = j + size - 1) {
			*(matrice + i * size + j) = caracter;
		}
	}
	afisare(matrice, size);
}

int main() {
	char *matrice = NULL;
	int opt,size,i,j;
	printf("Ordiunul matricei:\n");
	scanf("%d", &size);
	matrice = (char*)malloc(sizeof(char)*size*size);
	for (i = 0; i < size; i++) {
		*(matrice + i * size + 0) = 'A';
	}
	for (i = 0; i < size; i++) {
		for (j = 1; j < size; j++) {
			do {
				printf("Elementul [%d] [%d]\n", i + 1, j + 1);
				scanf(" %c", (matrice + i * size + j));
			} while (!(*(matrice + i * size + j) >= 'A' && *(matrice + i * size + j) <= 'Z'));
		}
	}
	while (1) {
		printf("0. Iesire\n");
		printf("1.Afisare\n");
		printf("2.Elem. de pe pe diag princ in ordine crescator\n");
		printf("3. Inloc. colturilor cu o litera data\n");
		scanf("%d", &opt);
		switch (opt)
		{
		case 0: free(matrice); exit(0); break;
		case 1: afisare(matrice, size); break;
		case 2: diag_princ(matrice, size);  break;
		case 3: colturi_matrice(matrice, size); break;
		default: printf("Nu exista optiunea.\n");
			break;
		}
	}
}