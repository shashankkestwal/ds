#include <bits/stdc++.h>
using namespace std;

int main() {
	int size ;
	cout << "array size : ";
	cin >> size ;

	int * array = (int*) malloc(size * sizeof(int));

	for (int i = 0; i < size; ++i) {
		cin >> array[i];
	}

	int front = 0,rear = size - 1;

	while(front < rear) {
		int temp = array[front];
		array[front] = array[rear];
		array[rear] = temp;
		front++;
		rear--;
	}

	for (int i = 0; i < size; ++i) {
		cout << array[i] << " ";
	}

	return 0;
}