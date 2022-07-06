#include <bits/stdc++.h>
using namespace std;

int findPivot(vector<int> nums) {
        for(int i = 0; i < nums.size(); i++ ) {
            if(nums[i+1] < nums[i]){
                return i+1;
            }
        }
        return 0;
    }

int binarySearch(vector<int> ans,int start, int end, int target){
    int mid = (start+end) / 2;
    // cout << endl;
    // cout << start  << "  " << end;
    // cout << endl;
    while(start <= end) {
        
        if(ans[mid] == target) {
            return mid;
        } else if(ans[mid] > target) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
        mid = (start+end) / 2;
    }
    return -1; 
}


int main() {
    vector<int> nums = {4,5,6,7,0,1,2};
    // cout << binarySearch(nums , 0, nums.size()-1, 3);
    // int target = 8;
    // vector<vector<int>> ans = combinationSum2(candidates, target);
    int pivot = findPivot(nums);
    int target = 0;

    if(target >= nums[pivot] && target <= nums[nums.size()-1]){
        cout <<  binarySearch(nums,pivot,nums.size()-1,target);
    }
    else{
        cout << binarySearch(nums,0,pivot-1,target);
    }

    // cout << pivot << endl; 
    // bool ans = binarySearch(nums,0 , pivot-1, target) ;
    // cout << ans << "    ";
    // ans = binarySearch(nums, pivot , nums.size()-1, target);
    // cout << ans <<"  ";
}