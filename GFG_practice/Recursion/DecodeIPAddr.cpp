#include <bits/stdc++.h>
using namespace std;


string defangIPaddr(string address) {
        int index = 0;
        for(auto c : address) {
            if(c == '.') {
                cout << index << endl;
                address.insert(index,"[");
                index+=2;
                address.insert(index,"]");
            }
            index++;
        }
        return address;
    }

int main() {
  defangIPaddr("1.1.1.1");
  return 0;
}