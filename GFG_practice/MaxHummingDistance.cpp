#include <iostream>
using namespace std;

int* createArray(int size) {
	int *array = (int*) malloc(size*sizeof(int));

	for (int i = 0; i < size; ++i)
	{
		cin >> array[i];
	}
	return array;
}

void rotateArray(int size, int* array) {
	int temp =  array[0];
	for (int i = 0; i < size; ++i)
	{
		array[i] = array[i+1];
	}
	array[size-1] = temp;
}

int* createCopyArray(int size, int * originalArray){
	int *duplicateArray = (int*) malloc(size*sizeof(int));
	for (int i = 0; i < size; ++i)
	{
		duplicateArray[i] = originalArray[i];
	}
	return duplicateArray;
}

int maxHummingDistance(int size, int* originalArray){
	int hummingDistance = 0;
	int* duplicateArray = createCopyArray(size, originalArray);
	for (int i = 0; i < size-1; ++i) {
		rotateArray(size, duplicateArray);
		for (int i = 0; i < size; ++i)
		{
			if (originalArray[i] == duplicateArray[i])
			{
				hummingDistance++;
			}
		}
		if (hummingDistance == size) {
			return hummingDistance;
		}
	}
	return hummingDistance;
}

int main() {
	int size;
	cin >> size;
	int* originalArray = createArray(size);
	cout <<endl << maxHummingDistance(size, originalArray);

	return 0;
}