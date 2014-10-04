#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;
/*
2, 4, 1, 5, 3
(2,1) (4,1) (4,3) (5,3)
*/

void printArr(int arr[], int size) {
	
	for (int i = 0; i < size; i++) {
		cout <<  arr[i] << " ";	
	}
	cout << "\n";
}


void merge(int arr[], int start1, int end1, int start2, int end2, int *inv1) {
	// end1 < start2
	int *b = (int*) malloc(sizeof(int) * ( (end1-start1+1) + (end2-start2+1) ) );
	int fi = start1;
	int si = start2;
	int bCount = 0;

	while( (fi <= end1) && (si <= end2) ) {
		if (arr[fi] < arr[si]) {
			b[bCount] = arr[fi];
			fi++;
		} else if (arr[fi] > arr[si]) {
			b[bCount] = arr[si];
			si++;
			*inv1 = *inv1 + (end1 - fi + 1);
		}
		bCount++;
	}

	while(fi <= end1) {
		b[bCount] = arr[fi];
		fi++;
		bCount++;
	}

	while(si <= end2) {
		b[bCount] = arr[si];
		si++;
		bCount++;
	}

	for (int i = start1, j = 0; i <= end2, j < bCount; i++,j++) {
		arr[i] = b[j];
	}
}


void countInverse(int arr[], int start, int end, int *totalInv) {

	if (start < end) {
		int middle = start + (end - start) /2;
		countInverse(arr, start, middle,totalInv);
		countInverse(arr,middle+1, end,totalInv);
		merge(arr,start,middle, middle+1,end,totalInv);
	}

}


void main() {
	int arr[] = {2, 4, 1, 3, 5};
	int size = sizeof(arr)/sizeof(int);
	int start = 0;
	int end = size - 1;
	printArr(arr,size);

	cout << "\n";
	cout << "\n";

	int totalInv = 0;
	countInverse(arr,start,end,&totalInv);
	cout << totalInv << "\n";
	printArr(arr,size);
}