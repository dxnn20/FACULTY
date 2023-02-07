#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


void citire(int *matrice, int size) {
	int i = 0 , j = 0;
	for (i=0 ; i < size; i++) {
		for (j=0; j < size; j++) {
			printf("Elementul [%d]  [%d]\t", i + 1, j + 1);
			scanf("%d", (matrice + i * size + j));
		}
	}
}

void afisare(int *matrice, int size) {
	int i,j;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			printf("%d   ", *(matrice + i * size + j));

		}
		printf("\n");
	}


}

void colturi(int* matrice, int size) {
	int i, j,k;

	for (i = 0; i < size; i = i + size - 1) {
		for (j = 0; j < size; j = j + size - 1) {
			printf("Elementul  %d:\t",*(matrice + i * size + j));
			for (k = 31; k >= 0; k--) {
				if ((*(matrice + i * size + j) >> k) & 1) printf("1"); 
				else printf("0");
			}
			printf("\n");
		}
	}

}

void inlocuire(int *matrice, int size,int numar) {
	int i,j;

	for (i = 0; i < size; i = i + size - 1) {
		for (j = 0; j < size; j = j + size - 1) {
			*(matrice + i * size + j) = numar;
		}
	}
	afisare(matrice, size);
}

void sortare(int* vector, int size) {
	int i, j,aux=0;
	for (i = 0; i < size-1; i++) {
		for (j = i + 1; j < size; j++) {
			if (*(vector + i) > *(vector + j)) {
				aux = *(vector + i);
				*(vector + i) = *(vector + j);
				*(vector + j) = aux;
			}


		}

	}
	printf("Vectorul sortat\n");
	for (i = 0; i < size; i++) {
		printf("%d\t", *(vector + i));
	}
	printf("\n");

}
void randMijloc(int*matrice, int size) {
	int i = size/2, j;
	int*vector = (int*)malloc(sizeof(int)*size);
	for (j = 0; j < size; j++) {
		*(vector + j) = *(matrice + i*size + j);
	}
	
	for (i = 0; i < size; i++) {
		printf("%d    ", *(vector + i));
	}
	printf("\n");

	sortare(vector, size);
}

int main() {
	int *matrice= NULL,size = 0,opt =0,numar=0;

	printf("Care e ordinul?\n");
	scanf("%d", &size);
	matrice = (int*)malloc(sizeof(int)*size*size);


	citire(matrice, size);
	afisare(matrice, size);
	while (1) {
		printf("0.Iesire\n");
		printf("1. Afisare\n");
		printf("2. Elemenetele din colturi in forma binara\n");
		printf("3. Inlocuire colturi cu un element citit de la tastatura\n");
		printf("4. Elementele din randul din mijloc, ordonat crescator\n");
		scanf("%d", &opt);

		switch (opt)
		{
		case 0: free(matrice); exit(0); break;
		case 1: afisare(matrice, size); break;
		case 2: colturi(matrice, size); break;
		case 3: printf("care e nr?\t");
			scanf("%d", &numar);
			inlocuire(matrice, size, numar); break;

		case 4: randMijloc(matrice, size); break;
		default: printf("Nu exista optiunea!\n");
			break;
		}
	}
}