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
    vector<int> a = {1, 3, 2, 7};
    int n = a.size();
    int sum = 5;
    vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
    if(func(a, 0, sum, n, dp)){
        cout << "true";
    }else{
        cout << "false";
    }
    return 0;
}