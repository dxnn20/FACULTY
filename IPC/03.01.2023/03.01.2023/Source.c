#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//rand. 8-114 pentru matrice
//rand 138 cuvinte ce apar de mai multe ori
//rand 296  cuvantul cu cele mai multe vocale

int valid(int element) {
	if ((element >= 0) && (element <= 128)) {
		return 0;
	}
	else return 1;
}

void suma_elemente(int **matrice, int size) {
	int i, j,suma = 0;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			suma = suma + matrice[i][j];
		}
	}
	printf("Suma elementelor: %d\n", suma);
}

void binar_colturi(int** matrice, int size) {
	
	int i,j;
	for (i = 0; i < size; i = i + size-1) {
		printf("%d In binar \n", matrice[0][i]);
		for (j = 31; j >= 0; j--) {
			if (((matrice[0][i] >> j)&1) == 1) printf("1");
			else printf("0");
		}
		printf("\n");
	}

}

void ordine_descr(int **matrice, int size) {
int i, j,aux;
int *sir = (int*)malloc(sizeof(int)*size);
for (i = 0; i < size; i++) {
	*(sir + i) = matrice[0][i];
}

for (i = 0; i < size; i++) {
	for (j = i + 1; j < size; j++) {
		if (*(sir + i) < *(sir + j)) {
			aux = *(sir + i);
			*(sir + i) = *(sir + j);
			*(sir + j) = aux;
		}
	}
}
for (i = 0; i < size; i++) {
	printf("%d   ", *(sir + i));
}
printf("\n");


}

void meniu_matrice() {
	int **matrice = NULL;
	int size = 0,i,j,opt;
	printf("Ordinul matricei patratice:\n");
	scanf("%d", &size);

	matrice = (int**)malloc(sizeof(int*)*size);
	for (i = 0; i < size; i++) {
		matrice[i] = (int*)malloc(sizeof(int)*size);
	}
	printf("Introdu elementele matricei:\n");
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			do {
				printf("elemntul [%d] [%d]\n", i + 1, j + 1);
				scanf("%d", &matrice[i][j]);
			} while (valid(matrice[i][j]) != 0);
		}
	}
	printf("Matricea introdusa este:\n");
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			printf("%d   ", matrice[i][j]);
		}
		printf("\n");
	}

	do {
		printf("0. Inapoi la meniul principal\n");
		printf("1. Suma elementelor matricei\n");
		printf("2. Repr. binara a numerelor din colturile de sus\n");
		printf("3. Elementele de pe primul rand in ordine descrescatoare\n");
		scanf("%d", &opt);

		switch (opt) {
		case 0: 
			for (i = 0; i < size; i++) {
				free(matrice[i]);
			} 
			free(matrice);

			 break;
		case 1:  suma_elemente(matrice, size); break;

		case 2:binar_colturi(matrice, size); break;
	
		case 3: ordine_descr(matrice, size); break;
		}
	} while (opt!=0);


}

void ordine_cresc(int* sir, int size) {
	int i, j,aux;
	for (i = 0; i < size-1; i++) {
		for (j = i + 1; j < size; j++) {
			if (*(sir + i) > *(sir + j)) {
				aux = *(sir + i);
				*(sir + i) = *(sir + j);
				*(sir + j) = aux;
			}
		}
	}
	for (i = 0; i < size; i++) {
		printf("%d   ", *(sir + i));
	}
	printf("\n");

}

//how?
void aparitie_multipla(int *sir, int size) {
	int i, j, mult=0; 

	for (i = 0; i < size; i++) {
		mult = 0;
		for (j = i; j < size; j++) {
			if (*(sir+i) == *(sir+j)) {
				mult++;
			}
		}
		if (mult > 1) { printf("%d apare de mai multe ori\n", *(sir + i)); }

	}

	printf("\n");
}

void putere(int *sir, int size) {
	int i,aux;

	for (i = 0; i < size; i++) {

		aux = *(sir + i) + 1;
		if ((aux &(aux - 1)) == 0) { printf("%d este cu 1 mai mic decat o putere a lui 2.\n", *(sir + i)); }

	}


}

void meniu_sir_numere() {
	int *sir;
	int i,size,opt;
	printf("Cate numere?\n");
	scanf("%d", &size);
	sir = (int*)malloc(sizeof(int)*size);
	for (i = 0; i < size; i++) {
		printf("Elementul %d\n", i + 1);
		scanf("%d", (sir + i));
	}

	do {
		printf("0. Meniu principal\n");
		printf("1. Ordine crescatoare\n");
		printf("2. Elemente ce apar de mai multe ori in vector\n");
		printf("3. Elementele mai mici cu 1 decat o putere a lui 2\n");
		scanf("%d", &opt);
		switch (opt)
		{
		case 0: free(sir); break;
		case 1: ordine_cresc(sir,size);
		case 2:  aparitie_multipla(sir, size);
		case 3: putere(sir, size);
		}
	} while (opt != 0);
}

void char_desc(char *sir, int size) {
	int j,i;
	char aux;
	for (i = 0; i < size-1; i++) {
		for (j = i + 1; j < size; j++) {
			if (*(sir + i) < *(sir + j)) {
				aux = *(sir + i);
				*(sir + i) = *(sir + j);
				*(sir + j) = aux;
			}
		}
	}
	printf("Sir ordonat desc. :\n");
	for (i = 0; i < size; i++) {
		printf("%c     ", *(sir + i));
	}
	printf("\n");
}

void poz_imp(char *sir, int size) {

	int i;
	printf("Cuvantul format din literele de pe poz. impara\n");
	for (i = 1; i < size; i = i + 2) {
		printf("%c", *(sir + i));
	}
	printf("\n");
}

void suma_ascii(char *sir, int size) {
	int i, suma=0;
	for (i = 0; i < size; i++) {
		suma = suma + *(sir + i);
	}
	printf("Suma elementelor : %d \nIar in binar:\n", suma);
	for (i = 31; i >= 0; i--) {

		if (((suma>>i) & 1) == 1) printf("1");
		else printf("0");

	}
	printf("\n");
}

void meniu_sir_caractere() {
	char *sir;
	int i,size,opt;

	printf("Cate caractere are sirul?\n");
	scanf("%d", &size);
	sir = (char*)malloc(sizeof(char)*size);
	for (i = 0; i < size; i++) {
		getchar();
		scanf("%c", sir+i);
	}
	printf("\n");
	
	
	do {

		printf("0. Main menu\n");
		printf("1. Elementele in ordine descresc.\n");
		printf("2. Cuvant format din literele de pe pozitie impara.\n");
		printf("3. Reprezentarea binara a sumei caracterelor in sistemul ASCII.\n");
		printf("Introdu optiunea:\n");
		scanf("%d", &opt);
		switch (opt)
		{
		case 0: free(sir);  break;
		case 1: char_desc(sir, size); break;
		case 2: poz_imp(sir, size); break;
		case 3: suma_ascii(sir, size); break;
		}

	} while (opt != 0);


}

void sortare_sir_sir(char **sir, int size) {
	int i, j;
	char aux[21];
	for (i = 0; i < size - 1; i++) {
		for (j = i + 1; j < size; j++) {
			if (strlen(sir[i]) > strlen(sir[j])) {
				strcpy(aux, *(sir + i));
				strcpy(*(sir + i), *(sir + j));
				strcpy(*(sir + j), aux);
			}
		}
	}
	printf("Sirul sortat\n");
	for (i = 0; i < size; i++) {
		printf("%s\n", *(sir + i));
	}

}

// how?
void vocale(char **sir, int size) {
	printf("\n????\n");
}


void biti(char **sir, int size) {

	int i, j, biti = 0;

	
	for (i = 0; i < size; i++) {
		biti = 0;
		
		for (j = 0; j < 32; j++) {
			if ((1 << j) & strlen(sir[i])) biti= j;
		}
		printf("\nCuvantul %s are nevoie de %d biti\n",sir[i], biti + 1);
	}

}


void meniu_sir_sir() {
	char **sir;
	int i,size,opt;
	char buffer[51];

	printf("Cate cuvinte introduci?\n");
	scanf("%d", &size);
	sir = (char**)malloc(sizeof(char*)*size+1);
	for (i = 0; i < size; i++) {
		scanf("%s", buffer);
		sir[i] = (char*)malloc(sizeof(char)*strlen(buffer)+1);
		strcpy(sir[i], buffer);
	}

	do {
		printf("0. Main menu\n");
		printf("1. Afisarea elementelor in ordine descrescatoare a lungimilor cuvintelor\n");
		printf("2. Cuvantul cu cele mai multe vocale\n");
		printf("3. Afisarea numarului de biti necesar pentru fiecare cuvant\n");

		scanf("%d", &opt);

		switch (opt)
		{
		case 0:
			free(sir);  break;
		case 1: sortare_sir_sir(sir, size); break;
		case 2: vocale(sir, size); break;
		case 3: biti(sir, size); break;
		}



	} while (opt != 0);
	/*printf("Sirul introdus:\n");
	for (i = 0; i < size; i++) {
		printf("%s\n", sir[i]);
	}*/
	
}


int main() {
	int  opt;
	

	do {
		printf("----Main Menu----\n");
		printf("0. Exit\n");
		printf("1. Matrice\n");
		printf("2. Sir de numere\n");
		printf("3. Sir de caractere\n");
		printf("4. Sir de siruri de caractere\n");
		
		scanf("%d", &opt);

		switch (opt)
		{
		case 0: exit(0); break;

		case 1:  meniu_matrice(); break;

		case 2:meniu_sir_numere(); break;
		
		case 3: meniu_sir_caractere(); break;

		case 4: meniu_sir_sir(); break;
		}





	}
	while (opt != 0);

}