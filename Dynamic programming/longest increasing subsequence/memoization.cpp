#include<bits/stdc++.h>
using namespace std;
int n;
    int dp[2501][2501];
    int solve(vector<int>& nums,int prev,int idx){
        if(idx>=n) return 0;
        if(prev!= -1  && dp[idx][prev] != -1) return dp[idx][prev];
        int take=0;
        if(prev == -1 || nums[idx]>nums[prev]){
            take = 1 + solve(nums,idx,idx+1);
        }
        int skip = 0 + solve(nums,prev,idx+1);
        if(prev != -1){
            return dp[idx][prev]=max(skip,take);
        }
        return max(skip,take);
}

int main()
{
    vector<int> nums = {10,9,2,5,3,7,101,18};
    n= nums.size();
    memset(dp,-1,sizeof(dp));
    cout<<solve(nums,-1,0);
    return 0;
}
