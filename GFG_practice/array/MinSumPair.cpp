// link -> https://www.geeksforgeeks.org/find-k-pairs-smallest-sums-two-arrays/

#include <bits/stdc++.h>
using namespace std;

void minSumPairs(int array1[], int size1, int array2[], int size2, int pair) {
	if (pair > size2 * size1) {
		return;
	}

	int index[size1];
	memset(index,0,sizeof(index));

	while( pair > 0){
		int min_index, min_sum;
		min_sum = INT_MAX;

		for (int i = 0; i < size1; ++i)
		{
			if (array1[i] + array2[index[i]] < min_sum && index[i] < size2) {
				min_sum = array1[i] + array2[index[i]];
				min_index = i;
			}	
		}
		cout <<"( "<<array1[min_index]<<", "<< array2[index[min_index]] << ")"<< endl;
		index[min_index]++;
		pair--;
	}
}

int main() {
	int size1, size2, pair;
	cout <<"number of pairs wanted :";
	cin >> pair;
	cout << "size of array1 :";
	cin >> size1;
	cout << "size of array2 :";
	cin >> size2;

	int array1[size1], array2[size2];

	for (int i = 0; i < size1; ++i)
	{
		cin >> array1[i];
	}

	for (int i = 0; i < size2; ++i)
	{
		cin >> array2[i];
	}

	minSumPairs(array1, size1, array2, size2, pair);



	return 0;
}