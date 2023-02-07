#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define opt(x) printf("Introdu optiunea:\n"); scanf("%d", &x);

int validare(int numar) {

	if (numar <=  100 && numar >= 0) {
		return 1;
	}
	else return 0;
}

void cresc(int *numere, int n) {
	int i,j;
	int aux;
	printf("Sirul neordonat\n" );
	for (i = 0; i < n; i++) {
		printf("%d\n", *(numere + i));
	}
	printf("Sirul ordonat:\n");
	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			if (*(numere + i) > *(numere + j)) {
				aux = *(numere + i);
				*(numere + i) = *(numere + j);
				*(numere + j) = aux;
			 }
		}
	}
	for (i = 0; i < n; i++) {
		printf("%d\n", *(numere + i));
	}


}

void  multiplu(int *numere, int n) {
	int i,j ,aparitie;
	for (i = 0; i < n-1; i++) {
		aparitie = 1;
		for (j = i+ 1; j < n; j++) {
			if (*(numere + i) == *(numere + j)) {
				
				aparitie++;
			}
		}
		printf("Numarul %d apare de %d ori\n", *(numere + i), aparitie);
	}
}


void biti(int *numere, int n) {
	int aux,i;

	for (i = 0; i < n; i++) {
		aux = *(numere + i) + 1;
		if ((aux & (aux - 1) )== 0) {
			printf("%d\n", aux-1);
		}
	}
	printf("\n");
}


int main() {
	int *numere;
	int n, i, optiune,aux;

	do {
		printf("Cate numere introduci?\n");
		scanf("%d", &n);
	} while (n > 100);

	numere = (int*)malloc(sizeof(int)*n);
	printf("Introdu numerele:\n");

	for (i = 0; i < n - 1; i++) {
		do {
			printf("Numarul %d\n", i + 1);
			scanf("%d", (numere + i));
			aux = *(numere + i);
		} while (validare(*(numere+i))!=1);

	}
	*(numere + n-1) = n;

	
	do {
		printf("0. Iesire\n");
		printf("1.Afisare ordine crescatoare\n");
		printf("2. elementele ce apar de mai multe ori in sir\n");
		printf("3. toate elementele mai mici cu 1 unitate decat o putere a lui 2\n");
		opt(optiune);


		switch (optiune)
		{
		case 0: free(numere); exit(0); break;
		case 1: cresc(numere, n); break;
		case 2: multiplu(numere, n); break;
		case 3: biti(numere, n); break;
		}

	} while (optiune != 0);






}