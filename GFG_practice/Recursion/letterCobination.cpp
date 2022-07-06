#include <bits/stdc++.h>
using namespace std;


void solve(string digits, string output, int index, string mapping[] , vector<string>& ans) {
    if(index == digits.length()){
      ans.push_back(output);
      return;
    } 
    int currIndex = digits[index] - '0';
    string currStr = mapping[currIndex];
    for( auto i : currStr) {
      output.push_back(i);
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
  vector<string> ans = letterCombinations("234");
  for(auto i : ans) {
    cout << i <<"   ";
  }
}