#include <bits/stdc++.h>
using namespace std;

int maxArea(int * array, int size ) {
  int i = 0;
  int maximum =INT_MIN;
  int curr_area = 0;
  while(i < size) {

    for (int j = i+1; j < size; ++i) {
      curr_area = max(array[i], array[j]) * (j - i);
      maximum = max(maximum, curr_area);
    }
    i++;
  }
  return maximum;
}

int main() {
  int size;
  cout << "enter size: ";
  cin >> size;
  int array[size];

  cout << "Enter array elements:";
  for (int i = 0; i < size; ++i) {
    cin >> array[i];
  }

  cout << maxArea(array, size);


  return 0;
}