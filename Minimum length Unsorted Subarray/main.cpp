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


void swap (int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/****/
// This method only find the farthest on the right arr[i] > arr[i+1] which is incorrect
// Have to find i, j on left and right, then min,max of i,j then expand from that
/****/
void findMinUnsorted(int arr[], int size, int *left, int *right) {
	int i = 0;
	int crossPoint = 0;

	while (i < size) {
		// step 1: find farthest element that arr[i] > arr[i+1];
		if (i + 1 < size) {
			if ( (arr[i] > arr[i+1]) && (i+1 > crossPoint))
				crossPoint = i+1;
		}
		i++;
	}

	// step 2: find greatest element < crossPoint
	int j = crossPoint-1;
	int maxBack = arr[crossPoint];
	int maxMinCrossPoint = INT_MIN;
	
	while (j >= 0) {
		if ( (arr[j] < arr[crossPoint] && (arr[j] > maxMinCrossPoint) )) {
			*left = j;			
			maxMinCrossPoint = arr[j];
		}
		if (arr[j] > maxBack) maxBack = arr[j];
		j--;
	}
	
	// step 3: find smallest element > maxBack
	int k = *left;
	while (k < size) {
		if (arr[k] > maxBack) break;
		k++;
	}
	*right = k-1;
}

void main() {
	
	//int arr[] = {10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60};
	int arr[] = {0, 1, 15, 25, 6, 7, 30, 40, 50};
	int size = sizeof(arr)/sizeof(int);
	printArr(arr,size);

	int *left = (int*)malloc(sizeof(int));
	int *right = (int*)malloc(sizeof(int));
	*left = *right = -1;

	findMinUnsorted(arr,size,left,right);

	cout << *left << " " << *right << "\n";
	
}


