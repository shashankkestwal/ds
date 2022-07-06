#include <bits/stdc++.h>
using namespace std;

// vector<vector<string>> groupAnagrams(vector<string>& s) {
//         int n=s.size();
//         unordered_map<string,vector<string>>mp;
//         string str;
//         for(int i=0;i<n;i++)
//         {   str = s[i];
//             sort(s[i].begin(),s[i].end());
//             //put into the map
//             mp[s[i]].push_back(str);
//         }
//         vector<vector<string>> ans;
//         for(auto it:mp)
//         {
//             ans.push_back(it.second);
//         }
//        return ans;
// }


vector<vector<string>> groupAnagrams(vector<string> s) {
  string str;
  unordered_map <string, vector<string>> umap;
  for (int i = 0; i < s.size(); ++i) {
    str = s[i];
    sort(str.begin(), str.end());
    umap[str].push_back(s[i]);
  }
  vector<vector<string>> ans;
  for(auto i : umap) {
    ans.push_back(i.second);
  }
  return ans;
}



int main() {
  // unordered_map<string, vector<string>> umap;
  // umap["a"].push_back("1");
  // umap["b"].push_back("123");
  // umap["c"].push_back("23");

  string aaaaa = "abba";
  string r; 
  vector<string> vstring; 

  string str = "dog cat cat dog";
  int index = 0;
  while(index != -1 ) {
    index = str.find(" ");
    r = str.substr(0, index);
    str = str.substr(index+1);
    vstring.push_back(r);
  }  
  unordered_map <char, string> umap;
  int counter = 0;
  bool ans = true;
  for(int i = 0 ; i < aaaaa.length() && counter < vstring.size(); i++) {
      if(umap.find(aaaaa[i]) == umap.end()) {
        umap[aaaaa[i]] = vstring[counter];
        counter++;
        continue;
      }
      if(umap[i] != vstring[counter]) {
        ans = false;
        break;
      }
      counter++;
  }
  // if(counter < vstring.size()) return false;
  // cout << ans; 
  // for(auto i : umap) {
  //   cout << i.first << "  " << i.second;
  // }

  map<string, int> temp;
  for(auto i : umap) {
    temp[i.second]++ ;
  }
  for(auto i : temp) {
    if(i.second >= 1) ans = false;
  }
  cout << ans;


  // do { 
    
  //   cout << index << endl;
    
  //   cout << str <<"|";
  //   prev = index;
  // } while(index != -1);
  return 0;
}