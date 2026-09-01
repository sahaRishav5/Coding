#include<bits/stdc++.h>
using namespace std;
bool func(vector<int> &a,int i, int sum,int n, vector<vector<int>> &dp){
    if(i==n){
        if(sum==0){
            return true;
        }
        return false;
    }
    if(dp[i][sum]!=-1){
        return dp[i][sum];
    }
    if(a[i]>sum){
        return dp[i][sum]=func(a, i + 1, sum, n, dp);
    }
    bool c1 = func(a, i + 1, sum - a[i], n, dp);
    bool c2 = func(a, i + 1, sum, n, dp);
    dp[i][sum] = c1 or c2;
    return dp[i][sum];
}
int main(){
    vector<int> a = {1, 3, 3, 5};
    int n = a.size();
    int sum = 5;
    vector<vector<int>> dp(n+1, vector<int>(sum+1));
    for (int j = 0; j <= sum;j++){
        dp[n][j] = 0;
    }
    dp[n][0] = 1;
    for (int i = n - 1; i >= 0;i--){
        for (int j = 0; j <= sum;j++){
            if(a[i]>j){
                dp[i][j] = dp[i + 1][j];
            }
            else{
                dp[i][j] = (dp[i+1][j-a[i]]) or (dp[i+1][j]);
            }
        }
    }
    cout << dp[0][sum];  

    return 0;
}