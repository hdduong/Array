#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#define ARR_SIZE 4

using namespace std;


void printMatrix(int* arr[], int size) {
	for (int i = 0; i < size;i++) {
		for (int j = 0; j < size; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}	
	cout << "\n";
}

int** createArr(int size) {
	int** arr = (int**) malloc(sizeof(int*) * size);

	for (int i = 0; i < size; i++) {
		arr[i] = (int*)malloc(sizeof(int) * size);
	}
	
	arr[0][0] = 1; arr[1][0] = 5; arr[2][0] = 9; arr[3][0] = 3;
	arr[0][1] = 2; arr[1][1] = 6; arr[2][1] = 0; arr[3][1] = 4;
	arr[0][2] = 3; arr[1][2] = 7; arr[2][2] = 1; arr[3][2] = 5;
	arr[0][3] = 4; arr[1][3] = 8; arr[2][3] = 2; arr[3][3] = 6;
	
	return arr;
}

int** rotateMatrix(int** arr, int size) {
	int** b = createArr(size);

	//row i = column (n-i)
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			b[i][j] = arr[size-1-j][i];
		}
	}
	return b;
}
void main() {
	int **arr = createArr(ARR_SIZE);
	printMatrix(arr, ARR_SIZE);

	int **b = rotateMatrix(arr,ARR_SIZE);
	printMatrix(b,ARR_SIZE);
}