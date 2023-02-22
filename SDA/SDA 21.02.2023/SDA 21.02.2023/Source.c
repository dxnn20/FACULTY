#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>	
#include <time.h>

typedef struct persoana {
	char nume[21], prenume[21];
	int salariu;

}p;


//functie de stergere a textului
void clear() {

	int i = 0;
	fclose(fopen("file.txt", "w")); //sterge textul din fisier
}

void afisarePersoana(p persoana) {
	printf("Nume:  %s\nPrenume:  %s\nSalariu:  %d\n--------\n", persoana.nume, persoana.prenume, persoana.salariu);
}

int validareNumeCautat(char aux[21]) {
	if (aux[0] >= 'A' && aux[0] <= 'Z') 
		for (int i = 1; i < strlen(aux); i++) {
			if (aux[i] >= 'A' && aux[i] <= 'Z') {
				return 1;
			}
			return 0;
		}
	return 1;
}

int main() {
	srand(time(NULL));
	FILE *f;
	p *pers;
	char prenume[][21] = { "Marcel","Ion","Alex","Daniel","Georgiana","Maria"};
	char nume[][21] = {"Alexandrescu","Georgescu","Turuta","Mihailescu","Tamari"};
	char aux[21]; // numele pe care il vom cauta in lista generata
	int random,size = 10+rand()%(40),check=0; //maxim 50 de oameni in lista, minim 10
	
	if ((f = fopen("text.txt", "rt"))==NULL) {
		printf("Fisierul nu exista!");
		return -1;
	}
	f = fclose(f);
	f = fopen("text.txt", "wt"); //redeschid fisierul in write mode

	//genereaza elemente in fisier
	printf("Size:\t%d", size); //maxim 30 de persoane generate in lista

	//pentru a filtra ulterior datele le stochez intr-0 structur
		pers = (p*)malloc(sizeof(p)*size);

	for (int i = 0; i < size; i++) {
			random = rand() % 5;
				fprintf(f,"Nume: %s\n", nume[random]);
					strcpy((pers + i)->nume, nume[random]); 
			random = rand()%5;
				fprintf(f, "Prenume: %s\n", prenume[random]);
					strcpy((pers + i)->prenume, prenume[random]);
			random = 1000 + rand() % (4000); //salariu minim = 1000 , maxim 50000
				fprintf(f,"Salariu:%d\n------------\n",random);// folosesc variabila random ca valoarea salariului pentru a nu defini o alta variabila
					(pers + i)->salariu = random;
	}

	
	do {
		printf("\nAfiseaza toti angajatii cu prenumele(prenumele trebuie sa corespunda standardului(prima litera mare,restul mici)):\n");
		scanf("%s", aux);
	} while (validareNumeCautat(aux));

	for (int i = 0; i < size; i++) {
		if (!strcmp((pers + i)->prenume, aux)) {
			afisarePersoana(*(pers + i));
			check++;
		}
	}
	if (check == 0) printf("Nu exista persoana cu numele introdus!\n");


	/* apelarea functiei de stergere a textului

	printf("\nClear?\n");
	scanf("%d", &opt);
	switch (opt)
	{
	case 0: fclose(f); return 0;
	case 1: clear(); break;
	default:
		break;
	}*/


	fclose(f);
	return 0;
}