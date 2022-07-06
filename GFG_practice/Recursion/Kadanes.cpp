#include<bits/stdc++.h>
using namespace std;

int maxSubArraySum(int a[], int size)
{
    int curr_max = a[0];
    int ans = a[0];
    for(int i = 0; i < size; i++) {
        curr_max = max(a[i], curr_max+ a[i]);
        ans = max(ans, curr_max);
    }
    return ans;
    // int max_so_far = a[0];
    // int curr_max = a[0];

    // for (int i = 1; i < size; i++)
    // {
    //     curr_max = max(a[i], curr_max+a[i]);
    //     max_so_far = max(max_so_far, curr_max);
    // }
    // return max_so_far;
}

/* Driver program to test maxSubArraySum */
int main()
{
    vector<int> nums = {9,4,1,7};
    int k = 2;

        //     int n=nums.size();
        // sort(nums.begin(),nums.end());
        // int m,minres=2147483647;
        // for(int i=0;i<(n-k+1);i++)
        // {
        //     cout <<"|  "<< i <<"   "<< i+k-1<< "    |";
        //     m=nums[i+k-1]-nums[i];
        //     minres=min(m,minres);
        //     }
        // cout <<  minres;


    int min_ans = nums[0];
    sort(nums.begin(), nums.end());
    int i = nums.size() - 1;
    while(i > 0) {
        cout << i <<"  "<<i-k+1 << "   |";
        if(i - k + 1 >= 0) {
            min_ans = min(min_ans, nums[i] - nums[i-k+1]);
        }     
        i--;
    }
    cout <<  min_ans;



    // int a[] = {-2, 4, 4, -1, -2, 1, 5, -3};
    // int n = sizeof(a)/sizeof(a[0]);
    // int max_sum = maxSubArraySum(a, n);
    // cout << "Maximum contiguous sum is " << max_sum;
    // return 0;
}
