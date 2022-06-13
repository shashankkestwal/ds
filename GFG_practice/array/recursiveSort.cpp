#include <bits/stdc++.h>
using namespace std;

// int power(int a, int b) {
//   if(a == 0) return a;
//   if(b == 0) return 1;
//   if(b % 2 == 1) return a * (power(a,b/2) * power(a,b/2));
//   else return (power(a,b/2) * power(a,b/2));
// }

void bubbleSort(int* arr, int size) {
  if(size == 0 || size == 1) return;

  for(int i = 0; i < size ; i++) {
    if(arr[i] > arr[i+1]) swap(arr[i], arr[i+1]);
  }
  bubbleSort(arr, size-1);
}


void insertionSort(int* arr, int size, int index = 0) {
  if(index == size-1) {
      return;
  }
  int minIndex = index; 
  for(int i = 0; i <= index; i++ ) {
    if(arr[i] < arr[minIndex]) {
      minIndex = i;
    }
    swap(arr[i], arr[minIndex]);
  }

  return insertionSort(arr, size, index+1);
}

void selectionSort(int *arr, int size , int index = 0) {
  if(index == size-1) {
      return;
  }
  int maxIndex = index; 
  for(int i = index; i < size; i++ ) {
    if(arr[i] > arr[maxIndex]) {
      maxIndex = i;
    }
    swap(arr[i], arr[maxIndex]);
  }

  return selectionSort(arr, size, index+1);
}

int main() {
  int arr[5] = {5,3,2,1,10};
  /* recursive bubble sort 
  selection sort and insertion sort (13 june 2022)
                          :-credit to love babbar
  */  
  return 0;
}