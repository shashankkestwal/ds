#include <iostream>
using namespace std;

void replaceArrayItems(int size, int array[]) {
	int prev = array[0];
	array[0] = array[0] * array[1];

	for (int i = 1; i < size-1; ++i) {
		int curr = array[i];
		array[i] = prev * array[i+1];
		prev = curr;
	}
	array[size - 1] *= prev; 
}

void printArray(int size, int array[]) {
	for (int i = 0; i < size; ++i){
		cout << array[i] <<"  ";
	}
	cout << endl;
}
int main() {
	int size;
	cout << "Enter array size : "; 
	cin >> size;

	int array[size];
	cout << "Enter array elements "<< endl;
	for (int i = 0; i < size; ++i)
	{
		cin >> array[i];
	}
	cout << "Original array " <<endl;
	printArray(size, array);
	replaceArrayItems(size, array);
	cout << "Array after replacement " <<endl;
	printArray(size, array);

	return 0;
}