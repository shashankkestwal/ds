#include <iostream>
using namespace std;

int selectionSort(int * array, int size) {
  int comparisonCount = 0;
  for (int i = 0; i < size; ++i) {
    int k = i;
    for (int j = i; j < size; ++j) {
      comparisonCount++;
      if (array[j] < array[k]) {
        k = j;
      }
    }
    swap(array[k], array[i]);
  }
  return comparisonCount;
}

int main() {
  int size;
  cout << "Enter size of array  : ";
  cin >> size;

  int array[size];
  cout << "Enter array elements" << endl;
  for (int i = 0; i < size; ++i) {
    cin >> array[i];
  }

  selectionSort(array, size);

  for (int i = 0; i < size; ++i) {
    cout << array[i] << "  ";
  }
}