#include<bits/stdc++.h>
using namespace std;

int main() {
  vector <int> a;
  auto i = a.begin();
  i--;
  cout << "   " << *i <<" test";
  for (int i = 0; i < 5; ++i) {
    a.push_back(i);
  }

  for(auto i = a.begin(); i != a.end(); i++) {
    cout << *i <<" ";    
  }
  cout << endl;
  for (auto i = a.cbegin();i != a.cend();i++)
  {
    cout << * i <<" ";
  }
  cout << endl;
  for (auto i = a.rbegin();i != a.rend();i++)
  {
    cout << * i <<" ";
  }
  cout << endl;
  for (auto i = a.rbegin();i != a.rend();i++)
  {
    cout << * i <<" ";
  }
  return 0;
}