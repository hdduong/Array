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
int maxof2(int a, int b) {
	return (a > b)? a: b;
}

int maxof3(int a, int b, int c) {
	return maxof2( maxof2(a,b), maxof2(b,c) );
}

int maxSum(int arr[], int size) {
	int maxUntil = INT_MIN;
	int maxUtil_i_2 = INT_MIN;
	int maxUtil_i_3 = INT_MIN;
	int maxUtil_i_1 = INT_MIN;

	for (int i = 0; i < size; i++) {
		if (i > 3) {
				maxUtil_i_3 = maxUtil_i_2;
				maxUtil_i_2 = maxUtil_i_1;
				maxUtil_i_1 = maxUntil;
			int currentMax = maxof3(arr[i], arr[i] + maxUtil_i_2, arr[i] +maxUtil_i_3);
			maxUntil = (maxUntil<currentMax)?currentMax:maxUntil;
		}
		else {
			if (i == 2) {
				maxUtil_i_2 = arr[i-2];
				maxUtil_i_1 = arr[i-1];
				int currentMax = maxof2(arr[i], arr[i] + maxUtil_i_2);
				maxUntil = (maxUntil<currentMax)?currentMax:maxUntil;
			} else if (i == 3) {
				maxUtil_i_3 = arr[i-3];
				maxUtil_i_2 = maxUtil_i_1;
				maxUtil_i_1 = maxUntil;
				int currentMax = maxof3(arr[i], arr[i] + arr[i-2], arr[i] + maxUtil_i_3);
				maxUntil = (maxUntil<currentMax)?currentMax:maxUntil;
			} else {
				int currentMax = arr[i];
				maxUntil = (maxUntil<currentMax)?currentMax:maxUntil;
			}
		}
	}
	return maxUntil;
}

void main() {
	//int arr[] = {5, 5, 10, 40, 50, 35};
	int arr[] = {5, 5, 10, 100, 10, 5};
	int size = sizeof(arr)/sizeof(int);

	// cout << maxof3(5,3,4) << "\n";

	int maxNoAdj = maxSum(arr, size);
	cout << maxNoAdj << "\n";
	//printArr(arr,size);
}