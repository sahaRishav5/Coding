#include<bits/stdc++.h>
using namespace std;
int func(vector<int> &val,vector<int> &wt,int i,int n,int cap,vector<vector<int>> &dp){
    if(i==n){
        return 0;
    }
    if(dp[i][cap]!=-1){
        return dp[i][cap];
    }
    if(wt[i]>cap){
        return dp[i][cap] = func(val, wt, i + 1, n, cap, dp);
    }
    int pick = val[i]+ func(val, wt, i + 1, n, cap-wt[i], dp);
    int notpick = 0 + func(val, wt, i + 1, n, cap, dp);
    return dp[i][cap] = max(pick, notpick);
}
int main(){
    vector<int> val = {5, 1, 3};
    vector<int> wt = {10, 8 , 8};
    int n = wt.size();
    int cap = 21;
    vector<vector<int>> dp(n+1, vector<int>(cap+1, -1));
    cout << func(val, wt, 0, n, cap, dp);
    return 0;
}