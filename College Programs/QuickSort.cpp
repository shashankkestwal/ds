#include <bits/stdc++.h>
using namespace std;

// int partition(int array[],int low, int high) {
//   int temp = array[high];
//   int i = low - 1;
//   for (int j = low; j < high; ++j)
//   {
//     if (array[j] < temp) {
//       i++;
//       swap(array[j], array[i]);
//     }
//   }
//   swap(array[i+1], array[high]);
//   return i + 1;
// }

int partition(int array[], int low, int high) {
  int pivot = array[low];
  int j = high;
  int i = low;
  do {
    do{
      j--;
    }while(array[j] > pivot);
    do{
      i++;
    }while(array[i] <= pivot);
    if (j > i) {
      swap(array[i], array[j]);
    }   
  } while(j > i);
  swap(array[j], array[low]);
  return j;
}

void quickSort(int array[], int low, int high) {
  if (low < high)
  {
    int temp = partition(array, low, high);
    quickSort(array, low, temp-1);
    quickSort(array, temp+1, high);
  }
}
int main() {
  int array[5] = {5,4,3,2,1};
  quickSort(array,0, 5);
  for (int i = 0; i < 5; ++i){
    cout << array[i] <<"  ";
  }
}

