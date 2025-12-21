#include<bits/stdc++.h>
using namespace std;
int n;
int solve(vector<vector<int>>& nums,int prev,int idx){
        if(idx>=n) return 0;
        int take=0;
        if(prev == -1 || nums[idx][0]>nums[prev][1]){
            take = 1 + solve(nums,idx,idx+1);
        }
        int skip = 0 + solve(nums,prev,idx+1);
        return max(skip,take);
}

int main()
{
    vector<vector<int>> nums = {{1, 2}, {7,8}, {4,5}};
    sort(nums.begin(), nums.end());
    n= nums.size();
    cout<<solve(nums,-1,0);
    return 0;
}
