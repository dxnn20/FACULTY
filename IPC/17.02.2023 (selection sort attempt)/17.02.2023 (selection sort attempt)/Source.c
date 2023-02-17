#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void read(int *arr, int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("Element %d\t", i + 1);
		scanf("%d", arr + i);
	}
}

void print(int *arr, int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("Element %d:\t%d\n", i + 1, *(arr + i));
	}
}

void insertionSort(int *arr, int size){
	int i, j,key;


	for (i = 1; i < size; i++) {
		j = i - 1;
		key = *(arr + i);
		while (j >= 0 && key < *(arr+j)) {
			*(arr
 + j+1) = *(arr + j);
			j--;
		}
		*(arr + j + 1) = key;
	}
	print(arr, size);
}

void swap(int *arr, int a,int b) {
	int aux;
	aux = *(arr+a);
	*(arr+a) = *(arr+b);
	*(arr+b) = aux;
}

void selectionSort(int *arr, int size) {
	int min, i, j,temp_min;

	for (i = 0; i < size-1; i++) {
		temp_min = i;
		for (j = i + 1; j < size; j++) {
			if (*(arr + j) < *(arr + temp_min)) temp_min = j;
		}
		if (temp_min != i) swap(arr, i,temp_min);
	}
}

int main() {
	int *arr, size;

	printf("(insertion sort) Size:\t");
	scanf("%d", &size);
	arr = (int*)malloc(sizeof(int) * size);
	read(arr, size);
	printf("\n");

	insertionSort(arr, size);

	printf("Now using selection sort:\n");
		free(arr);
		printf("Size:\t");
		scanf("%d", &size);
		arr = (int*)malloc(sizeof(int) * size);

	read(arr, size);
	selectionSort(arr, size);
	
	printf("\n");
	print(arr, size);
}