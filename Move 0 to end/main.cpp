#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;


void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++) 
		cout << arr[i] << " ";

	cout << "\n";
}

int findNextPositive(int arr[], int size, int start) {
	// find next element > 0 that begin from start
	int i = start;
	while( (i < size) && (arr[i] == 0 )) {
		i++;
	}
	if (i == size)  i = -1;
	return i;
}

void move0(int arr[], int size) {
	int currentZero = 0;
	int nextPointer = 0;
	int prevPointer = nextPointer;

	while(currentZero < size) {
		if (arr[currentZero] > 0) {
			currentZero++;
		} else {
			if (prevPointer == 0) prevPointer = currentZero;
			nextPointer = findNextPositive(arr,size,prevPointer);
			if (nextPointer == - 1) break;

			swap(arr[currentZero], arr[nextPointer]);
			
			prevPointer = nextPointer;
			currentZero++;
		}
	}
	
}



void main() {
	int arr[] = {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0};
	int size = sizeof(arr)/sizeof(int);
	move0(arr,size);
	printArray(arr,size);

}