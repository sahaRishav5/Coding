#include<bits/stdc++.h>
using namespace std;
int n;
typedef long long ll;
ll solve(vector<int>& arr,int idx,bool flag){
    if(idx>=n) {
        return 0;
    }
    ll val = arr[idx];
    ll skip = solve(arr, idx + 1, flag);
    if(flag==false){
        val = -val;
    }
    ll pick =  solve(arr, idx + 1, !flag) + val;
    return max(pick, skip);
}

int main()
{
    vector<int> arr = {6,2,1,2,4,5};
    n = arr.size();
    cout << solve(arr,0, true);//true as starting index is 0(even)
    return 0;
}
