#include <bits/stdc++.h>
using namespace std;

bool solve(string s1, int index, string s2) {
        if(index == 0) {
            if(strstr(s2.c_str(),s1.c_str())) return true;
        } 
        bool val;
        for(int i = index; i < s1.length(); i++) {
            swap(s1[index], s1[i]);
            val = solve(s1, index, s2);
            swap(s1[index], s1[i]);
            return val;
        }  
        return true;
    }

bool checkInclusion(string s1, string s2) {
        int index =  0;
        return solve(s1, index, s2);        
}

int main(){
    string s1 = "abcd";
    string s2 = "abcewsdas";
    cout << checkInclusion(s1, s2);
}