// Positive elements at even and negative at odd positions (Relative 
// order not maintained)

#include <iostream>
using namespace std;

void arrangeEvenOdd(int arr[], int n);
int main() {
	int n;
	cout << "size of array : ";
	cin >> n;

	int arr[n];
	
	for(int i = 0 ; i < n;i++) {
		cin >> arr[i]; 
	}
	arrangeEvenOdd(arr, n);
	for(int i = 0 ; i < n;i++) {
		cout << arr[i] <<" "; 
	}
	return 0;
}

void arrangeEvenOdd(int arr[],  int n) {
	for (int i = 0; i < n; i++) {
		if (i%2 == 0 && arr[i] < 0) {
			int j = i+1;
			while(j < n){
				if (arr[j] > 0) {
					int temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
					break;
				}
				j+=2;
			}
		} else if(i%2 == 1 && arr[i] > 0) {
			int j = i+1;
			while(j < n){
				if (arr[j] < 0) {
					int temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
					break;
				}
				j+=2;
			}
		}
	}
}