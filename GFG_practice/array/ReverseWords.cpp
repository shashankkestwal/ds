#include <bits/stdc++.h>
// CPP program to illustrate substr()
#include <string.h>

using namespace std;

int main() {
  string s = "the sky a is blue";

  queue<string> q1;
  stack<string> s1;

  int prev = 0;
  int after = s.length()-1;

  while(prev <= after) {
    int i = prev;
    int j = after;
    while(s[i] != ' ') i++;
    while(s[j] != ' ') j--;
    string first = s.substr(prev, i-prev + 1); 
    string second = s.substr(j, after - j+1 );
    if(i >= j) {      
      q1.push(second);
    } else{
      q1.push(second);
      s1.push(first);
    }
    prev = i+1;
    after = j-1;
  } 
  while(!q1.empty() ) {
    cout << q1.front();
    q1.pop();
  }
  while(!s1.empty() ) {
    cout << s1.top();
    s1.pop();
  }
  return 0;
}
