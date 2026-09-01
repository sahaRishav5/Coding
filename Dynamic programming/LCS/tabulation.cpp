#include<bits/stdc++.h>
using namespace std;

int main(){
    string s1 = "hello";
    string s2 = "heyo";

    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    //dp[n][j]=0 and dp[i][m]=0
    for (int i = n - 1; i >= 0;i--){
        for (int j = m - 1; j >= 0;j--)
        {
            if(s1[i]==s2[j]){
                dp[i][j] = 1 + dp[i + 1][j + 1];
            }
            else{
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }
    cout << dp[0][0];
    return 0;
} 