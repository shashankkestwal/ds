#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums, int index, vector<int> dp) {
  if(index < 0) return 0;
  if(dp[index] != -1) return dp[index];
  dp[index] = max(solve(nums, index - 2, dp) + nums[index], solve(nums, index - 1, dp));
  return dp[index]; 
}

int solve(vector<int>& nums) {
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    for (int i = 1; i < dp.size(); i++) {
        dp[i] = max((dp[i - 2] + nums[i]), (dp[i - 1]));
    }
    return dp[nums.size() - 1];
}

int main() {
  vector<int> house = {1,4,2,3,8};
  int n = house.size();
  vector<int> dp(n+1, -1);
  int ans = solve(house);
  cout << ans;
  return 0;
}