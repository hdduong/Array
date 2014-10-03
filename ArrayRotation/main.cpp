#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;
/*
equal size
ar1[] = {1, 2, 3, 4, 5, 6, 7}
		{3, 4, 5, 6, 7, 1, 2}
		n: size
		d: d rotates on left = 2
*/

void printArr(int arr[], int size) {
	
	for (int i = 0; i < size; i++) {
		cout <<  arr[i] << " ";	
	}
	cout << "\n";
}

// 0(n) complexity and 0(d) space
// method 2: move d time, each time move left 1
void method1(int arr[], int size, int d) {
	if (d == size) return ; // no need to do
	d = d % size; //case when d > size

	int*tmpArr = (int*)malloc(sizeof(int) * d);

	for (int i = 0; i < d;i++) {
		tmpArr[i] = arr[i];	
	}

	for (int i = d; i < size; i++) {
		arr[i-d] = arr[i];
	}

	for (int i = 0; i < d;i++) {
		arr[size - i - 1] = tmpArr[i];	
	}

	tmpArr = NULL;
	free(tmpArr);
}



void swap (int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

// reverse between(start, end)
void reverseArr(int arr[], int start, int end) {
	int middle = start + (end - start) / 2;

	for (int i = start; i < middle; i++) {
		swap(&arr[i], &arr[end-i + start]);
	}
}

/*
For arr[] = [1, 2, 3, 4, 5, 6, 7], d =2 and n = 7
A = [1, 2] and B = [3, 4, 5, 6, 7]
Reverse A, we get ArB = [2, 1, 3, 4, 5, 6, 7]
Reverse B, we get ArBr = [2, 1, 7, 6, 5, 4, 3]
Reverse all, we get (ArBr)r = [3, 4, 5, 6, 7, 1, 2]

OR 
1, 2, 3, 4, 5, 6, 7
7, 6, 5, 4, 3, 2, 1 reverse n-d and n-d+1, n
3, 4, 5, 6, 7, 1, 2
*/

void method2a(int arr[], int size, int d) {
	reverseArr(arr,0,size-1);
	reverseArr(arr,0,size - d -1);
	reverseArr(arr,size-d, size-1);
}

void main() {
	int arr[] = {1, 2, 3, 4, 5, 6, 7};
	int size = sizeof(arr)/sizeof(int);
	int d = 2;

	//method1(arr,size,2);
	reverseArr(arr,0,6);

	printArr(arr,size);
}