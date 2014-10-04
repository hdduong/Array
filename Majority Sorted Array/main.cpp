#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

/*
Input: arr[] = {1, 2, 3, 3, 3, 3, 10}, x = 3
Output: True (x appears more than n/2 times in the given array)

Input: arr[] = {1, 1, 2, 4, 4, 4, 6, 6}, x = 4
Output: False (x doesn't appear more than n/2 times in the given array)

Input: arr[] = {1, 1, 1, 2, 2}, x = 1
Output: True (x appears more than n/2 times in the given array)
*/

void printArr(int arr[], int size) {
	
	for (int i = 0; i < size; i++) {
		cout <<  arr[i] << " ";	
	}
	cout << "\n";
}

int binarySearchFirstOccur(int arr[], int start, int end, int X) {
	int firstAppear = -1;

	if(start <= end) {
		int middle = start + (end - start) /2;

		if (arr[middle] == X) {
			if (arr[middle - 1] != X) {
				firstAppear = middle;
			} else {
			   // find more on the left
				firstAppear =  binarySearchFirstOccur(arr,start,middle-1,X);
			}
		}

		if (arr[middle] < X) {
			int tmpAppear = binarySearchFirstOccur(arr,middle+1,end,X);
			if (tmpAppear != -1) firstAppear = tmpAppear;
		} else if(arr[middle] > X) {
			int tmpAppear =  binarySearchFirstOccur(arr,start,middle-1,X);
			if (tmpAppear != -1) firstAppear = tmpAppear;
		}
	}

	return firstAppear;
}

bool isMajority(int arr[], int size, int X) {
	int start= 0;
	int end = size -1;

	int firstOc = binarySearchFirstOccur(arr,start,end,X);

	if ( ((firstOc + size/2) < size) && (arr[firstOc + size/2] == X) )
		return true;

	return false;
		
}
void main() {
	int arr[] = {1, 2, 3, 3, 3, 3, 10};
	//int arr[] = {1, 1, 2, 4, 4, 4, 6, 6};
	//int arr[] = {1 ,1 ,1,2,2};

	int size = sizeof(arr)/sizeof(int);
	int start = 0;
	int end = size - 1;
	int X = 3;
	printArr(arr,size);

	bool isMajoryElement = isMajority(arr,size,X);
	cout << isMajoryElement << "\n";


}

