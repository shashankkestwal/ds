#include <bits/stdc++.h>
using namespace std;

int binarySearch(int l, int h, int array[],int key ) {
	if (l <= h) {
		int mid = (l + h) / 2;
		if (array[mid] == key) {
			return mid;
		}
		else {
			if (array[mid] > key) {
			 	return binarySearch(l, mid-1 , array, key);
			} 
			return binarySearch(mid+1, h , array, key);
		}
	} 
	return -1;
}

int main() {
	int size;
	cout << "Enter array size : ";
	cin >>size;

	int array[size];
	for (int i = 0; i < size; ++i) {
		cin >> array[i];
	}
	
	sort(array. array + size);

	int key;
	cout << "Enter the value you want to search :";
	cin >> key;

	cout << "Element found at index : " <<  binarySearch(0, size, array, key);
	return 0;
}