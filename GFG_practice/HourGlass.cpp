// link -> https://www.hackerrank.com/challenges/2d-array/problem

#include <bits/stdc++.h>
using namespace std;




int main() {
	int row , coloumn;
	cin >> row;
	cin >> coloumn;

	int array[row][coloumn];

	cout << "Enter array elements : ";
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < coloumn; ++j)
		{
			cin >> array[i][j];
		}
	}

	int max_sum = INT_MIN;
	
	for (int i = 0; i < row - 2 ; ++i)
	{

		for (int j = 0; j < coloumn - 2; ++j)
		{
			int current_sum = INT_MIN;
			if (array[i][j] != 0 && array[i+1][j] != 0 && array[i+2][j] != 0 && array[i+1][j+1] != 0 && array[i][j+2] != 0 && array[i+1][j+2] != 0 && array[i+2][j+2] != 0){
				current_sum = array[i][j] + array[i+1][j] + array[i+2][j] + array[i+1][j+1] + array[i][j+2] + array[i+1][j+2] + array[i+2][j+2];
			}
			if (current_sum > max_sum) {
				max_sum = current_sum;
			}
		}
	}
	cout << max_sum;

	return 0;
}