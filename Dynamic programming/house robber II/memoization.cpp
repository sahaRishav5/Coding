#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> arr,int start,int end,vector<int> dp){
    if(start>=end) return 0;
    if(dp[start]!=-1) return dp[start];

    int pick = arr[start] + solve(arr, start + 2, end,dp);
    int notpick = 0 + solve(arr, start + 1, end,dp);
    return dp[start]=max(pick, notpick);
}
/* if 0th index selected ,then (n-1)th wont be selected
and vice versa */
int main()
{
    vector<int> arr = {1, 2, 3, 1,8};
    int n = arr.size();
    vector<int> dp(n + 1, -1);
    int case1 = solve(arr, 0,n-1,dp);//[0...(n-2)]
    int case2 = solve(arr, 1, n,dp);//[1...(n-1)]
    cout << max(case1, case2);
    return 0;
}
