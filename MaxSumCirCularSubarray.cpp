#include <bits/stdc++.h>
using namespace std;

int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN;
        // kadane's algorithm 
        
        for(int j = 0; j < nums.size(); j++ ) {
            int curr = 0;
            for(int i = 0; i < n; i++) {
                int index = (j + i) % n;
                cout << index << "  ";
                curr += nums[index]; 
                maxSum = max(maxSum, curr);
                if(curr < 0) curr = 0;
            }
            cout << endl; 
        }
        
        return maxSum;
    }


int main() {
  vector<int> a = {1,-2,3,-2};
  cout << maxSubarraySumCircular(a);
  return 0;
}