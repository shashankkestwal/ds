#include<bits/stdc++.h>
using namespace std;
long long solve(vector<int>& v, int start, int end,int sum ,int x) {
    // cout << "Here" << endl;   
    if(x == sum ) return 0;
    if(sum > x) {
        return INT_MAX;
    } 
    if(start == v.size()-1 || end == 0) return INT_MAX;
    if(start > end) return INT_MAX;
    // case 1 - take from start
    long long s = solve(v, start+1, end, sum + v[start], x) + 1;
    // case 2 - tale from end 
    long long e = solve(v, start, end -1 , sum + v[end], x) + 1;
    // if(s < 0 && e < 0) 
    //     return -1;
    // if(s < 0) 
    //     return e;
    // if(e < 0) 
    //     return s;
    return min(s, e);
}

int minOperations(vector<int>& nums, int x) {
    int ans = solve(nums, 0, nums.size() -1, 0, x);
    if(ans < 0) return -1;
    return ans;
}

int main() {
    vector<int> v = {1241,8769,9151,3211,2314,8007,3713,5835,2176,8227,5251,9229,904,1899,5513,7878,8663,3804,2685,3501,1204,9742,2578,8849,1120,4687,5902,9929,6769,8171,5150,1343,9619,3973,3273,6427,47,8701,2741,7402,1412,2223,8152,805,6726,9128,2794,7137,6725,4279,7200,5582,9583,7443,6573,7221,1423,4859,2608,3772,7437,2581,975,3893,9172,3,3113,2978,9300,6029,4958,229,4630,653,1421,5512,5392,7287,8643,4495,2640,8047,7268,3878,6010,8070,7560,8931,76,6502,5952,4871,5986,4935,3015,8263,7497,8153,384,1136};
    int x = 894887480;
    cout << minOperations(v, x);
    return 0;
}

