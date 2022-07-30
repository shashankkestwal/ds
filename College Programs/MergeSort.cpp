#include <bits/stdc++.h>
using namespace std;

void merge(int array[], int low, int mid, int high) {
  int leftArraySize = mid - low + 1;
  int rightArraySize = high-mid;
  
  int leftSubarray[leftArraySize];
  int rightSubarray[rightArraySize];
  for (int i = 0; i < leftArraySize; ++i) {
    leftSubarray[i] = array[low + i];
  }
  for (int i = 0; i < rightArraySize; ++i)
  {
    rightSubarray[i] = array[mid + 1 + i];
  }

  int temp = low;
  int left = 0;
  int right = 0; 
  while(left < leftArraySize && right < rightArraySize) {
    if (leftSubarray[left] > rightSubarray[right]) {
      array[temp] = leftSubarray[left];
      temp++;
      left++;
    } else {
      array[temp] = rightSubarray[right];
      temp++;
      right++;
    }
  }

  while(left < leftArraySize) {
    array[temp++] = leftSubarray[left];
    left++;
  }

  while(right < rightArraySize) {
    array[temp++] = rightSubarray[right];
    right++;
  }

}

void mergeSort(int array[], int low, int high){
  int mid;
  if (low < high) {
    mid = (low + high) / 2;
    mergeSort(array,low, mid);
    mergeSort(array, mid+1, high);
    merge(array, low , mid , high);
  }
}

int main() {
  int array[5] = {5,4,3,2,1};
  mergeSort(array,0, 5);
  for (int i = 0; i < 5; ++i){
    cout << array[i] <<"  ";
  }
}
