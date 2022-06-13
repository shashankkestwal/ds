// link -> https://www.geeksforgeeks.org/rearrange-array-maximum-minimum-form/


#include <bits/stdc++.h>
using namespace std;

void printArray(int* arr, int size){
	for (int i = 0; i < size; ++i) {
		cout << arr[i] << "  ";
	}
	cout << endl;
}

int* arrangeMinMax(int arr[], int size) {
	int* arrangedArray = (int*) malloc(size*sizeof(int));
	int front = 0;
	int rear = size - 1;
	int i = 0;
	while(front <= rear and i < size ) {
		arrangedArray[i] = arr[rear];
		arrangedArray[i + 1] = arr[front];
		front ++;
		rear --;
		i += 2;
	}
	return arrangedArray;
}
int main(){
	int size; 
	cout << "size of array : " << endl;
	cin >> size;
	int arr[size];
	for (int i = 0; i < size; ++i) {
		cin >> arr[i];
	}
	sort(arr, arr+size);
	printArray(arr, size);
	int* arranged_array = arrangeMinMax(arr, size);
	printArray(arranged_array, size);
	return 0;
}
