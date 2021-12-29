#include <iostream>
using namespace std;

void segregateArray(int size, int array[]) {

	int evenIndex = 0;
	for (int j = 0; j < size; j++) {
		if (array[j] % 2 == 0) {
			int temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			evenIndex++;
		}
	}
}



void printArray(int size, int array[]) {
	for (int i = 0; i <  size; ++i){
		cout << array[i] <<"  ";
	}
	cout << endl;
}

int main(){
	int size;
	cin >> size;
	int array[size];
	for (int i = 0; i < size; i++) {
		cin >> array[i];
	}
	printArray(size, array);
	segregateArray(size, array);
	printArray(size, array);
	return 0;
}