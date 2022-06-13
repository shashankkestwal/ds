// link ->  https://www.geeksforgeeks.org/minimum-number-of-jumps-to-reach-end-of-a-given-array/

#include <iostream>
using namespace std;

int minJump(int array[], int size) {
	if (size == 1) {
		return 1;
	}
	int minJumps = 0;
	int curr = 0; 
	while(curr < size - 1) {
		int max_proceed = 0;
		int temp = 0;
		int index = 0;
		for (int i = 1; i <= array[curr] ; ++i) {
			temp = i + array[curr + i];
			if (temp > max_proceed) {
				max_proceed = temp;
				index = i;
			}
		}
		if (max_proceed == 0){
			return -1;
		}
		curr += index;
		minJumps++;
	}
	return minJumps;
}

int main() {
	int size;
	cout << "Enter arrray size : ";
	cin >> size;
	int array[size];
	cin.clear();
	for (int i = 0; i < size; ++i) {
		cout << "Array element :" << i <<": ";
		cin >> array[i];
	}
	cout << minJump(array, size);

	// int minJumps = 0;
	// int curr = 0;
	// while(curr < size) {
		
	// 	int max_proceed = 0;
	// 	int temp = 0;
	// 	int index = 0;
	// 	for (int i = 1; i <= array[curr] ; ++i) {
	// 		temp = i + array[curr + i];
	// 		if (temp > max_proceed) {
	// 			max_proceed = temp;
	// 			index = i;
	// 		}
	// 	}
	// 	curr += index;
	// 	minJumps++;
	// }
	// cout << minJumps;
	return 0;


}





// // C++ program to find Minimum
// // number of jumps to reach end
// #include <bits/stdc++.h>
// using namespace std;

// // Function to
// return the minimum number
// // of jumps to reach arr[h] from arr[l]
// int minJumps(int arr[], int n)
// {

// 	// Base case: when source and
// 	// destination are same
// 	if (n == 1)
// 		return 0;

// 	// Traverse through all the points
// 	// reachable from arr[l]
// 	// Recursively, get the minimum number
// 	// of jumps needed to reach arr[h] from
// 	// these reachable points
// 	int res = INT_MAX;
// 	for (int i = n - 2; i >= 0; i--) {
// 		if (i + arr[i] >= n - 1) {
// 			int sub_res = minJumps(arr, i + 1);
// 			if (sub_res != INT_MAX)
// 				res = min(res, sub_res + 1);
// 		}
// 	}

// 	return res;
// }

// // Driver Code
// int main()
// {
// 	int arr[] = { 1, 3, 6, 3, 2,
// 				3, 6, 8, 9, 5 };
// 	int n = sizeof(arr) / sizeof(arr[0]);
// 	cout << "Minimum number of jumps to";
// 	cout << " reach the end is " << minJumps(arr, n);
// 	return 0;
// }

// // This code is contributed
// // by Shivi_Aggarwal
