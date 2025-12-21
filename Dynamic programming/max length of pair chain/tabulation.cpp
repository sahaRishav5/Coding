#include<bits/stdc++.h>
using namespace std;
int n;
/*dp[i]-> LIS ending at index i*/
int solve(vector<vector<int>>& nums){
    vector<int> dp(n,1);
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i][0] > nums[j][1])
                {
                    dp[i] = max(dp[i],dp[j] + 1);
                }
            }
        }
    return *max_element(dp.begin(),dp.end());
}

int main()
{
    vector<vector<int>> nums = {{1, 2}, {7,8}, {4,5}};
    sort(begin(nums), end(nums));// as pairs are to be selected at any order
    n= nums.size();
    cout << solve(nums);
    return 0;
}
