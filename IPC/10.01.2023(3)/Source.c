#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char nume[21];
	int greutate;
	char cod[4];

}f;

int validare(char nume[21]) {
	int i;
	for (i = 0; i < strlen(nume); i++) {
		if (nume[i] <'a' || nume[i]>'z') {
			return 1;
		}

		
	}
	return 0;
}

void generare_cod(f* fructe, int nr){
	char cod[4];
	int aux = (fructe + nr)->greutate;
	while (aux >= 10) {
		aux  = aux / 10;
	}
	cod[0] = (fructe + nr)->nume[0];
	cod[1] = (fructe + nr)->nume[1];
	cod[2] = aux + '0';
	cod[3] = '\0';
	strcpy((fructe + nr)->cod, cod);
	printf("Cod dupa generare: %s ", (fructe + nr)->cod);
}
void citire(f* fructe, int *nr) {

	(*nr)++;
	do {
		printf("Nume:\n");
		scanf("%s", (fructe + *nr)->nume);
	} while (validare((fructe + *nr)->nume) != 0);
	printf("Greutate: \n");
	scanf("%d", &((fructe + *nr)->greutate));
	generare_cod(fructe, *nr);
}

void afisare(f* fructe, int n ) {
	printf("\nNume:\t%s\n", (fructe + n)->nume);
	printf("Greutate:\t%d\n", (fructe + n)->greutate);
	printf("Cod: \t%s", (fructe + n)->cod);
	printf("\n\n");
}

void ordonare_greutate(f* fructe, int nr) {
	int i,j;
	f aux;
	for (i = 0; i < nr; i++) {
		for (j = i + 1; j <= nr; j++) {
			if ((fructe+i)->greutate > (fructe+j)->greutate) {
				aux = *(fructe + i);
				*(fructe + i) = *(fructe + j);
				*(fructe + j) = aux;

			}
		}
	}
	for (i = 0; i <= nr; i++) {
		afisare(fructe, i);
	}
}

void greutate_desc(f* fructe, int nr) {
	int *vector = (int*)malloc(sizeof(int)* (nr+1));
	int i,j,aux;

	for (i = 0; i <= nr; i++) {
		*(vector + i) = (fructe + i)->greutate;
	}

	for (i = 0; i < nr; i++) {
		for (j = i + 1; j <= nr; j++) {
			if (*(vector + i) < *(vector + j)) {
				aux = *(vector + i);
				*(vector + i) = *(vector + j);
				*(vector + j) = aux;
			}
		}
	 }
	for (i = 0; i <= nr; i++) {
		printf("%d     ", *(vector + i));
	}
	printf("\n\n\n");
	free(vector);
}

void inlocuire(f *fructe, int nr) {

	int i = 0;
	for (i = 0; i <= nr; i++) {

		if ((strcmp((fructe + i)->nume, "cais"))==0) {
			strcpy((fructe + i)->nume, "prun");
		}
		afisare(fructe, i);
	}

}

int main(){
	f fructe[50];

	int opt,nr = -1;
	char nume[21];


	while (1) {

		printf("0. Iesire\n");
		printf("1. Citire\n");
		printf("2. Afisare ordine descr a greutatilor\n");
		printf("3. Greutatile intr-un vector, ordonate descresc\n");
		scanf("%d", &opt);
		switch (opt)
		{
		case 0: exit(0); 
			break;
		case 1:citire(fructe, &nr);
			break;
		case 2: ordonare_greutate(fructe, nr); break;
		case 3: greutate_desc(fructe, nr); break;
		case 4: inlocuire(fructe, nr); break;
		default: printf("Nu exista asa optiune!\n");
			break;
		}
		
	}
	





}