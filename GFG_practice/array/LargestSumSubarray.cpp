// Kadane's algorithm

#include <bits/stdc++.h>
using namespace std;

int maxSumSubarray(int array[], int size) {
	int current_sum, max_sum;
	current_sum = max_sum = array[0];

	for (int i = 1; i < size; ++i) {
		current_sum = max(array[i], current_sum + array[i]);
		max_sum = max(max_sum, current_sum);
	}
	return max_sum;
}

int main(){
	int size;
	cout <<"Size of array :";
	cin >> size;

	int array[size];
	for (int i = 0; i < size; ++i) {
		cin >> array[i];
	}

	cout << maxSumSubarray(array, size);

	return 0;
}