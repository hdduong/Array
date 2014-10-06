#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

void printArr(int arr[], int size) {
	
	for (int i = 0; i < size; i++) {
		cout <<  arr[i] << " ";	
	}
	cout << "\n";
}

int countOccur(int arr[], int start, int end, int X) {
	if (start <= end) {
		int middle  = start + (end - start) /2;

		if (arr[middle] == X) {
			int numLeftOcc = countOccur(arr, start, middle-1, X);
			int numLRightOcc = countOccur(arr, middle + 1, end, X);

			numLeftOcc  = (numLeftOcc != -1) ? numLeftOcc : 0;
			numLRightOcc  = (numLRightOcc != -1) ? numLRightOcc: 0;

			return (numLeftOcc + numLRightOcc + 1);
		}

		else if (arr[middle] < X) {
			return countOccur(arr,middle + 1, end, X);
		}
		else if (arr[middle] > X) {
			return countOccur(arr,start, middle - 1, X);
		}

	}

	return -1;
}

int countOccur(int arr[], int size, int X) {
	return countOccur(arr,0,size-1,X);	
}

void main() {
	
	int arr[] = {1, 1, 2, 2, 2, 2, 3};
	int size = sizeof(arr)/sizeof(int);
	printArr(arr,size);

	int X = 1;
	int numOccur = countOccur(arr,size,4);
	cout << numOccur << "\n";
	
}
