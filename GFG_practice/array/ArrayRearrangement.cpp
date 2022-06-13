#include <iostream>
using namespace std;

void fixArray(int size, int* array) {
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++) {
			if (array[j] == i) {
				int temp = array[i];
				array[i] = i;
				array[j] = temp;
			}
		}
	}
	for (int i = 0; i < size; ++i)
	{
		if (array[i] != i) {
			array[i] = -1;
		}
	}
}

void printArray(int size, int array[]) {
	cout << endl;
	for (int i = 0; i < size; i++) {
		cout << array[i]<<"  ";
	}
	cout << endl;
}


int main(int argc, char const *argv[]) {
	int size;
	cin >> size;
	int array[size];
	for (int i = 0; i < size; i++) {
		cin >> array[i];
	}
	printArray(size, array);
	fixArray(size, array);
	printArray(size, array);

	return 0;
}