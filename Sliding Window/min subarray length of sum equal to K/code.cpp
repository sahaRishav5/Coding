#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    vector<int> arr = {1,3,2,2,3,5,1};
    int n = arr.size();
    int target = 6;
    int sum = 0, res = INT_MAX, high = 0, low = 0;
    while(high<n){
        sum += arr[high];
        while(sum>target)//fire the employees untill no more advancement of the work
        {
            sum -= arr[low];
            low++;
        }
        if(sum==target){
            res = min(res, (high - low + 1));
        }
        high++;
    }
    return 0;
}