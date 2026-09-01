#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    vector<int> arr = {1,3,2,2,3,5,1};
    int n = arr.size();
    int target = 6;
    int sum = 0, res = INT_MAX;
    int high = 0, low = 0;
    while(high<n){
        sum += arr[high];
        while(sum>=target)//fire the employees untill no more advancement of the work
        {
            res = min(res, (high - low + 1));
            sum -= arr[low];
            low++;
        }
        high++;
    }
    cout << res;
    return 0;
}
