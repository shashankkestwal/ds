#include <bits/stdc++.h>
using namespace std;

// void solve(string s, string p, vector<int>& ans) {
//   unordered_map<char, int> smap;
//   unordered_map<char, int> pmap;
//   for(int i = 0; i < p.length(); i++) {
//     smap[s[i]]++;
//     pmap[p[i]]++;
//   }

//   for(int i = 0; i <= s.length() - p.lengh(); i++) {
//     for(auto i : smap) {
//       if(umap)
//     }
//   }
// }

int main() {
  string s;
  cin >> s;
  string p;
  cin >> p;
  vector<int> ans;
  vector<int> a;
  vector<int> b;
  a[0] =1;
  b[0] =1;
  if(a == b) cout <<"True";

  return 0;
}
// vector<int> findAnagrams(string s, string p) {
//         int s_len = s.length();
//         int p_len = p.length();
        
//         if(s.size() < p.size()) return {};
        
//         vector<int> freq_p(26,0);
//         vector<int> window(26,0);
        
//         //first window
//         for(int i=0;i<p_len;i++){
//             freq_p[p[i]-'a']++;
//             window[s[i]-'a']++;
//         }
        
//         vector<int> ans;
//         if(freq_p == window) ans.push_back(0);
        
//         for(int i=p_len;i<s_len;i++){
//             window[s[i-p_len] - 'a']--;
//             window[s[i] - 'a']++;
            
//             if(freq_p == window) ans.push_back(i-p_len+1);
//         }
//         return ans;
//     }
