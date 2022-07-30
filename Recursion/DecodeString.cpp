#include <bits/stdc++.h>
using namespace std;

void solve( string& s, string& ans) {
    if(s.length() == 0) {
        return ;
    }
    string substr = "";
    int index = 2;
    while(s[index] != ']'){
        substr.push_back(s[index]);
        index++;
    }
    cout << s << endl;
    if(s[0] - '0' == 1) {
        s = s.substr(index+1);
    } else if(s[0] >= 97) {
        return;
    } else{
        s[0] = s[0]-1;
    }
    ans.append(substr);
    solve(s, ans);
}

bool myComp(pair<int,int> p, pair<int,int> q) {
    return p.second > q.second;
}
int main() {
    // string s = "2[xyzz]9[bc]efgh";
    // string ans = "";
    // solve(s, ans);
    // ans.append(s);
    // cout << ans;
    // return 0;
    priority_queue<pair<int, int> , myComp> p1;
    p1.push(make_pair(4, 5));
    p1.push(make_pair(5, 4));
    p1.push(make_pair(1, 6));
    p1.push(make_pair(7, 3));
    p1.push(make_pair(9, 4));
    while (!p1.empty()) {
        cout << p1.top().first
             << " " << p1.top().second
             << endl;
        p1.pop();
    } 
}