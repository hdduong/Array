#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

/*
Input array   =  [1, 23, 12, 9, 30, 2, 50] 
Output array =  50, 30 and 23

method 1: sort O(nlogn + k)
method 2: binary heap O(n + k);
*/

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

// heapify from i element
void heapify(int arr[], int i ,int size) {
	int left = 2*i + 1;
	int right = 2*i + 2;
	int maxPosition = i;
	int maxValue = arr[i];

	if ( (left < size) && (arr[i] < arr[left]) ) {
		maxPosition = left;
		maxValue = arr[left];
	}

	if ( (right < size) && (maxValue < arr[right]) ) {
		maxPosition = right;
		maxValue = arr[right];
	}

	if (maxPosition != i) {
		swap(&arr[i], &arr[maxPosition]);
	}
	
	if (maxPosition == left)
		heapify(arr,maxPosition,size);
	else if (maxPosition == right)
		heapify(arr,maxPosition,size);
	
}

void buildBinaryHeap(int arr[], int size) {
	for (int i = size/2-1; i >= 0; i--) {
		heapify(arr,i,size);
	}
}

int getMax(int arr[], int size) {
	int maxTmp = arr[0];
	arr[0] = arr[size-1];

	heapify(arr,0,size-1);

	return maxTmp;
}

void getKMax(int arr[], int size, int k) {
	buildBinaryHeap(arr,size);
	printArr(arr,size);

	for (int i = 0; i < k;i++) {
		int maxTmp = getMax(arr,size - i);
		cout << maxTmp << " ";
	}
	cout << "\n";
}

void main() {
	int arr[] = {1, 23, 12, 9, 30, 2, 50};
	int size = sizeof(arr)/sizeof(int);
	printArr(arr,size);
	
	getKMax(arr,size,3);
	printArr(arr,size);

}
