// link -> https://www.geeksforgeeks.org/count-minimum-steps-get-given-desired-array/

#include <bits/stdc++.h>
using namespace std;

void decrementIndex(int &value) {
	value--;
}

void doubleArrayElements(int array[], int size) {
	for (int i = 0; i < size; ++i) {
		array[i] = array[i] / 2; 
	}
}

bool gotResult(int array[], int size) {
	for (int i = 0; i < size; ++i) {
		if (array[i] != 0) {
			return false;
		}
	}
	return true;
}

int minStepsCount(int array[], int size) {
	int count  = 0;
	
	while(true) {
		if (gotResult(array, size)) {
			return count;
		} 
		bool double_operation;
		for (int i = 0; i < size; ++i) {
			double_operation = true;
			if (array[i] % 2 != 0) {
				decrementIndex(array[i]);
				double_operation = false;
				count++;
				break;
			}
		}
		if (double_operation == true) {
			doubleArrayElements(array, size);
			count++;
		}
	}	
} 

int main() {
	int size;
	cout << "Array size : ";
	cin >> size;
	int array[size];
	cout << "Enter desired array : ";
	for (int i = 0; i < size; ++i) {
		cin >> array[i];
	}
	cout << minStepsCount(array, size);

	return 0;
}