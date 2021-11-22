#include <iostream>
using namespace std;
void settleZeroes(int size, int array[]) {
	int last = size - 1;
	int i = 0;
	while(i < last){
		if (array[i] == 0)
		{
			if (array[last] == 0)
			{
				last --;
			} else {
				int temp = array[last];
				array[last] = 0;
				array[i] = temp;
				i++;
			}
		} else {
			i++;
		}
	}
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
	settleZeroes(size, array);
	cout << "Array after replacement " <<endl;
	printArray(size, array);

	return 0;
}