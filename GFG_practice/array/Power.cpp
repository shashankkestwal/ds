#include <bits/stdc++.h>
using namespace std;

int power(int a, int b) {
  if(a == 0) return a;
  if(b == 0) return 1;
  if(b % 2 == 1) return a * (power(a,b/2) * power(a,b/2));
  else return (power(a,b/2) * power(a,b/2));
}

int main() {
  int a, b;
  cout << "Enter base :" ;
  cin >> a;
  cout << "Enter power :" ;
  cin >> b;

  int ans = power(a,b);
  cout << ans;
}

