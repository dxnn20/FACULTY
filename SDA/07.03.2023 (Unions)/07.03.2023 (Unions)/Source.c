#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>

typedef enum {tehnic,economic}profil;
typedef struct {
	int nota_bac, nota_4ani, nota_licenta;
}note;
typedef enum{medii, sup,doctorat}studii;

typedef struct{
	int zi, luna, an;
}dn;

typedef union {
	dn nastere;
	studii s;
	note nota;
	profil p;
}info;

typedef struct {
	char nume[20], prenume[20];
	float salariu;
	info informatii;

}angajat;

int load(angajat a[]) {
	FILE *f = fopen("emp.txt", "rt");
	int i = 0;
	while (!feof(f)) {
		fscanf(f, "%s%s%f%d%d%d", a[i].nume, a[i].prenume, &a[i].salariu, &a[i].informatii.nastere.zi, &a[i].informatii.nastere.luna, &a[i].informatii.nastere.an);
		fscanf(f, "%d", &a[i].informatii.s);
		
		switch (a[i].informatii.s)
		{
		case medii: fscanf(f, "%d%d", &a[i].informatii.nota.nota_4ani, &a[i].informatii.nota.nota_bac); break;
		case sup: fscanf(f, "%d", &a[i].informatii.nota.nota_licenta); break;
		case doctorat: fscanf(f, "%d", &a[i].informatii.p); break;
		default: printf("%s %s has errors in its declaration" ,a[i].nume,a[i].prenume); break;
		}
		i++;
	}
	return i;
}

void print(angajat a[],int n) {
	int i = 0;
	for (i; i < n; i++) {
		printf("%s %s\t%g %d/%d/%d\t%d", a[i].nume,a[i].prenume,a[i].salariu,a[i].informatii.nastere.zi, a[i].informatii.nastere.luna, a[i].informatii.nastere.an,a[i].informatii.s);
		/*switch (a[i].informatii.s)
		{

		case medii: printf("Nota4 \t%d  nota Bac: %d",a[i].informatii.nota.nota_4ani,a[i].informatii.nota.nota_bac);
		}
		printf("\n");*/
	}

}

int main() {
	angajat a[20];
	int n = load(a);
	print(a, n);
}