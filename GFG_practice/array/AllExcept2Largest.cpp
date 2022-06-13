#include <iostream>
#include <climits>	
using namespace std;

void allExceptLargestTWO(int array[], int size) {
	int first , second;
	first = second = INT_MIN;
	for (int i = 0; i < size; ++i) {
		if (first < array[i]) {
			second  = first;
			first = array[i];
		} else if(second < array[i]){
			second = array[i];
		}
	}

	for (int i = 0; i < size; ++i ){
		if (array[i] != first && array[i] != second) {
			cout << array[i] <<"  ";
		} 
	}
}	

int main(int argc, char const *argv[]) {
	int size;
	cout << "Array size :";
	cin >> size;
	int array[size];
	for (int i = 0; i < size; ++i) {
		cin >> array[i];
	}
	allExceptLargestTWO(array, size);

	return 0;
}