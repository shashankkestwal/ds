// calculating square root using binary search

#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int base;
  cin >> base;
  double low = 1, high = n;
  double mid;

  while( high - low > 0.01) {
    mid = (low+high) / 2;
    if(pow(mid,base) < n) {
      low = mid;
    } else {
      high = mid;
    }
  }
  cout << high << endl;
}