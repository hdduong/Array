#include <stdlib.h>
#include <iostream>
#include <stdio.h>

using namespace std;

struct aPair {
	int first_elment;
	int second_element;
};

void printPair(aPair arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << "{" << arr[i].first_elment << "," << arr[i].second_element << "} ";
	}
	cout << "\n";
}

// =-1: means 2nd element of 1st pair > 1st element of 2nd pair 
// = 1: means 2nd element of 1st pair < 1st element of 2nd pair
int comparePair(aPair pair1, aPair pair2) {
	if (pair1.second_element < pair2.first_elment)
		return 1;

	if (pair1.second_element > pair2.first_elment)
		return -1;
}

int maxChain(aPair arr[], int size) {
	
	int max_length_ending_here = 0;
	int max_lenght_ending_so_far = 1;

	for (int i = 1; i < size; i++) {
		for (int j = 0; j < i;j++) {
			if (comparePair(arr[j],arr[i]) == 1) { //second pair bigger
				max_length_ending_here++;
			}
		}
		
		if (max_length_ending_here > max_lenght_ending_so_far)
			max_lenght_ending_so_far = max_length_ending_here;

		max_length_ending_here = 0;
	}

	return max_lenght_ending_so_far;
	
}

void main() {
	aPair arr[] = {{5,24},{39, 60}, {15, 28}, {27, 40}, {50, 90}};
	int size = sizeof(arr)/sizeof(aPair);

	printPair(arr,size);

	int maxChainNo = maxChain(arr,size);
	cout << maxChainNo << "\n";
}