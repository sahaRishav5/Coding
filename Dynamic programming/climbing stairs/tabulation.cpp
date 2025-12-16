#include<bits/stdc++.h>
using namespace std;
long long solve(int dp[],int n){
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n;i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
int main()
{
    int n;
    cin >> n;
    int dp[n+1];
    memset(dp, -1, sizeof(dp));
    cout << solve(dp,n);
    return 0;
}
