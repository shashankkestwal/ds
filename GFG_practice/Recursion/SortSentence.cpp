#include <iostream>
using namespace std;

// int arrsize = 1e3+10;
int size = 0;
string arr[100];

void sortSentence(string s) {
  int index;
  while(s.length() > 0 ) {
    int pos = s.find(' ');
    if(pos == - 1) break;
    index = (s[pos-1] - '0' - 1);
    cout << index  << "   "<< s.substr(0,pos-1) << endl;
    arr[index] = s.substr(0, pos - 1);
    s = s.substr(pos+1);   
    size++;   
  }
  index = s[s.length() - 1]- '0' - 1;
  s.pop_back();
  arr[index] = s;
  cout << index << "   " << arr[index] << endl;
  size++;
}

int main(){
  sortSentence("is2 sentence4 This1 a3");
  // cout << size << endl;
  string ans = "";
  for(int i = 0; i < size ; i++) {
    if(i == size - 1){
      ans += arr[i];
      break;
    }
    ans += arr[i] +" ";
  } 
  cout << ans;
  return 0;
}