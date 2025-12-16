#include<bits/stdc++.h>
using namespace std;
long long solve(vector<int> arr,int ind,int n){
    if(ind>=n) return 0;
    int pick = arr[ind] + solve(arr, ind + 2, n);
    int notpick = 0 + solve(arr, ind + 1, n);
    return max(pick, notpick);
}
int main()
{
    vector<int> arr = {1, 2, 3, 1};
    int n = arr.size();
    cout << solve(arr, 0,n);
    return 0;
}
