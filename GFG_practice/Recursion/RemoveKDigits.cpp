#include <bits/stdc++.h>
using namespace std;

int minNum = INT_MAX;
string ans = "";

void solve(string num, int k, int n) {
        if(n + k -1 == num.length()) return;
        string temp = num;  
        temp.erase(n, k);
        cout << temp << endl;
        if(stoi(temp) < minNum) {
            ans = temp;
            minNum = stoi(temp);
        } 
        solve(num, k, n+1);
}

int main() {
  // string s = "112233453";
  // int k = 2;
  // solve(s, k, 0);
  // cout << minNum << endl;



  vector<int> nums = {1,1,2,2,3,3};
  int ans = 0;
        auto i = nums.begin() + 1;
        while( i != nums.end()) {
            if(*(i - 1) == *i) {
                nums.erase(i);
                ans++; 
                continue;
            } 
            i+=2;
        }
        if(nums.size() % 2 == 0) cout << ans;
        else cout <<  ans+1;
}