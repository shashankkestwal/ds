#include <bits/stdc++.h>
using namespace std;

void firstNegative(int arr[], int k, int size) {
  queue<int> q;
  int i = 0;
  int j = 0;
  while(j < size) {
    if(j - i + 1 < k) {
      if(arr[j] < 0) {
        q.push(arr[j]);
      }
      j++;
    } else {
      if(arr[j] < 0) {
        q.push(arr[j]);
      }
      if(!q.empty()) {
        cout << "ans = " << q.front();
      } else {``
        cout << "ans = 0 " ;
      }
      cout << "Window from " << i <<" to " << j << endl;
      
      if(arr[i] < 0) q.pop();
      j++;

      i++;
    }
  }
}

int main(){
  int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
  int size = 8;
  int windowSize = 3;
  firstNegative(arr, windowSize, size);

  return 0;
}