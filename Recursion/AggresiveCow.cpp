#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 +10;
int n, cows;
int position[N];

bool canPlaceCow(int minDist){
  int lastPos = -1;
  int n_cows = cows;

  for(int i = 0; i < n; i++) {
    if(position[i] - lastPos >= minDist || lastPos == -1) {
      n_cows--;
      lastPos = position[i];
    }    
  }
  return n_cows <= 0;
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    cin >> n >> cows; 
    for(int i = 0; i < n; ++i) {
      cin >> position[i];
    }

    sort(position, position+n);

    int low = 0, high = 1e9, mid;
    while(high - low > 1) {
      mid = (low+high)/2;
      if(canPlaceCow(mid)) {
        low = mid;
      } else {
        high = mid -1;
      }
    }
    if(canPlaceCow(high)) {
      cout << high;
    } else{
      cout << low;
    }
  }
}