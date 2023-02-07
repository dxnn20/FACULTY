#define _CRT_SECURE_NO_WARNINGS

#include	<stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct  telefon {
	char marca[21];
	int diagonala_ecran;
	int pret;
 }t;

int validare(char aux[21]) {
	int i;
	for (i = 0; i < strlen(aux); i++) {
		if (aux[i] < 'a' || aux[i] > 'z') {
			return 1;
		}
	}
		for (i = 0; i < strlen(aux); i++) {
			if (aux[i] == 'a' || aux[i] == 'e' || aux[i] == 'i' || aux[i] == 'o' || aux[i] == 'u') {
				return 0;
			}
		}
	
}


void adaugare(t *telefon, int *n) {
	(*n)++;
	char aux[21];
	do {
		printf("Marca:\t");
		scanf("%s", aux);
	} while (validare(aux) != 0);
		strcpy((telefon + *n)->marca, aux);
		printf("Diagonala \t ");
		scanf("%d", &((telefon + *n)->diagonala_ecran));
		(telefon + *n)->pret = strlen((telefon + *n)->marca)* ((telefon + *n)->diagonala_ecran);
}

void afisare(t*telefon, int n) {
	printf("Marca:\t %s  \n", (telefon + n)->marca);
	printf("Diagonala :\t  %d \n", (telefon + n)->diagonala_ecran);
	printf("Pret:\t %d \n",(telefon+n)->pret	);

	printf("\n\n");

}

void afisare_cresc(t*telefon, int n) {
	int i, j;
	t aux;

	for (i = 0; i < n; i++) {
		for (j = i+1; j <= n; j++) {
			if ((telefon + i)->pret > (telefon + j)->pret) {
				aux = *(telefon + i);
				*(telefon + i) = *(telefon + j);
				*(telefon + j) = aux;

			}

		}
	}


	for (i = 0; i <= n; i++) {
		afisare(telefon, i);
	}
}

void binary(t*telefon, int n) {
	int i, j,biti_de_1= 0;

	for (i = 0; i <= n; i++) {
		biti_de_1 = 0;
		afisare(telefon, i);
		for (j = 0; j < 31; j++) {
			if ((1 << j)& (telefon + i)->diagonala_ecran) biti_de_1++;
		}
		printf("Diag in binar are %d biti de 1\n\n\n", biti_de_1);


	}



}

int main() {
	t telefon[50];
	int opt,n=-1,i;

	

	while (1) {
		printf("0. Iesire\n");
		printf("1. Adaugare\n");

		scanf("%d", &opt);

		switch (opt)
		{

		case 0: exit(0); break;
		case 1:adaugare(telefon, &n); break;
		case 2: afisare_cresc(telefon, n); break;
		case 3:binary(telefon, n); break;
		default: printf("nu exista optiunea\n");
			break;
		}

	}



}