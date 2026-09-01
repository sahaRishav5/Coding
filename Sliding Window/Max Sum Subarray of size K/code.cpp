#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    vector<int> arr = {1,3,2,2,3,5,1};
    int n = arr.size();
    int k = 3;
    int low = 0, high = k-1;
    int sum = 0;
    for (int i = low; i <= high;i++){
        sum += arr[i];
    }
    int maxSum = INT_MIN;
    while(high<n){
        maxSum = max(maxSum, sum);
        low++, high++;
        if(high==n) break;
        sum -= arr[low - 1];
        sum += arr[high];
    }
    cout << maxSum;
    return 0;
}