// link -> https://www.geeksforgeeks.org/find-minimum-number-of-merge-operations-to-make-an-array-palindrome/


#include <bits/stdc++.h>
using namespace std;

void mergeFrontElements(int array[], int size , int &i , int &j) {
	array[i] += array[i+1];
	for (int x = i+1; x < j; ++x) {
		array[x] = array[x+1];
	}
	j--;
}

void mergeEndElements(int array[], int size , int &i , int &j) {
	array[j-1] += array[j];
	j--;
}

void performNextOperation(int array[], int size, int &i , int &j) {
	if (array[i] > array[j] && array[i+1] > 0) {
		mergeFrontElements(array, size , i, j);
	} else if (array[i] > array[j] && array[i+1] < 0) {
		mergeEndElements(array, size, i, j);
	} else if (array[j] > array[i] && array[j-1] > 0) {
		mergeFrontElements(array, size , i, j);
	} else if (array[j] > array[i] && array[j-1] < 0) {
		mergeEndElements(array, size, i, j);
	} 
}

int countOperation(int array[], int size) {
	int count = 0;
	int i = 0;
	int j = size - 1;
	while(i < j) {
		cout << i <<"  "<< j << endl;
		cout << array[i] <<"  "<< array[j] << endl << endl;
		if (array[i] == array[j]) {
			i++;
			j--;
		} else {
			performNextOperation(array, size, i, j);
			count++;			
		}
	} 
	return count;
}

int main() {
	int size;
	cout << "Enter the size of array : ";
	cin >> size;

	int array[size];
	for (int i = 0; i < size; ++i) {
	  	cin >> array[i];
	}  

	int value = countOperation(array, size);
	if (value == size -1) {
		cout << "No palindrome possible " << endl;
	} else {
		cout << "minimum merges are :"<< value << endl; 
	}
	return 0;
}
