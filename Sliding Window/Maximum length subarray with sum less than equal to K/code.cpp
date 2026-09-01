#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    vector<int> arr = {1,3,2,2,3,5,1};
    int n = arr.size();
    int target = 6;
    int sum = 0, res = INT_MIN, high = 0, low = 0;
    while(high<n){
        sum += arr[high];
        while(sum>target){
            sum -= arr[low];
            low++;
        }
        res = max(res, (high - low + 1));//either less than or equal to
        high++;
    }
    cout << res;
    return 0;
}