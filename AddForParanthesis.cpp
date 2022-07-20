#include <bits/stdc++.h>
using namespace std;

int minAddToMakeValid(string s) {
  int open = 0;
  int need = 0;
  for(auto c : s) {
      if(c == '('){ 
        open++;
      } else if(c == ')' && open > 0){
         open--;
      }
      else {
        need++;
      };
  }
  return need + open;
}

int main() {
  cout << minAddToMakeValid("()))((");
  return 0;
}

