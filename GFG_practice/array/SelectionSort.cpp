#include <bits/stdc++.h>
using namespace std;

int selectionSort(int array[], int size) {
	int count = 0;
	for (int i = 0; i < size; ++i) {
		int j = i;
		int min_index = -1;
		int &key = array[i];
		while(j < size ) {
			if (array[j] < key) {
				min_index = j;
			}
			count++;
			j++;
		}
		if (min_index != -1) {
			swap(key, array[min_index]);
		}
	}
	return count;
}

void printArray(int array[], int size) {
	for (int i = 0; i < size; ++i) {
		cout << array[i] << "  ";
	}
	cout << endl;
}

int main() {
	int size;
	cout << "Enter array size : ";
	cin >> size;
	int array[size];
	cout << "Enter array elements : ";
	for (int i = 0; i < size; ++i) {
		cin >> array[i];
	}

	cout << "Total number of comparisons in sorting the list are : " << selectionSort(array, size) << endl;
	printArray(array, size);

	return 0;
}