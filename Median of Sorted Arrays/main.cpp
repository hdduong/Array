#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;
/*
equal size
ar1[] = {1, 12, 15, 26, 38}
ar2[] = {2, 13, 17, 30, 45}

*/

int max(int a, int b) {
	return (a > b)?a:b;
}

int min(int a, int b) {
	return (a < b)?a:b;
}
int searchByMedian(int arr1[], int arr2[], int size) {
	int startArr1 = 0;
	int endArr1 = size-1;

	int startArr2 = 0;
	int endArr2 = size-1;

	
	while ( (endArr1 - startArr1 > 1) && (endArr2 - startArr2 > 1)) {
		int middleArr1 = startArr1 + (endArr1 - startArr1) /2; // in sorted array, middle elements is median
		int middleArr2 = startArr2 + (endArr2 - startArr2) /2;

		if (arr1[middleArr1] > arr2[middleArr2]) {
			endArr1 = middleArr1;
			if ( (endArr2 - startArr2) % 2 ==0) // to make sure 2 arrays have the same size
				startArr2 = middleArr2;	
			else 
				startArr2 = middleArr2 + 1;
		} else if (arr2[middleArr2] >= arr1[middleArr1]) {
			endArr2 = middleArr2;
			
			if ( (endArr1 - startArr1) % 2 ==0)
				startArr1 = middleArr1;
			else
				startArr1 = middleArr1 + 1;
		}
	}

	// Median = (max(ar1[0], ar2[0]) + min(ar1[1], ar2[1]))/2
	int median = max(arr1[startArr1], arr2[startArr2]) + min(arr1[endArr1], arr2[endArr2]);
	return median /2;
}


int medianByBinarySearch(int arr1[], int arr2[], int size) {
	int startArr1 = 0;
	int endArr1 = size -1;
	
	int startArr2 = 0;
	int endArr2 = size -1;
	

	int middleArr1 = startArr1 + (endArr1 - startArr1) /2;
	int correspondArr2 = size - middleArr1 - 1; 

	while( (middleArr1 < endArr1) && (middleArr1 > startArr1) )  {
		if ( (arr1[middleArr1] >= arr2[correspondArr2]) &&
			(arr1[middleArr1] <= arr2[correspondArr2+1]) ) {
			break;
		}

		if (arr1[middleArr1] < arr2[correspondArr2]) {
			startArr1 = middleArr1;
			middleArr1 = startArr1 + (endArr1 - startArr1) /2;
			correspondArr2 = size - middleArr1 - 1; 
		} else if (arr1[middleArr1] > arr2[correspondArr2]) {
			endArr1 = middleArr1;
			middleArr1 = startArr1 + (endArr1 - startArr1) /2;
			correspondArr2 = size - middleArr1 - 1; 
		}
	}

	
	return (arr1[middleArr1] + arr2[correspondArr2] ) /2;
}


void main() {
	int arr1[] = {1, 12, 15, 26, 38};
	int arr2[] = {2, 13, 17, 30, 45};

	 //int arr1[] = {1, 5, 7, 10, 13};
	 //int arr2[] = {11, 15, 23, 30, 45};
	
	//int arr1[] = {1, 2, 3, 6};
   // int arr2[] = {4, 6, 8, 10};



	int size = sizeof(arr1)/sizeof(int);

	// int median = searchByMedian(arr1,arr2,size);
	int median = medianByBinarySearch(arr1,arr2,size);

	cout << median << "\n";
}