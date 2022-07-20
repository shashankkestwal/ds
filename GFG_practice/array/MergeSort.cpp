// C++ program for Merge Sort
#include <iostream>
using namespace std;

// void merge(int array[], int const left, int const mid, int const right)
// {
// 	int subArrayOne = mid - left + 1;
// 	int subArrayTwo = right - mid;

// 	// Create temp arrays
// 	int leftArray[subArrayOne];
// 	int rightArray[subArrayTwo];

// 	// Copy data to temp arrays leftArray[] and rightArray[]
// 	for (int i = 0; i < subArrayOne; i++)
// 		leftArray[i] = array[left + i];
// 	for (int j = 0; j < subArrayTwo; j++)
// 		rightArray[j] = array[mid + 1 + j];

// 	auto indexOfSubArrayOne = 0, // Initial index of first sub-array
// 		indexOfSubArrayTwo = 0; // Initial index of second sub-array
// 	int indexOfMergedArray = left; // Initial index of merged array


// 	while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
// 		if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
// 			array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
// 			indexOfSubArrayOne++;
// 		}
// 		else {
// 			array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
// 			indexOfSubArrayTwo++;
// 		}
// 		indexOfMergedArray++;
// 	}

// 	while (indexOfSubArrayOne < subArrayOne) {
// 		array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
// 		indexOfSubArrayOne++;
// 		indexOfMergedArray++;
// 	}
	

// 	while (indexOfSubArrayTwo < subArrayTwo) {
// 		array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
// 		indexOfSubArrayTwo++;
// 		indexOfMergedArray++;
// 	}
// }

// void mergeSort(int array[], int begin, int end)
// {
// 	if (begin >= end)
// 		return; // Returns recursively

// 	int mid = begin + (end - begin) / 2;
// 	mergeSort(array, begin, mid);
// 	mergeSort(array, mid + 1, end);
// 	merge(array, begin, mid, end);
// }


void merge(int * arr, int start, int mid, int end) {
	int size1 = mid - start + 1;
	int size2 = end - mid;
	int *leftSubArr = new int(size1);
	int *rightSubarray = new int(size2);
	for(int i = 0; i < size1; i++) leftSubArr[i] = arr[i+start];
	for(int i = 0; i < size2; i++) rightSubarray[i] = arr[mid+i];

	int left = 0, right = 0, total = start;
	while(left < size1 && right < size2) {
		if(leftSubArr[left] < rightSubarray[right]) {
			arr[total++] = leftSubArr[left++];
		} else {
			arr[total++] = rightSubarray[right++];
		}
	}
	while(left < size1) {
		arr[total++] = leftSubArr[left++];
	}
	while(right < size2) {
		arr[total++] = rightSubarray[right++];
	}
}


void mergeSort(int*arr, int start, int end ) {
	// base case i.e if size of array is <= 0
	if(start >= end) return;
	int mid = (start + end) / 2;
	// breaking the array recursively 
	// sort first part 
	mergeSort(arr, start, mid-1);
	// sort second part
	mergeSort(arr, mid+1, end);

	// merging both the subarrays into single array
	merge(arr, start, mid, end);
}

void printArray(int A[], int size)
{
	for (int i = 0; i < size; i++)
		cout << A[i] << " ";
}

// merge sort time complexity O(n*logn)
// space complexity O(n)

int main() {
	int arr[] = {5,2,3,1};
	int arr_size = sizeof(arr) / sizeof(arr[0]);
	// sort the given array 
	mergeSort(arr, 0, arr_size-1);

	cout << "\nSorted array is \n";
	printArray(arr, arr_size);
	return 0;
}


