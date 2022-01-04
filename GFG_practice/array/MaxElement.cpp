#include <iostream>
#include <climits >
using namespace std;

int main(){
	int size;
	cout << "array size : ";
	cin >> size ;
	int array[size];
	for (int i = 0 ; i < size; i++) {
		cin >> array[i];
	}
	int max = INT_MIN;
	for (int i = 0; i < size; ++i)
	{
		if(array[i] > max) {
			max = array[i];
		}
	}
	cout << "max element is :" << max << endl;
 	return 0;
}