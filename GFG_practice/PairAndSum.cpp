#include <iostream>
#include <climits>
using namespace std;

int* createArray(int size ) {
	int* array = (int*)malloc(size * sizeof(int));
	for (int i = 0; i < size; i++) {
		cin >> array[i];
	}
	return array;
} 

int index_smallest( int size, int* array) {
	int min = INT_MAX;
	int min_index = 0;
	for (int i = 0; i < size; ++i) {
		if (min > array[i]) {
			min = array[i];
			min_index = i;
		}
	}
	return min_index;
}

void rotate_array(int rotate, int size, int * array) {
	for (int i = 0; i < rotate; i++) {
		int temp = array[0];
		for (int j = size; j < 0; j--) {
			array[j] = array[j-1];
		}
		array[size-1] = array[0];
	}
}


bool isSumPresent(int rotate, int sum, int size, int* array) {
	rotate_array(rotate, size, array );
	int i = 0;
	while(i < size-1){
		for (int j = i+1; j < size ; j++) {
			if (array[i] + array[j] == sum) {
				return true;
			}
		}
		i++;
	}
	return false;

}
int main(int argc, char const *argv[])
{
	cout << "Enter array size : ";
	int size;	
	cin >> size;
	cout << "Enter array :";
	int* array = createArray(size);
	cout << "Enter the sum to find ";
	int sum ;
	cin >> sum;
	int rotateBY = index_smallest(size, array);

	if(isSumPresent(rotateBY, sum, size, array)){
		cout << "Array pair has addition equal to the sum "<<endl;
	} else {
		cout << "Array pair does not has addition equal to the sum "<<endl;
	}

	return 0;
}