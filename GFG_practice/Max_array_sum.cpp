#include <iostream>
#include <climits>
using namespace std;

int* createArray(int size) {
	int* array = (int*)malloc(size * sizeof(int));
	int i = 0;
	while(i < size) {
		cin >> array[i];
		i++;
	}
	return array;
}
void rotate_array(int size, int *array ){

	int min = INT_MAX;
	int min_index = 0;
	for (int i = 0; i < size; i++) {
		if (min > array[i])
		{
			min = array[i];
			min_index = i;
		}
	}

	for (int i = 0; i < min_index; i++) {
		int temp = array[0];
		for (int j = 1; j < size; j++) {
			array[j-1] = array[j];
		}
		array[size - 1] = temp;
	}
}

void max_sum(int size, int *array) {
	int max = 0; 
	rotate_array(size, array);
	
	int multiple = 0;
	for (int i = 0; i < size; i++)
	{
		multiple += array[i] * i;
	}
	if (multiple > max) {
		max = multiple;
	}
	
	cout <<"max sum of the array index multiplication is : "<< max << endl;
}
void printArray(int size, int* array) {
	for (int i = 0; i < size; ++i) {
		cout << array[i] << "  ";
	}
	cout << endl;
}
int main() {
	int size;
	cout << "Enter array size : ";
	cin >> size;
	cout << "Enter array elements "<< endl;
	
	int* array  = createArray(size);
	printArray(size, array);
	max_sum(size, array);
	printArray(size, array);

	return 0;
}
