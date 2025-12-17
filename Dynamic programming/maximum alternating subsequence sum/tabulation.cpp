#include<bits/stdc++.h>
using namespace std;
int n;
typedef long long ll;
ll solve(vector<int>& arr,int n){
    int dp[n + 1][2];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n;i++){
        dp[i][0] = max(dp[i - 1][1] - arr[i - 1], dp[i - 1][0]);
        dp[i][1] = max(dp[i - 1][0] + arr[i - 1], dp[i - 1][1]);
    }
    return max(dp[n][0], dp[n][1]);
}

int main()
{
    vector<int> arr = {4,2,7,3,1};
    n = arr.size();
    cout << solve(arr,n);//true as starting index is 0(even)
    return 0;
}
