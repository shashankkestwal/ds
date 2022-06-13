#include <iostream>
using namespace std;

class HeapSort { 
public:
	template <class T>
	void heapify(T arr[], int n, int i) {
	    int largest = i; 	// Initialize largest as root
	    int l = 2 * i + 1;  // left = 2*i + 1
	    int r = 2 * i + 2;  // right = 2*i + 2

	    if (l < n && arr[l] > arr[largest])
	        largest = l;

	    if (r < n && arr[r] > arr[largest])
	        largest = r;

	    if (largest != i) {
	        swap(arr[i], arr[largest]);

	        heapify(arr, n, largest);
	        this->printArray(arr, n);
	    }
	}

	template <class T>
	void printArray(T arr[], int n) {
	    for (int i = 0; i < n; ++i)
	        cout << arr[i] << " ";
	    cout << "\n";
	}

	template <class T>
	void heapSort(T arr[], int n) {
	    for (int i = n / 2 - 1; i >= 0; i--)
	        heapify(arr, n, i);


	    for (int i = n - 1; i > 0; i--) {
	        swap(arr[0], arr[i]);

	        heapify(arr, i, 0);
	    }
	}
};



int main() {
	int size;
	cout << "Enter array size : ";
	cin >> size;

	cout <<"Enter array elements : ";
	char array[size];

	for (int i = 0; i < size; ++i) {
		cin >> array[i];
	}
	HeapSort h;
	h.heapSort(array, size);
	h.printArray(array, size);
	return 0;
}
















