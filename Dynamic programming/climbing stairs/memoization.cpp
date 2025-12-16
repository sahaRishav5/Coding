#include<bits/stdc++.h>
using namespace std;
int dp[46];
long long solve(int n){
    if(n<0){
        return 0;
    }
    if(dp[n]!=-1) {
        return dp[n];
    }
    if(n==0 || n==1){
        return 1;
    }
    else{
        return dp[n]=solve(n - 1) + solve(n - 2);
    }
}
int main()
{
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << solve(n);
    return 0;
}
