#include<bits/stdc++.h>
using namespace std;
int n;
/*dp[i]-> LIS ending at index i*/
int solve(vector<int>& nums){
    vector<int> dp(n,1);
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j] && dp[i] <= dp[j])
                {
                    dp[i] = max(dp[i],dp[j] + 1);
                }
            }
        }
    return *max_element(dp.begin(),dp.end());
}

int main()
{
    vector<int> nums = {10,9,2,5,3,7,101,18};
    n= nums.size();
    cout << solve(nums);
    return 0;
}
