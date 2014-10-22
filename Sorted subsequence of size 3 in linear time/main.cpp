#include <stdlib.h>
#include <iostream>
#include <stdio.h>

using namespace std;

void find3(int arr[], int size) {

	int* current_min_1st = NULL;
	int* current_min_2nd = NULL;
	int* tmp_min_1st = NULL;
	
	for (int i = 0; i < size; i++) {
		if ( (current_min_1st != NULL) && (current_min_2nd != NULL) ) {
			if (arr[i] > *current_min_2nd) { // asssume that current_min_2nd > current_min_1st
				cout << *current_min_1st <<  " " << *current_min_2nd << " " << arr[i];
				return;
			} else if (arr[i] < *current_min_2nd) {
				if (arr[i] > *current_min_1st) {
					*current_min_2nd = arr[i];
				}
				else if (arr[i] < *current_min_1st) {
					if (tmp_min_1st == NULL) {
						tmp_min_1st = (int*)malloc(sizeof(int));
						*tmp_min_1st = arr[i];
					} else if (tmp_min_1st != NULL) {
						*current_min_1st = *tmp_min_1st;
						*current_min_2nd = arr[i];
					}
				}
			}
		}
		
		if (current_min_1st == NULL) {
			current_min_1st = (int*)malloc(sizeof(int));
			*current_min_1st = arr[i];
		} else if ( (current_min_1st != NULL) && (current_min_2nd == NULL)) {
			if (arr[i] > *current_min_1st) {
				current_min_2nd = (int*)malloc(sizeof(int));
				*current_min_2nd = arr[i];
			} else if (arr[i] < *current_min_1st) {
				*current_min_1st = arr[i];
			}
		}

	}
	cout << "No such triplet";
}

void main() {
	//int arr[] = {12, 11,10,5,6,2,30};
	//int arr[] = {1,2,3,4};
	int arr[] = {4, 3, 2, 1};
	int size = sizeof(arr)/sizeof(int);
	find3(arr,size);
	cout << "\n";
}
		  