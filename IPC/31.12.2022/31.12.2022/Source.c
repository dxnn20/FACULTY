#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

short int valid(char buffer[21]) {
	int i;
	if (buffer[0] >= 'A' && buffer[0] <= 'Z') {
		for (i = 1; i < strlen(buffer); i++) {
			if (buffer[i]<'a' || buffer[i]> 'z') {
				return 1;
			}
		}
		return 0;
	}
	else return 1;
}

void citire(char** sir, int size)
{
	int i;
	char buffer[21];
	for (i = 0; i < size; i++) {
		do {
			printf("Numele %d\n", i + 1);
			scanf("%s", buffer);

		} while ((valid(buffer))!=0);
		sir[i] = (char*)malloc(sizeof(char)*strlen(buffer) + 1);
		strcpy(sir[i], buffer);	
		
	}
}
void afisare(char **sir, int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("%s\n", sir[i]);
	}
}

void invers(char **sir, int size) {
	int i = 0, j = 0;
	char aux[21];
	for( i = 0; i< size-1 ; i++){
		for (j = i + 1; j < size; j++) {
			if (strcmp(sir[i], sir[j]) <0 ) {
				strcpy(aux, sir[i]);
				strcpy(sir[i], sir[j]);
				strcpy(sir[j], aux);
			}
		}
	}
	for (i = 0; i < size; i++) {
		printf("%s\n", sir[i]);
	}
}

void binar(char **sir, int size) {
	int i,  suma=0;

	for (i = 0; i < size; i++) {
		suma = suma + strlen(sir[i]);
	}
	printf("Suma e %d\n", suma);
	for (i = 31; i >= 0; i--) {
		if (((suma >> i) & 1) == 1) {
			printf("1");
		}
		else printf("0");
	}
}

void putere(char **sir, int size) {
	int i,lungime;

	for (i = 0; i < size; i++) {
		lungime = strlen(sir[i]);
		printf("Lungimea cuvantului %s este %d\n", sir[i], lungime);
		if( (lungime & (lungime-1)) == 0 ) printf("E putere a lui 2 \n");
		else printf("Nu e putere a lui 2\n");
	}
}

void reverse(char **sir, int size) {
	int i, j;
	for (i = 0; i < size; i++) {
		for (j = strlen(sir[i]); j >= 0; j--) {
			printf("%c", sir[i][j]);
		}
		printf("\n");
	}
}

void cuvant_litera(char **sir,int size) {
	int i;

	for (i = 0; i < size; i++) {
		printf("%c", sir[i][0]);
	}
	printf("\n");

}


int main() {
	char **sir;
	int size, opt,i;

	printf("Cate nume?\n");
	scanf("%d", &size);

	sir = (char**)malloc(sizeof(char*)*size);

	citire(sir, size);
	do {
		printf("\n-----Meniu-----\n");
		printf("0. Iesire\n");
		printf("1. Afisare\n");
		printf("2. Invers Alfabetica\n");
		printf("3. Lungimea tuturor elem. adunata si afisata in binar\n");
		printf("4. De verificat daca lungimea unui cuvant este o putere a lui 2 \n");
		printf("5. Fiecare nume in ordine inversa \n");
		printf("6. Cuvant format din primele litere ale fiecarui nume\n");
		printf("Introdu we\n");
		scanf("%d", &opt);

		switch (opt) {

		case 0:for (i = 0; i < size; i++) {
			free(sir[i]);
		} free(sir); break;
		case 1: afisare(sir, size); break;
		case 2: 
			invers(sir, size);
			break;
		case 3: binar(sir, size); break;
		case 4: putere(sir, size); break;
		case 5: reverse(sir, size);  break;
		case 6:  cuvant_litera(sir, size);  break;
		
		}
	} while (opt != 0);
}
