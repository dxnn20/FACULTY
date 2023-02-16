#define _CRT_SECURE_NO_WARNINGS
#define size 10

#include <stdio.h>
#include <stdlib.h>


void insertionSort(int a[10], int length);

//tried recreating the same  algortithm using a pointer and no tutorials lol
void insertionSortV2(int *a, int lenght);
void forgotTheNameSort(int *a, int lenght);
int main() {
	int a[size],i,*arr = NULL,arraySize;
	printf("Input:(static, 10 elements)\n");
	for (i = 0; i < 10; i++)
		scanf("%d", &a[i]);
	
	insertionSort(a, 10);

	printf("Sorted array\n");
	for (i = 0; i < size; i++) {
		printf("a[%d] = %d\n", i, a[i]);
	}


	printf("\nDinaically allocated array\nWhat's the size?\n");
	scanf("%d", &arraySize);
	arr = (int*)malloc(sizeof(int)*arraySize);

	for (i = 0; i < arraySize; i++) {
		printf("a[%d] :\t",i); 
		scanf("%d", (arr + i));
	}
	insertionSortV2(arr, arraySize);
	
	printf("Sorted :\n");
	for (i = 0; i < arraySize; i++)
		printf("a[%d] =  %d\n", i, *(arr + i));


	printf("Scan an array of the same size array sorted using **forgot the name** sort\n");
	for (i = 0; i < arraySize; i++) {
		printf("a[%d] :\t", i);
		scanf("%d", (arr + i));
	}
	forgotTheNameSort(arr, arraySize);

	printf("Sorted array\n");
	for (i = 0; i < arraySize; i++)
		printf("a[%d] =  %d\n", i, *(arr + i));

}

void insertionSort(int a[10], int length) {
	int i = 0, key = 0, j = 0;


	for (i = 1; i < length; i++) {
		key = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > key) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
}

void insertionSortV2(int *a, int length) {
	int i, j,key;

	for (i = 0; i < length; i++) {
		printf("%d\n", *(a + i));
	}

	for (i = 1; i < length; i++) {
		key = *(a+i);
		j = i - 1;
		while (j >= 0 && *(a + j) > key) {
			*(a + j + 1) = *(a + j);
			j--;
		}
		*(a + j + 1) = key;
	}

	

}

void forgotTheNameSort(int *a, int length) {
	int i, valid,aux;

	do{
		valid = 1;
		for (i = 0; i < (length-1); i++) {
			if (*(a + i) > *(a + i + 1)) {
				aux = *(a + i);
				*(a + i) = *(a + i + 1);
				*(a + i + 1) = aux;
				valid = 0;
			}
		}	
		
	}while (valid != 1);
	
}
