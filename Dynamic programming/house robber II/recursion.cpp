#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> arr,int start,int end){
    if(start>=end) return 0;
    int pick = arr[start] + solve(arr, start + 2, end);
    int notpick = 0 + solve(arr, start + 1, end);
    return max(pick, notpick);
}
/* if 0th index selected ,then (n-1)th wont be selected
and vice versa */
int main()
{
    vector<int> arr = {1, 2, 3, 1};
    int n = arr.size();
    int case1 = solve(arr, 0,n-1);//[0...(n-2)]
    int case2 = solve(arr, 1, n);//[1...(n-1)]
    cout << max(case1, case2);
    return 0;
}
