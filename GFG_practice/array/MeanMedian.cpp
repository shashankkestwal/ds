// Program for Mean and median of an unsorted array

#include <bits/stdc++.h>
using namespace std;

int mean(int array[], int size) {
	int sum = 0;
	for (int i = 0; i < size; ++i) {
		sum += array[i];
	}
	return sum/size;
}

int median(int array[], int size){
	int median;
	if (size % 2 == 0) {
		median = (array[(size/2) -1] + array[size/2]) / 2;
	} else {
		median = array[(size-1)/2];
	}
	return median;
}

int main(int argc, char const *argv[])
{
	int size ;
	cout << "Array size :";
	cin >> size;
	int array[size];
	for (int i = 0; i < size; ++i)
	{
		cin >> array[i];
	}
	int meanVAL = mean(array, size);
	int medianVAL = mean(array, size);
	cout << "mean :" << meanVAL << endl <<"median :" << medianVAL;
 	return 0;
}