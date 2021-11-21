//                    problem statement
//                  _____________________

// Queries on Left and Right Circular shift on array
// Given an array A of N integers. There are three types of commands: 
// 1 x : Right Circular Shift the array x times. If an array is a[0], a[1], …., a[n – 1], then after one right circular shift the array will become a[n – 1], a[0], a[1], …., a[n – 2].
// 2 y : Left Circular Shift the array y times. If an array is a[0], a[1], …., a[n – 1], then after one left circular shift the array will become a[1], …., a[n – 2], a[n – 1], a[0].
// 3 l r : Print the sum of all integers in the subarray a[l…r] (l and r inclusive).
// Given Q queries, the task is to execute each query





#include <iostream>

using namespace std;

int* createArray(int size) {
	int* array = (int*)malloc(size* sizeof(int));
	for (int i = 0; i < size; ++i) {
		cin >> array[i];
	}
	return array;
}

int* indexQueries(){
	cout << "Enter the value of l and r as per query (3 l r) ";
	int* query3 = (int*)malloc(2* sizeof(int)) ;
	cin >> query3[0];
	cin >> query3[1];
	return query3;
}

int rotateQueries() {
	int query1 ;
	cout <<"enter value of x as in (1 x) of query 1 : ";
	cin >> query1;
	
	cout <<"enter value of y as in (2 y) of query 1 : ";
	int query2 ;
	cin >> query2;

	int total_rotations = query1 - query2;
	return total_rotations;
}

void leftRotate(int size, int* array) {
	int temp = array[0];
	for (int i = size-1; i > 0; i--) {
		array[i] = array[i-1];
	}
	array[size - 1] = temp;
}

void rightRotate(int size, int* array) {
	int temp = array[size - 1];
	for (int i = size-1; i > 0; i--) {
		array[i] = array[i-1];
	}
	array[0] = temp;
}

void totalRotations(int size, int rotation, int* array) {
	if (rotation > 0) {
		for (int i = 0; i < rotation; i++)
		{
			leftRotate(size, array);
		}
	} else if(rotation < 0) {
		for (int i = 0; i > rotation; i--)
		{
			rightRotate(size, array);
		}
	}
}

int summation(int index, int* array) {
	int sum = 0;
	for (int i = 0; i <= index; i++) {
		sum += array[i];
	}
	return sum;
}

int sumMid(int start, int end , int* array){
	int sum = 0;
	for (int i = start; i < end; i++) {
		sum += array[i];
	}
	return sum;
}



int sumIndexes(int size, int* query3, int* array){
	int totalSum = 0;
	if (query3[0] < size ) {
		if (query3[1] > query3[0]) {
			int rightSum = summation(query3[1], array);
			int leftSum = summation(query3[0]-1, array);
			int totalSum = rightSum - leftSum;
		} else {
			int rightSum = summation(query3[0], array);
			int leftSum = sumMid(query3[1]+1,query3[0], array);
			totalSum = rightSum - leftSum;
		}
	} else{
		return -1;
	}
	return totalSum;
}


void printArray(int size, int* array){
	for (int i = 0; i < size; ++i) {
		cout <<array[i] <<"  ";
	}
	cout << endl;

}

int main(int argc, char const *argv[])
{
	cout << "Enter array size : ";
	int size;
	cin >> size;
	cout <<"enter array elements "<<endl; 
	int* array = createArray(size);
	cout << "Enter the query 1 and 2 " << endl;


	printArray(size, array);
	int rotation = rotateQueries();
	totalRotations(size, rotation, array);
	printArray(size, array);

	int* indexes = indexQueries();
	if (sumIndexes(size, indexes, array) == -1) {
		cout << "Error "<< endl;
		return 0;
	}
	cout <<"The sum as per the query 3 is : " <<sumIndexes(size, indexes, array);

	return 0;
}

