#include<bits/stdc++.h>
using namespace std;
long long solve(vector<int> arr,int ind,int n,vector<int> dp){
    if(ind>=n) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int pick = arr[ind] + solve(arr, ind + 2, n,dp);
    int notpick = 0 + solve(arr, ind + 1, n,dp);
    return dp[ind]=max(pick, notpick);
}
int main()
{
    vector<int> arr = {1, 2, 3, 1};
    int n = arr.size();
    vector<int> dp(n + 1, -1);
    cout << solve(arr, 0,n,dp);
    return 0;
}
