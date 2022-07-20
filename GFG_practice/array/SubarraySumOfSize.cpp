#include <bits/stdc++.h>
using namespace std;

int numSubarraysWithSum(vector<int>& nums, int goal) {
    int i = 0;
    int j = 0;
    int ans = 0;
    int currSum = nums[0];
    while(j < nums.size() && i <= j) {
        if(currSum > goal) {
            currSum -= nums[i];
            cout << "incrementing i" << endl;
            i++;
        } else if(currSum == goal) {
            ans++;
            cout << "sum found incrementing j " << endl;
            currSum += nums[j];
            j++;
        } else {
            cout << "incrementing j" << endl;
            currSum += nums[j];
            j++;
        }
    }
    return ans;
}


int main(int argc, char const *argv[])
{
  vector<int>  nums = {1,0,1,0,1};
  cout << numSubarraysWithSum(nums, 2);
  return 0;
}