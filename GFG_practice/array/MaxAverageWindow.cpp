// link -> https://www.geeksforgeeks.org/find-subarray-least-average/
#include <bits/stdc++.h>
using namespace std;

void indexSmallestAverage(int array[], int size , int window) {
	int min_ave = 0;
	int index = window;
	for (int i = 0; i < window; ++i) {
		min_ave += array[i];
	}

	int curr = min_ave;
	for (int i = window; i < size ; ++i) {
		curr = curr + array[i] - array[i - window];
		if (curr < min_ave) {
			min_ave = curr;
			index = i;
			cout << index << endl;
		}
	}

	cout << "indexes within which minimum averge lies is " << index - window + 1<<" to " << index << endl;
}

int main() {
	int size;
	cout <<"Size of array :";
	cin >> size;

	int array[size];
	for (int i = 0; i < size; ++i) {
		cin >> array[i];
	}
	int window;
	cout << "Enter window size: ";
	cin >> window;

	indexSmallestAverage(array, size,window);

	return 0;
}