#include<bits/stdc++.h>
using namespace std;


void heapify(int array[], int size, int i)
{
    int largest = i; // Initialize largest as root
    int lchild = 2 * i + 1; // left = 2*i + 1
    int rchild = 2 * i + 2; // right = 2*i + 2
 
    if (lchild < size && array[lchild] > array[largest])
        largest = lchild;
 
    if (rchild < size && array[rchild] > array[largest])
        largest = rchild;
 
    if (largest != i) {
        swap(array[i], array[largest]);
        heapify(array, size, largest);
    }
}


void heapSort(int array[], int size) {
   for (int i = size / 2 - 1; i >= 0; i--)
        heapify(array, size, i);
 
    for (int i = size - 1; i > 0; i--) {

        swap(array[0], array[i]);
 
        heapify(array, i, 0);
    }
}

int main(){
  int size;
  cout  << "Enter the size of the array :";
  cin >> size ;
  int array[size];
  cout << "Array elements : ";
  for (int i = 0; i < size; ++i) {
    cin >> array[i];
  }

  heapSort(array, size);

  for (int i = 0; i < size; ++i) {
    cout << array[i] << "  ";
  }
}