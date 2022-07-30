#include <bits/stdc++.h>
using namespace std;

// void getSubsequence(string s, int index, string subsequence, vector<string>& ans) {
//   if(index >= s.length()) {
//     ans.push_back(subsequence);
//     return;
//   }

//   // include 
//   getSubsequence(s, index+1,subsequence, ans);
//   // exclude
//   subsequence.push_back(s[index]);
//   getSubsequence(s, index+1,subsequence, ans);
// }

// int main() {
//   string s = "abcde";
//   int index = 0;
//   string subsequence = "";
//   vector<string> ans;
//   getSubsequence(s, index, subsequence,ans);
//   for (int i = 0; i < ans.size(); ++i) {
//     cout << ans[i] <<"  ";
//   }
// }

void solve(string digits, int index , vector<string>& ans, string s, string* map) {
        if(index == digits.size()) {
            ans.push_back(s);
            return;
        }
        for(auto c : map[digits[index]-'0']) {
            s.push_back(c);
            solve(digits, index+1, ans, s, map);
            s.pop_back();
        }
    }

vector<string> letterCombinations(string digits) {
    string map[] = {"","","abc","def","ghi","jkl","mno","pqrs", "tuv","wxyz"};
    int index = 0;
    vector<string> ans;
    string s = "";
    solve(digits, index , ans , s, map);
    for(auto i : ans) cout << i << endl;
    return ans;
}

int main() {
  letterCombinations("23");
  return 0;
}