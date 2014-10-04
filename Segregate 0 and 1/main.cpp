#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

/*
Input array   =  [0, 1, 0, 1, 0, 0, 1, 1, 1, 0] 
Output array =  [0, 0, 0, 0, 0, 1, 1, 1, 1, 1] 

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



// method 1: count always work
// method 2: two indexes and exchange in place
// method 2a: easier: two pointer to left, right and exchange
void segregateArr(int arr[], int size) {
	int i0 = 0;
	int i1 = 0;

	bool continueLoop = true;
	while(continueLoop) {
		if ( (arr[i0] == 0) && (arr[i1] == 0) ) {
			i1++;
			while ( (i1 < size) && (arr[i1] != 1) ) {
				i1++;
			}
			if (i1 >= size) continueLoop = false;
		}
		else if ( (arr[i0] == 1) && (arr[i1] == 1) ) {
			i0++;
			while ( (i0 < size) && (arr[i0] != 0) ) {
				i0++;
			}
			if (i0 >= size) continueLoop = false;
		}
		else if ( (arr[i0] == 0) && (arr[i1] == 1 )) {
			if (i0 > i1) {
				swap(&arr[i0], &arr[i1]);	
				i1++;
				while ( (i1 < size) && (arr[i1] != 1) ) {
					i1++;
				}
			}
			// next 0 element
			i0++;
			while ( (i0 < size) && (arr[i0] != 0) ) {
				i0++;
			}
			if (i0 >= size) continueLoop = false;
		}
		/*else if ( (arr[i1] == 0) && (arr[i0] == 1 )) {

		}*/
	}
}


void main() {
	//int arr[] = {0, 1, 0, 1, 0, 0, 1, 1, 1, 0}; 
	int arr[] = {0, 1, 0, 1, 1, 1};
	int size = sizeof(arr)/sizeof(int);
	printArr(arr,size);

	segregateArr(arr,size);
	printArr(arr,size);

}


