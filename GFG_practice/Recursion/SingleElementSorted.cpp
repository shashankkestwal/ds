#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int low = 0;
    int high = nums.size()-1;
    int mid;
    int ans;
    while(low < high) {
        mid = low + high / 2;
         cout << mid ;
        if( (mid + 1 < nums.size() && nums[mid + 1] == nums[mid]) ||( mid - 1 > 0 && nums[mid - 1] == nums[mid] ) )continue;
        else if((mid + 1 < nums.size() && nums[mid + 1] != nums[mid]) && ( mid - 1 > 0 && nums[mid - 1] != nums[mid] )) ans = nums[mid];
    } 
    return ans;
}

int main() {
    vector<int> nums = {1,1,2,3,3,4,4,8,8};
    singleNonDuplicate(nums);
    return 0;
}


// half solved right now    ---- > 