#include <iostream>
using namespace std;


void rearrangedArray(int size, int array[]) {
	int oddIndex = 1;
	int negativeCount = 0;
	int i = 0;
	while(i < size) {
		if (array[i] > 0) {
			if (array[oddIndex] < 0)
			{
				int temp = array[i];
				array[i] = array[oddIndex];
				array[oddIndex] = temp;
				oddIndex += 2;
				negativeCount ++;
				i += 2;
			} else {
				oddIndex += 2; 
				break;
			}
		}
		else {
			i += 2;
		}
	}
	int evenIndex = 0;
	i = 1;
	while(i < size) {
		if (array[i] < 0) {
			if (array[evenIndex] > 0)
			{
				int temp = array[i];
				array[i] = array[evenIndex];
				array[evenIndex] = temp;
				evenIndex += 2;
				i += 2;
			} else {
				evenIndex += 2; 
				break;
			}
		}
		else {
			i += 2;
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
