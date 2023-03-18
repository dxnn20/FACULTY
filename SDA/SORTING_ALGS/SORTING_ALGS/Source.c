#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef enum {terminate,insertion, selection,shaker,radix_direct}optiuni;

void swap(int *a, int  *b) {
	int aux = *a;
	*a = *b;
	*b = aux;
}

int biti(int x, int k, int j)
{
	return (x >> k) & ~(~0 << j);
}

void citire(int *a,int n) {

	for (int i = 0; i < n; i++) {
		printf("Element %d\t", i + 1);
		scanf_s("%d", a + i);
	}
}

void afisare(int *a, int n) {
	int newline = 0;
	for (int i = 0; i < n; i++) {
		printf("%d\t",*(a+i));
		if (newline == 10) {
			printf("\n");
			newline = 0;
		}
	}
	printf("\n");
}

void insertionSort(int *a, int n) {
	int i, j;
	for (i = 1; i < n ; i++) {
		j = i - 1;
		int aux = *(a + i);
		while (j >= 0 && aux < *(a+j)) {
			*(a + j + 1) = *(a + j);
			j--;
		}
		*(a + j + 1) = aux;
	}
}

void selectionSort(int *a, int n) {
	int i, j,temp_min;

	for (i = 0; i < n - 1; i++) {
		temp_min = i;
		for (j = i + 1; j < n; j++) {
			if (*(a + j) < *(a + temp_min))
				temp_min = j;
		}
		if (temp_min != i)
			swap(a + i, a + temp_min);
	}

}

void shakerSort(int *a, int n)
{
	int  j, k, s, d, aux, count = 1;
	s = 1;
	d = n - 1;
	k = n - 1;
	do
	{
		for (j = d; j >= s; j--)
			if (*(a+j-1) > *(a+j))
			{
				swap(a + j, a + j - 1);
				k = j;
			}
		s = k + 1;
		for (j = s; j <= d; j++)
			if (*(a+j-1) > *(a+j))
			{
				swap(a + j - 1, a + j);
				k = j;
			}
		d = k - 1;
		printf("\nEtapa %d: ", count);
		afisare(a, n);
		count++;

	} while (s <= d);
	printf("\n");
}

void radixSortD(int *a, int n) {

	int b, T[100], Number[100], m, k, i, t;
	b = sizeof(int) * 8;
	m = 4;
	for (t = 0; t < b / m; t++)
	{
		for (i = 0; i < pow(2, m); i++)
			Number[i] = 0;
		for (i = 0; i < n; i++)
		{
			k = biti(a[i], t * m, m);
			Number[k]++;
		}
		for (i = 1; i < pow(2, m); i++)
			Number[i] += Number[i - 1];

		for (i = n - 1; i >= 0; i--)
		{
			k = biti(a[i], t * m, m);
			T[Number[k] - 1] = a[i];
			Number[k]--;
		}
		printf("Etapa %d: ", t + 1);
		afisare(T, n);
		for (i = 0; i < n; i++)
			a[i] = T[i];
	}
	printf("\n");
}


int main() {
	int *a, length;
	enum optiuni opt;

	while (1) {
		printf("\n0. Exit\n");
		printf("1. Insertion sort\n");
		printf("2. Selection sort\n");
		printf("3. Shaker sort\n");
		printf("4. Direct Radix sort");

		scanf_s("%d", &opt);
		
		switch (opt)
		{
		case terminate: 
			exit(0);
			break;

		case insertion: 
			printf("Length:\t");
			scanf_s("%d", &length);
			a = (int*)malloc(sizeof(int)*length);
			citire(a, length);

			printf("Before sorting:\n");
			afisare(a, length);
			printf("\nAfter sorting\n");
			insertionSort(a, length);
			afisare(a, length);

			free(a);
			break;

		case selection:
			printf("Length:\t");
			scanf_s("%d", &length);
			a = (int*)malloc(sizeof(int)*length);
			citire(a, length);

			printf("Before sorting:\n");
			afisare(a, length);
			printf("\nAfter sorting\n");
			selectionSort(a, length);
			afisare(a, length);

			free(a);

		case shaker: 
			printf("Length:\t");
			scanf_s("%d", &length);
			a = (int*)malloc(sizeof(int)*length);
			citire(a, length);

			printf("Before sorting:\n");
			afisare(a, length);
			printf("\nAfter sorting\n");
			shakerSort(a, length);
			afisare(a, length);

			free(a);
			break;

		case radix_direct:
			printf("Length:\t");
			scanf_s("%d", &length);
			a = (int*)malloc(sizeof(int)*length);
			citire(a, length);

			printf("Before sorting:\n");
			afisare(a, length);
			printf("\nAfter sorting\n");
			radixSortD(a, length);
			afisare(a, length);

			free(a);
			break;
		default:
			printf("No such option.\n");
			break;
		}



	}
}