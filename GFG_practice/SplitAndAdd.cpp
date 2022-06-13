#include <iostream>
using namespace std;

void rotateLeft(int size, int array[]){
	int temp = array[0];
	for (int i = 0; i < size; ++i) {
		array[i] = array[i+1];
	}
	array[size-1] = temp;
}
void splitAndAdd(int rotate, int size, int array[]) {
	for (int i = 0; i < rotate; ++i) {
		rotateLeft(size, array);
	}
}

void printArray(int size, int array[]) {
	for (int i = 0; i < size; ++i) {
		cout << array[i]<<"  ";
	}
	cout << endl;
}

int main(int argc, char const *argv[])
{
	int size;
	cin >> size;
	int array[size];
	for (int i = 0; i < size; ++i) {
		cin >> array[i];
	}
	printArray(size, array);
	int k;
	cin >> k;
	splitAndAdd(k, size, array);
	printArray(size, array);
	return 0;
}