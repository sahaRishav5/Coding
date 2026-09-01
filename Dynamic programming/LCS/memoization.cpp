#include<bits/stdc++.h>
using namespace std;

int fun(string s1,string s2, int n,int m,int i,int j,vector<vector<int>> &dp){
    if(i==n or j==m){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(s1[i]==s2[j]){
        return dp[i][j]=(1 + fun(s1, s2, n, m, i + 1, j+1,dp));
    }
    int c1 = fun(s1, s2, n, m, i + 1, j,dp);
    int c2 = fun(s1, s2, n, m, i, j + 1,dp);
    return dp[i][j]=max(c1, c2);
}

int main(){
    string s1 = "hello";
    string s2 = "heyo";

    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    cout << fun(s1, s2, n, m, 0, 0,dp);
    return 0;
} 