#include <iostream>
using namespace std;

void shuffleArray (int size, int array[]) {
	for (int i = 0; i < size ; ++i) {
		int index = rand() % size;
		int temp = array[index];
		array[index] = array[i];
		array[i] = temp; 
	}
	cout << endl;
}
void printArray(int size, int array[]) {
	for (int i = 0; i < size; ++i) {
		cout << array[i] <<"  ";
	}
	cout << endl;
}

int main(){
	int size;
	cout << "Enter array size : "; 
	cin >> size;
	int array[size];
	cout << "Enter array elements "<< endl;
	for (int i = 0; i < size; ++i)
	{
		cin >> array[i];
	}
	cout << "Original array "<<endl;
	printArray(size, array);
	shuffleArray(size, array);
	cout << "Shuffled array "<<endl;
	printArray(size, array);


	return 0;
}