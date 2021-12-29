// Reorder an array according to given indexes
// link -> https://www.geeksforgeeks.org/reorder-a-array-according-to-given-indexes/


#include <bits/stdc++.h>

using namespace std;

void reorderArray(int arr1[], int arr2[], int size) {
	for (int i = 0; i < size; ++i)
	{
		if (arr2[i] != i) {
			swap(arr1[i], arr1[arr2[i]]);
			swap(arr2[i], arr2[arr2[i]]);
 		}
	}

	for (int i = 0; i < size; ++i)
	{
		arr2[i] = i;
	}
}

int main() {
	int size;
	cout << "size" << endl;
	cin >> size;
	int n = size;
	int arr1[n];
	int arr2[n];
	for (int i = 0; i < n ; ++i)
	{
		cin >> arr1[i];
	}
	cout << endl;
	for (int i = 0; i < n ; ++i)
	{
		cin >> arr2[i];
	}
	reorderArray(arr1, arr2, size);

	for (int i = 0; i < size; ++i) {
		cout << arr1[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < size; ++i){
		cout << arr2[i] << " ";
	}
	return 0;
}