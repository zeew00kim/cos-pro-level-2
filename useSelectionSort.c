#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

void selectionSort(int* arr, int num);
void printArr(int* arr, int num);
int getSumValue(int* arr, int num, int m);

int main() {

	int n;
	int m = 0;
	int solution;
	int sum = 0;

	srand(time(NULL));

	do {
		printf("enter the value of n (1 ~ 1000) : ");
		scanf("%d", &n);
		if (!(n >= 1 && n <= 1000)) {
			puts("retry it...");
		}
	} while (!(n >= 1 && n <= 1000));

	do {
		if (n == 1) {
			puts("break program...");
			break;
		}
		printf("enter the value of m (2 ~ 50 && m < n) : ");
		scanf("%d", &m);
		if ((m >= 2 && m <= 50) && !(m < n)) {
			puts("retry it...");
		}
	} while ((m >= 2 && m <= 50) && !(m < n));
	
	int* arr = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 10 + 1;
	}

	selectionSort(arr, n);
	printArr(arr, n);
	solution = getSumValue(arr, n, m);

	printf("result of solution func : %d\n", solution);

	free(arr);

	return 0;
}

void selectionSort(int* arr, int num) {

	for (int i = 0; i < num - 1; i++) {
		int minIdx = i;
		for (int j = i + 1; j < num; j++) {
			if (arr[j] < arr[minIdx]) {
				minIdx = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[minIdx];
		arr[minIdx] = temp;
	}
}

void printArr(int* arr, int num) {
	
	printf("arr[%d] = { ", num);
	for (int i = 0; i < num; i++) {
		printf("%d", arr[i]);
		if (i != num - 1) {
			printf(", ");
		}
		else if (i == num - 1) {
			printf(" }\n");
		}
	}
}

int getSumValue(int* arr, int num, int m) {

	int sum = 0;

	for (int i = 1; i < num; i++) {
		if (arr[i] % m == 0) {
			sum += arr[i];
		}
	}

	return sum;
}