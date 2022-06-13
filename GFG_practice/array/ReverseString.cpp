#include <bits/stdc++.h>
using namespace std;

string reverseString(string& s, int start, int end) {
  if(start > end ) {
    return s;
  }
  swap(s[start],s[end]);
  return reverseString(s,start+1, end-1);
}

int main() {
  string s = "aa bb cd";
  cout << reverseString(s, 0 , s.length()-1);
  cout << endl << s;
  return 0;
}