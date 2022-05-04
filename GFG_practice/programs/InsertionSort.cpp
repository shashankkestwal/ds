#include <bits/stdc++.h>
using namespace std;

int insertionSort(int array[], int size) {

  int comparisonCount = 0, temp, j ;
  for (int i = 1; i < size; ++i) {
    j = i - 1;
    temp = array[i];
    while(j >= 0) {
      comparisonCount++;
      if (array[j] > temp) {
        array[j+1] =  array[j];
      }
      j--;
    }
    array[j+1] =  temp;   
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
  cout << "comparisons in bubbleSort :" << insertionSort(array, size) << endl;
  for (int i = 0; i < size; ++i) {
    cout << array[i] << "  ";
  }
  return 0;

}