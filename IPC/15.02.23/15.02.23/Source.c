#define _CRT_SECURE_NO_WARNINGS
//program that prints an hourglass made of the n-th letter of a word 
//and has decreasing items based on how many letters the word has
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void hourglass(char *word) {
	int nth,aux,j,k;
	float i;
	float lenght;
	printf("strlen : %d", strlen(word));
	printf("\nSelect the n-th character:\t");
	do {
		scanf("%d", &nth);
	} while (nth<0 || nth > (strlen(word)));
	printf("Selected letter: %d, %c\n", nth, *(word + nth-1)); // first letter should have the position 1
	aux = strlen(word);
	lenght =  (float)strlen(word) / 2;
	
	for (i = 0; i < lenght; i++) {
		printf("\n");
		for (j = 0; j < i; j++) {
			printf(" ");
		}
		for (k = aux-1; k >= 0; k--) {
			printf("%c", *(word + nth - 1));
		}
		aux-=2;
	}
	
	for (i = lenght; i>0; i--) {
		aux += 2;
		printf("\n");
		for (j = 0; j < i-1; j++) {
			printf(" ");
		}
		for (k = 0 ; k < aux ; k++) {
			printf("%c", *(word + nth - 1));
		}
	}
	printf("\n\n");
}
void read(char *word) {
	char buffer[101];
	printf("Input(max 100 letters): \t");
	scanf("%s", buffer);
	word = (char*)malloc(sizeof(char)*(strlen(buffer) + 1));
	strcpy(word, buffer);
	hourglass(word);

}

int main() {
	char *word=NULL;
	int opt;
	
	read(word);
	
	while (1) {
		
		printf("\n0.Exit\n");
		printf("1.Redo\n");
		scanf("%d", &opt);
		
		switch (opt)
		{
		case 0: free(word); exit(1); break;
		case 1: free(word); read(word); break;
		default: printf("man u trippin(option doesnt exist)\n");
			break;
		}
		
	}
}