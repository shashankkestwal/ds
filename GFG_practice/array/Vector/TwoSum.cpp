#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int , int > umap;
        int i = 0, j;
        umap[nums[i]] = i;
        for(i = 1; i < nums.size(); i++) {
            if(umap.find(target - nums[i]) == umap.end()){
                umap[nums[i]] = i;
            } else {
                j = umap.at(target - nums[i]);
                break;
            }
        }
        
        vector <int> ans;
        ans.push_back(i);
        ans.push_back(j);
        return ans;
}

int main() {
    vector<int> test;
    test.push_back(2);
    test.push_back(7);
    test.push_back(11);
    int n = 9;
    vector <int>  a = twoSum(test, n);
    for (auto i = a.begin(); i < a.end(); ++i) {
        cout << *i <<"  ";
    }
    return 0;
}