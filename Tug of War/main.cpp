#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int getLimitSize(int size) {
	return (size % 2) ? ( (size - 1) /2 ) : (size /2);
}

int getSum(int arr[], int size) {
	int sum = 0;
	for (int i = 0; i < size;i++){
		sum += arr[i];
	}
	return sum;
}

void TugWar(int arr[], int size, int numLeft, int current, int *sumLeft, int *bestValue, int* bestSumLeft) {
	if ( (numLeft  == getLimitSize(size)) && (current < size)  ) {
		int sumRight = getSum(arr,size) - *sumLeft;
		int current_different = abs(*sumLeft - sumRight);
		if (*bestValue > current_different) {
			*bestValue = current_different;
			*bestSumLeft = *sumLeft;
		}
		return;
	}

	for( int i = current; i  < size; i++) {
			numLeft++;
			*sumLeft = *sumLeft + arr[i];
			TugWar(arr,size,numLeft,i+1,sumLeft,bestValue,bestSumLeft);
			
			numLeft--;
			*sumLeft = *sumLeft - arr[i];
	}

}

void main() {
	//int arr[] = {3, 4,1};
	//int arr[] = {3, 4};
	// int arr[] = {3, 4, 5, -3, 100, 1, 89, 54, 23, 20};
	int arr[] = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};
	int size = sizeof(arr)/sizeof(int);
	int result = (101/100)%10;
	int *sumLeft = (int*)malloc(sizeof(int));
	*sumLeft = 0;

	int *bestSumLeft = (int*)malloc(sizeof(int));
	*bestSumLeft = 0;

	int *besValue = (int*)malloc(sizeof(int));
	*besValue = INT_MAX;

	int numLeft = 0;
	int current = 0;
	for (int i = current; i < size;i++)
		TugWar(arr,size,numLeft,i, sumLeft, besValue,bestSumLeft);

	cout << *bestSumLeft << "\n";
	cout << *besValue << "\n";
	

}