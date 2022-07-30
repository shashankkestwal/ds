#include <bits/stdc++.h>
using namespace std;

int dp[100];
// int x = 1e5+10;

// memoization to solve fibonacci series 
// using recursion

int fibonacci(int n) {
  if(n <= 1) return n;
  if(dp[n] != -1) return dp[n];
  else dp[n] = fibonacci(n-1) + fibonacci(n-2);
  return dp[n];   
}

// bottom up approach to solve fibonacci series problem 
// takes o(n) time

int fibBottomUp(int n) {
  for(int i = 0; i <= n ; i++) {
    if(i <= 1) dp[i] = i;
    else dp[i] = dp[i-1]+dp[i-2];
  }
  return dp[n];
}

int fibUsingariable(int n) {
  int prev1 = 1;
  int prev2 = 0;
  int curr;
  for(int i = 2; i < n ; i++) {
    curr = prev1+ prev2;
    prev2 = prev1;
    prev1 = curr;
  }
  return prev1;
}
void solve(stack<int>&s, int sizeOfStack, int index) {
  cout << "   " << index << "  " << sizeOfStack << endl;
    if(index >= sizeOfStack / 2) {
        s.pop();
        return; 
    }
    int x = s.top();
    s.pop();
    solve(s, sizeOfStack, index+1);
    s.push(x);
}

int main() {
  // stack<int> s;
  // int n;
  // cin >> n;
  // int num;
  // for(int i = 0;i < n ; i++) {
  //   cin >> num;
  //   s.push(num);
  // }
  // solve(s, s.size(), 0);
  // while(!s.empty()) {
  //   cout << s.top() <<"   ";
  //   s.pop();
  // }
}

