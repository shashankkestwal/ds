#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> candidates, int target, int val,vector<int> output, vector<vector<int>>& ans, int index) {
        if(index == candidates.size()) {
            
            return;
        }
        for(int i = index ; i < candidates.size(); i++) {
            val += candidates[i];
            if(val == target) ans.push_back(output);
            output.push_back(candidates[i]);
            solve(candidates, target, val, output, ans , i+1);
            val -= candidates[i];
            output.pop_back();
        }
}
    
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int val = 0;
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        for(int i = 0; i < ans.size(); i++) {
            for(int j = 0; j < ans[i].size(); j++) {
                cout << ans[i][j] <<"   ";
            }cout << endl;
        }
        return ans;
}

int main() {
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>> ans = combinationSum2(candidates, target);

}