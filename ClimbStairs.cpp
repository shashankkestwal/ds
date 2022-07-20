#include <bits/stdc++.h>
using namespace std;


// normal recursion
// // int solve1(vector<int>&cost, int n) {
// //     if(n <= 1) return cost[n];
// //     int ans = cost[n] + min(solve1(cost, n-1), solve1(cost, n-2));
// //     return ans;
// // }
// // // top down -> recursion & momoization
// // int solve2(vector<int>& cost, vector<int>& dp, int n) {
// //     if(n <= 1) return cost[n];
// //     if(dp[n] != -1) return dp[n];
// //     dp[n] = cost[n] + min(solve2(cost, dp, n-1), solve2(cost, dp, n-2));
// //     return dp[n];
// // }
// // // bottom up approach
// // int solve3(vector<int>& cost, vector<int>& dp, int n) {
// //     dp[0] = cost[0];
// //     dp[1] = cost[1];
// //     for(int i = 2; i < n ; i++ ) {
// //         dp[n] = cost[n] + cost(dp[n-1], dp[n-1]);
// //     }
// //     return min(dp[n-1], dp[n-2]);
// // }
// int solve4(vector<int>& cost, int n) {
//     int prev1 = cost[0];
//     int prev2 = cost[1];
//     int curr;
//     for(int i = 2 ; i < n ; i++){
//       curr = cost[i] + min(prev1 ,prev2);
//       prev1 = prev2;
//       prev2 = curr;
//     }
//     return min(prev1, prev2);
// }



int main() {
  vector<int> dp(100,0);
  cout << dp[100];
  // dp[0] = 1;
  // dp[1] = 1;
  // int n = 4; 
  // for(int i = 2; i <= n; i++) {
  //   dp[i] = dp[i-1] + dp[i-2];
  // }
  // cout << dp[n];
  return 0;
}