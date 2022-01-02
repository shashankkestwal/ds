// link -> https://www.geeksforgeeks.org/find-maximum-average-subarray-of-k-length/

#include <bits/stdc++.h>
using namespace std;

int maxAverageaSubarray (int array[], int size, int k) {
	if (k > size) {
		return -1;
	}
	int maxAverage = 0 ;
	for (int i = 0; i < k; ++i) {
		maxAverage += array[i];	
	}
	int temp = maxAverage;
	int index = 0;
	for (int i = k; i < size; ++i) {
		temp += array[i] - array[i-k];
		if (temp > maxAverage) {
			maxAverage = temp;
			index = i + 1 - k;
		}
	}
	cout << maxAverage / k << " is the maximum average." << endl;
	return index;
}

int main() {
	int size;
	cout << "Enter the size of array : ";
	cin >> size;
	int array[size];
	for (int i = 0; i < size; ++i) {
		cin >> array[i];
	}
	int k;
	cout << "Enter the window size :";
	cin >> k;

	cout << "Starting index :" <<maxAverageaSubarray(array, size , k);

	return 0;
}