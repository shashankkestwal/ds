 					//problem statement 
					// ____________________

// Given an array of n elements.
// Our task is to write a program to rearrange the array 
// such that elements at even positions are greater than all
// elements before it and elements at odd positions are less 
// than all elements before it.


#include <iostream>
using namespace std;


void printArray(int size, int array[]) {
	for (int i = 0; i < size; ++i) {
		cout << array[i] <<"  ";
	}
	cout << endl;
}


void sortArray(int size, int array[]) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size-i-1; j++) {
			if (array[j] > array[j+1]) {
				int temp = array[j+1];
				array[j+1] = array[j];
				array[j] = temp;
			}
		}
	}
}


void rearrangedArray(int size, int array[]){
	sortArray(size, array);
	int index = 1;
	for (int i = (size + 1) / 2; i < size && index < size; i++) {
		int temp = array[index];
		array[index] = array[i];
		array[i] = temp;
		index += 2;
	}
}



int main(){
	int size;
	cout << "Enter array size : ";
	cin >> size;

	int array[size];
	cout << "Enter array elements" << endl; 
	for (int i = 0; i < size; ++i) {
		cin >> array[i];
	}
	rearrangedArray(size, array);
	cout << "Array arranged as per the queston "<<endl;
	printArray(size, array);
	return 0;
}


