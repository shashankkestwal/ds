#include <bits/stdc++.h>
using namespace std;

int bubbleSort(int * array, int size) {
  int comparisonCount = 0;
  for (int i = size-1; i >= 0; i--) {

    for(int j = 0; j < i; j++){

      //incrementing comparison count 
      comparisonCount++;
      if (array[j] > array[j+1]) {
        swap(array[j], array[j+1]);

      }
    }
  }
  return comparisonCount;
}

int main() {
  int size;
  cout << "array size :";
  cin >> size;
  int array[size];
  cout << "array elements \n";
  for (int i = 0; i < size; ++i) {
    cin >> array[i];
  }
  cout << "comparisons in bubbleSort :" << bubbleSort(array, size) << endl;
  for (int i = 0; i < size; ++i) {
    cout << array[i] << "  ";
  }

  return 0;
}