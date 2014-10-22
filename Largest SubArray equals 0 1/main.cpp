#include <stdlib.h>
#include <iostream>
#include <stdio.h>

using namespace std;

void getSmaller(int arr[], int size, int *value, int *count) {
	int numberOf1 = 0;
	int numberOf0 = 0;

	for (int i = 0; i < size; i++) {
		(arr[i] == 1)? (numberOf1++): (numberOf0++);
	}
	
	if ( (numberOf0 == 0) || (numberOf1 == 0) ) {
		*count = -1;
		*value = -1;
		return;
	}
	else {
		if ( numberOf0 >= numberOf1) {
			*value = 1;
			*count = numberOf1;
		}
		else {
			*value = 0;
			*count = numberOf0;
		}
	}
}

void findSubArray(int arr[], int size, int *startIndex, int *endIndex) {
	int *smallerCount = (int*)malloc(sizeof(int));
	int *smallerValue = (int*)malloc(sizeof(int));
	getSmaller(arr,size,smallerValue,smallerCount);

	if (*smallerValue == -1) {
		*startIndex = *endIndex = -1;
		return;
	}
	int current0Index = 0;
	int current1Index = 0;
	int current0Count = 0;
	int current1Count = 0;

	for (int i = 0; i < size; i++) {
		if ( (current0Index != 0) && (current1Index!=0) )
			break;

		if ( (arr[i] == 0) && (current0Index == 0) ) {
			current0Count++;
			if (current0Count == *smallerCount) {
				current0Index = i;
			}
		}

		if ( (arr[i] == 1) && (current1Index == 0) ) {
			current1Count++;
			if (current1Count == *smallerCount) {
				current1Index = i;
			}
		}
	}

	*endIndex = (current0Index > current1Index)? current0Index: current1Index;
	*startIndex = (*endIndex + 1) - 2 * (*smallerCount);

	free(smallerCount);
	free(smallerValue);
}

void main() {
	int arr[] = {1,0,0,1,0,1,1};
	int size = sizeof (arr)/sizeof(int);

	int *startIndex = (int*)malloc(sizeof(int));
	int *endIndex = (int*)malloc(sizeof(int));

	findSubArray (arr,size,startIndex, endIndex);
	if (*startIndex == -1 )
		cout << "No such subarray \n";
	else 
		cout << *startIndex << " " << *endIndex << "\n";

	free(startIndex);
	free(endIndex);
}