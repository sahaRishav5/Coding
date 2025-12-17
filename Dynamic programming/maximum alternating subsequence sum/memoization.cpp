#include<bits/stdc++.h>
using namespace std;
int n;
typedef long long ll;
ll dp[1000001][2];
ll solve(vector<int>& arr,int idx,bool flag){
    if(idx>=n) {
        return 0;
    }
    if(dp[idx][flag]!=-1){
        dp[idx][flag];
    }
    ll val = arr[idx];
    ll skip = solve(arr, idx + 1, flag);
    if(flag==false){
        val = -val;
    }
    ll pick =  solve(arr, idx + 1, !flag) + val;
    return dp[idx][flag]=max(pick, skip);
}

int main()
{
    vector<int> arr = {6,2,1,2,4,5};
    n = arr.size();
    memset(dp, -1, sizeof(dp));
    cout << solve(arr,0, true);//true as starting index is 0(even)
    return 0;
}
