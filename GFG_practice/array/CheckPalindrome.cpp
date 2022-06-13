#include <bits/stdc++.h>
using namespace std;

bool checkPalindrome(string& s, int start, int end) {
  if(start > end ) {
    return true;
  }
  if(s[start] != s[end]) {
    return false;
  }
  return checkPalindrome(s,start+1, end-1);
}

int main() {
  string s = "a";
  cout << checkPalindrome(s, 0 , s.length()-1);
  cout << endl << s;
  return 0;
}