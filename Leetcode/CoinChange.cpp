#include <iostream>
#include <limits.h>
#include <vector>
// #include <bits/stdc++.h>
using namespace std;

// // recursive coin change
// int solve(vector<int>& coins, int amount, int count = 0) {
//   if(amount == 0) {
//     return 0;
//   }
//   if( amount < 0 ) 
//     return INT_MAX;
//   int mini = INT_MAX;
//   for(auto i : coins) {  
//     int ans = solve(coins, amount - i, count+1);
//     if(ans != INT_MAX)
//       mini = min(ans+1, mini);
//   }
//   return mini;
// }

// // recursive + memoized 
// int solveMem(vector<int>& coins, int amount, vector<int>& dp) {
//   if(amount == 0) {
//     return 0;
//   }
//   if( amount < 0 ) 
//     return INT_MAX;
//   if(dp[amount] != -1) {
//     return dp[amount];
//   }
//   int mini = INT_MAX;
//   for(auto i : coins) {  
//     int ans = solveMem(coins, amount - i, dp);
//     if(ans != INT_MAX)
//       mini = min(ans+1, mini);
//   }
//   dp[amount] = mini;
//   return dp[amount];
// }

// tabulation method 
int solveMem(vector<int>& coins, int amount) {
  vector<int> dp(amount+1, INT_MAX);
  dp[0] = 0;
  for(int i = 1; i <= amount; i++) {
    for(auto j : coins) {
      if((i - j >= 0) && dp[i-j] != INT_MAX)
        dp[i] = min(dp[i], 1+ dp[i-j]);
    }
  }
  if(dp[amount] == INT_MAX) return -1;
  return dp[amount];
}


int main(){
  int amount;
  cin >> amount;
  vector<int> coins = { 1, 5, 10, 20, 100};
  // int ans = solve(coins, amount);
  // if(ans == INT_MAX ) cout << "cannot form this number" ;
  // cout << ans << endl; 
  // return 0;
  vector<int> dp(amount+1, -1);
  int ans = solveMem(coins, amount);
  if(ans == INT_MAX) return -1;
  cout << ans;
}