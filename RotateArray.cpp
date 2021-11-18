#include <iostream>
using namespace std;

void rotate_right(int size, int rotate, int* array) {
	int is = 0;
	while( is < rotate){
		int temp;
		temp = array[size - 1];
		for (int i = size-1; i >= 0; i--) {
			array[i] = array[i-1];
		}
		array[0] = temp;
		is++;
	}

	
}

void rotate_left(int size, int rotate, int * array) {
	int rotated_count = 0;
	while(rotated_count < rotate){
		int temp = array[0]; 
		for (int i = 0; i < size; i++)
		{
			array[i] = array[i+1];
		}
		array[size-1] = temp;
		rotated_count++;
	}

	
}

void print_array(int size, int* array) {
	for (int i = 0; i < size; i++) {
		cout << array [i] <<"    ";
	}
}
int main(int argc, char const *argv[])
{

	cout << "rotate an array \n";
	cout << "array size ";
	int n;
	cin >> n;
	int array[n];
	cout << "array elements ";
	for (int i = 0; i < n; i++) {
		cin >> array[i];
	}
	cout << "No of times to rotate array : ";
	int rotate ;
	cin >> rotate;
	char choice;
	cout << "l for left r for rigth rotation .";
	cin >> choice;
	switch (choice){
		case 'l':
			rotate_right(n,rotate,array);
			break;
		case 'r':
			rotate_left(n,rotate,array);
			break;
		default :
			cout << "invalid input ";
			break;
	
	} 
	print_array(n, array);

	return 0;
}