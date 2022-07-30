#include <bits/stdc++.h>
using namespace std;

// iterative solution 
// void bubbleSort(vector<int>& v, int end) {
//   for(int i = 0; i < end ; i++) {
//     for(int j = 0; j < end - i;  j++) {
//       if(v[j] > v[j+1]) {
//         swap(v[j], v[j+1]);
//       }
//     }
//   }
// }

// recursive solution

void bubbleSort(vector<int>& v, int end) {
  if (end == 0)
    return;
  for(int i = 0 ;  i < end; i++) {
    if(v[i] > v[i+1]) {
      swap(v[i], v[i+1]);
    }
  }
  bubbleSort(v, end -1);
}

int main() {
  vector<int> v = {5,4,3,2,1};
  bubbleSort(v, v.size()-1);
  for(auto i : v) {
    cout << i << endl;
  }
}