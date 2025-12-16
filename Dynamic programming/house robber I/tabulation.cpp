#include<bits/stdc++.h>
using namespace std;
//dp[i] means max stolen money upto house 
long long solve(vector<int>& arr,int n,vector<int>& dp){
    dp[0] = arr[0];
    for (int i = 1; i < n;i++){
        int pick = arr[i] + ((i>1)?dp[i - 2]:0);
        int notpick = 0 + dp[i - 1];
        dp[i] = max(pick, notpick);
    }
    return dp[n - 1];
}
int main()
{
    vector<int> arr = {1, 2, 3, 1};
    int n = arr.size();
    vector<int> dp(n+1, -1);
    cout << solve(arr,n,dp);
    return 0;
}
