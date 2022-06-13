#include <iostream>
using namespace std;

void printRotatedArray(int index, int size, int array[]){
	index = index % size;

	int count = 0;
	while(count < size) {
		cout << array[index] <<"  ";
		index = (index+1) % size;
		count++;
	}
}

int main(int argc, char const *argv[])
{
	int size;
	cout << "Enter array size : "; 
	cin >> size;
	int array [size];
	cout << "Enter array elements "<<endl; 
	for (int i = 0; i < size; ++i)
	{
		cin >> array[i];
	}
	int k;
	cout << "Enter how much to rotate :";
	cin >> k;
	printRotatedArray(k, size, array);
	return 0;
}