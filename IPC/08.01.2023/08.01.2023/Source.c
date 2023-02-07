#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validare(char buffer[21]) {
	int i;
	for (i = 0; i < strlen(buffer); i++) {
		if (buffer[i] < 'a' || buffer[i]>'z')
			return 1;
	}
	for (i = 0; i < strlen(buffer); i++) {
		if (buffer[i] == 'a' || buffer[i] == 'e' || buffer[i] == 'i' || buffer[i] == 'o' || buffer[i] == 'u')
			return 0;
	}

}

void afisare(char **sir, int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("%s\n", *(sir + i));
	}
}

void ordonare_alfabetica(char **sir, int size) {
	int i, j;
	char aux[21];

	for (i = 0; i < size-1 ; i++) {
		for (j = i + 1; j < size; j++) {
			if (strcmp(*(sir + i), *(sir + j)) >= 0) {
				strcpy(aux, *(sir + i));
				strcpy(*(sir + i), *(sir + j));
				strcpy(*(sir + j), aux);
			}
		}
	}
	printf("Sirul ordonat\n");
	for (i = 0; i < size; i++) {
		printf("%s\n", *(sir + i));
	}


}

void biti(char **sir, int size) {
	int i, j,biti;

	for (i = 0; i < size; i++) {
		biti = 0;
		printf("Elementul %s :\n", *(sir+i));
		for (j = 0; j <32 ; j++) {
			if ((1 << j)&strlen(*(sir + i))) {
				biti = j+1;
			}
		}

		printf("Reprezentarea binara a lungimii elementului \n");
		for (j = 31; j >= 0; j--) {
			if((strlen(*(sir+i))>>j) &1) printf("1"); 
			else printf("0");
		}

		printf("\n%d biti\n", biti);
	}


}

void lungime_vector(char** sir, int size) {
	int *vector= (int*)malloc(sizeof(int)*size);
	int i,j,aux;
	for (i = 0; i < size; i++) {
		*(vector + i) = strlen(*(sir + i));
	}

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


		printf("%d   ", *(vector + i));
	}
	printf("\n");

}
 
void lungime_putere(char** sir, int size) {
	int i=0,j=0,lungime=0,puterea;

	for (i = 0; i < size; i++) {
		lungime = strlen(*(sir + i));
		if (!(lungime & (lungime - 1))) {
			printf("%s are lungimea %d si este o putere  a lui 2.\n", *(sir + i), lungime);
			for (j = 31; j >=0 ; j--) {

				if (!(lungime >> j)) puterea = j - 1;
			}
			printf("Puterea este : %d\n", puterea);
		}
	}
	
}
int main()

{
	char **sir,buffer[21];
	int i,opt, size;



	printf("Cate cuvinte?\n");
	scanf("%d", &size);
	sir = (char**)malloc(sizeof(char*)*size);
	sir[0] = (char*)malloc(sizeof(char) *21);
	strcpy(sir[0], "cireasa");
	
	for (i = 1; i < size; i++) {
		do {
			printf("Cuvantul %d:    ", i + 1);
			getchar();
			scanf("%s", buffer);
		} while (validare(buffer)!=0);
		sir[i] = (char*)malloc(sizeof(char)*strlen(buffer) + 1);
		strcpy(sir[i], buffer);
	}

	while (1) {
		printf("0.Iesire\n");
		printf("1.Afisarea elementelor\n");
		printf("2.Ordonarea alfabetica\n");
		printf("3.Cati biti necesari pentru fiecare cuvant\n");
		printf("4. Lungimile intr-un vector si ordonate crescator\n");
		printf("5. Daca lungimea unui cuvant e o putere a lui 2\n");
		scanf("%d", &opt);

		switch (opt)
		{

		case 0: 
			free(sir); exit(0); break;
		case 1: afisare(sir, size); break;
		case 2: ordonare_alfabetica(sir, size); break;
		case 3: biti(sir, size); break;
		case 4: lungime_vector(sir, size); break;
		case 5: lungime_putere(sir, size); break;
		default: printf("Nu exista optiunea!\n");
			break;
		}
	}
}