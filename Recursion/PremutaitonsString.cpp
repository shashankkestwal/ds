#include <bits/stdc++.h>
using namespace std;

void solve(string s, int index) {
  if(index == s.length()){
    cout << s << endl;
    return;
  }
  for(int i = index; i < s.length(); i++){
    swap(s[index], s[i]);
    solve(s,index+1);
    swap(s[index], s[i]);
  }
}

int main() {
  string s = "cab";
  sort(s.begin(),s.end());
  solve(s, 0);
  cout << s;
  return 0;
}