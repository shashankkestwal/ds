#include <iostream>
using namespace std;

void rearrangedArray(int size, int array[]) {
	int i = 0;
	for (int j = 0; j < size; j++) {
		if (array[j] < 0) {
			int temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
		}
	}

	int positiveIndex = i;
	for (int k = 0; k < size && positiveIndex < size; k++)
	{
		if (k % 2 == 0 && array[k] < 0) {
			int temp = array[k];
			array[k] = array[positiveIndex];
			array[positiveIndex] = temp;
			positiveIndex++;	
		}
	}
}

void printArray(int size, int array[]){
	for (int i = 0; i < size; ++i)
	{
		cout << array[i] << "  ";
	}
	cout << endl;
}


int main(){
	int size;
	cout << "Enter array size : "; 
	cin >> size;
	cout << "Enter array elements "<< endl; 
	int array[size];
	for (int i = 0; i < size; ++i)
	{
		cin >> array[i];
	}
	cout << "original array "<< endl;
	printArray(size, array);
	rearrangedArray(size, array);
	cout << "rearranged  array "<< endl;
	printArray(size, array);
	return 0;
}

