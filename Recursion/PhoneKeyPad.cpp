#include <bits/stdc++.h>
using namespace std;

void solve(string digits, string output, int index, string mapping[] , vector<string>& ans) {
    
        if(index >= digits.length()) {
            ans.push_back(output);
            return;
        }
        int in = digits[index] - '0';
        string curr  = mapping[in];
        for(int i = 0; i < curr.length(); i++) {
            output.push_back(curr[i]);
            solve(digits, output, index+1, mapping, ans);
            output.pop_back();
        }
    }
    
vector<string> letterCombinations(string digits) {

        string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        if(digits.length() == 0) return ans;
        string output = "";
        int index = 0;
        solve(digits,output,index,mapping,ans);
        return ans;
}

int main() {
    auto ans = letterCombinations("233");
    for(int i = 0; i< ans.size(); i++) {
        cout << ans[i] <<"  ";
    }
    return 0;
}