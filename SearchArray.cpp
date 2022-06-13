#include <iostream>
using namespace std;
bool isSorted(int* array, int size) {
	for (int i = 0; i < size; ++i) {
		for (int j = i; j < size ; j++) {
			if (array[i] > array[j]) {
				return false;
			}
		}
	}
	return true;
}

int linearSearch(int size, int search_element, int* array) {
	for (int i = 0; i < size ; ++i) {
		if (array[i] == search_element) {
			return i;
		}
	}
	return -1;
}

int binarySearch(int size , int search_element, int* array) {
	if (!isSorted(array, size)) {
		return -2;
	} else {
		int start, mid , end;
		start = 0;
		end = size;
		while (end > start){
			mid = (end+start) /2;
			if (array[mid] == search_element) {
				return mid;
			} else if (array[mid] > search_element) {
				end = mid - 1;
			} else {
				start = mid + 1;
			}
		}
	}
	return -1;
}

int main(){
	int size;
	cout << "Enter the size of array : ";
	cin >> size;
	cout << "Enter array elements : ";
	int array[size];
	for (int i = 0; i < size; i++) {
		cin >> array[i];
	}
	cout << "Item to be searched : ";
	int search_element;
	cin >> search_element;
	char choice;
	cout << "press b for binary search l for linear search ";
	cin >> choice;
	switch (choice){
		case 'b':
			if (binarySearch(size, search_element, array) == -2) {
				cout << "cannot perform binary search on undorted array "<<endl;
				break;
			} else if (binarySearch(size, search_element, array) == -1)
			{
				cout << "Element not found"<< endl;
				break;
			} else {
				cout << "Element found at index "<< binarySearch(size, search_element, array) <<" index";
			}
			break;
		case 'l':
			if (linearSearch(size, search_element, array) == -1)
			{
				cout << "Element not found"<< endl;
				break;
			} else {
				cout << "Element found at index "<< linearSearch(size, search_element, array) <<" index";
			}
			break;
	}
	return 0;
}