#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> val = {5, 1, 3};
    vector<int> wt = {10, 8 , 8};
    int n = wt.size();
    int cap = 21;
    vector<vector<int>> dp(n + 1, vector<int>(cap+1));
    for (int i = 0; i <= cap;i++){
        dp[n][i] = 0;
    }
    for (int i = n - 1; i >= 0;i--){
        for (int j = 0; j <= cap;j++){
            if(wt[i]>j){
                dp[i][j] = dp[i + 1][j];
            }
            else{
                int pick = val[i] + dp[i + 1][j - wt[i]];
                int notpick = 0 + dp[i + 1][j];
                dp[i][j] = max(pick, notpick);
            }
        }
    }
    cout << dp[0][cap];
    return 0;
}