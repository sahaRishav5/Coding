#include<bits/stdc++.h>
using namespace std;

int fun(vector<int> &arr,int n,int i,int prev,vector<vector<int>> &dp)
{
    if(i==n){
        return 0;
    }
    if(dp[i][prev+1]!=-1){
        return dp[i][prev+1];
    }
    if(prev==-1 || arr[i]>arr[prev]){
        int c1 = 1+ fun(arr, n, i + 1, i,dp);
        int c2 = 0 + fun(arr, n, i + 1, prev,dp);
        return dp[i][prev+1]=max(c1, c2);
    }
    return dp[i][prev+1]=fun(arr, n, i + 1, prev,dp);
}

int main(){
    vector<int> arr = {10,2,6,5,4,7,9};
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    cout << fun(arr, n, 0, -1,dp);
    return 0;
}