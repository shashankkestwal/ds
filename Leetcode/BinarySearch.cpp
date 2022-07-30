#include <iostream>
using namespace std;

int binary_search_iterative (int start_index, int endindex , int * list, int search_item ) {
	while (start_index < endindex) {
		int mid = (start_index + endindex) / 2;
		if (list[mid] == search_item) {
			return mid;
		} else if (list[mid] < search_item) {
			start_index = mid + 1;
		} else if (list[mid] > search_item) {
			endindex = mid - 1;	
		}
	}
	return -1;
}
int main() {
	int arr[] = {1,2,3,4,5,6};
	int N = sizeof(arr)/sizeof(arr[0]);
	cout << binary_search_iterative(0, N, arr, 6);
	return 0;
}


