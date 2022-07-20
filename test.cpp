#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int getMaxOccurance(const int *arr, int n) {
  int maxcount=0;
  for(int i=0;i<n;i++)
  {
    int count=0;
    for(int j=0;j<n;j++)
    {
      if(arr[i] == arr[j])
        count++;
    }
 
    if(count > maxcount)
    {
      maxcount = count;
    }
  }
 
  return maxcount;
}

int main() {
    vector<int> ans;
    cout << "test size ";
    int t;
    cin >> t;
    while(t--) {
        int size;
        cin >> size;
        int arr[size];
        for(int i = 0; i < size; i++ ){
            cin >> arr[i];
        }
        int maxOccur = getMaxOccurance(arr, size);
        // cout << maxOccur;
        ans.push_back(size - maxOccur);
    } 
    for(auto i : ans ) cout << i << endl;
	return 0;
}