#include<bits/stdc++.h>
using namespace std;

int main() {
  int x  = 121;
  int temp = x;
  int palidromeCheck = 0;
  while(temp != 0){
      cout << palidromeCheck <<"  ";
      palidromeCheck = palidromeCheck * 10 + temp % 10;
      temp = temp/10; 
  }
        
  cout << palidromeCheck;

}