#include<bits/stdc++.h>
using namespace std;
//dp[i] means max stolen money upto house 
long long solve(vector<int>& arr,int start,int end){
    vector<int> dp(end - start + 1, 0);
    dp[0] = arr[start];
    for (int i = 1; i <= (end-start);i++){
        int pick = arr[start+i] + ((i>1)?dp[i - 2]:0);
        int notpick = 0 + dp[i - 1];
        dp[i] = max(pick, notpick);
    }
    return dp[end-start];
}
int main()
{
    vector<int> arr = {1, 2, 3, 1,8};
    int n = arr.size();
    int case1 = solve(arr, 0,n-2);//[0...(n-2)]
    int case2 = solve(arr, 1, n-1);//[1...(n-1)]
    cout << max(case1, case2);
    return 0;
}
