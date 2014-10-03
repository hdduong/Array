#include <stdio.h>
#include <stdlib.h>
#include <iostream>


// Dymaic programming style

using namespace std;

void printArray(int arr[], int n);

int maxSum(int arr[], int n) {
	
	int* tmpArr = (int*)malloc(sizeof(int) * (n + 1)); // contains max value at i position
	for (int i = 0; i <=n; i++) {
		tmpArr[i] = INT_MIN;
	}
	tmpArr[0] =arr[0];
	
	int max_so_far = INT_MIN;


	for (int i = 1; i <= n; i++) {
		if (arr[i] + tmpArr[i-1] < arr[i]) {
			tmpArr[i] = arr[i];
		} else {
			tmpArr[i] = arr[i] + tmpArr[i-1];
		}
		if (tmpArr[i] > max_so_far) max_so_far = tmpArr[i];
	}

	printArray(tmpArr,n);
	return max_so_far;
}

void printArray(int arr[], int n) {
	for (int i = 0; i <= n; i++) 
		cout << arr[i] << " ";

	cout << "\n";
}
void main() {
	int a[] =  {-2, -3, 4, -1, -2, 1, 5, -3};
	int size = sizeof(a)/sizeof(int);
	int n = size -1;

	int maxContinuous = maxSum(a,n);
	cout << maxContinuous << "\n";
}