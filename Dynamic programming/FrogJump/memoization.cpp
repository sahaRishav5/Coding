#include<bits/stdc++.h>
using namespace std;
int func(int i,int n,vector<int> &arr){
    if(i>=n-1){
        return 0;
    }
    
    int c1 =(i+1<n)? abs(arr[i] - arr[i + 1]) + func(i + 1, n, arr):INT_MAX;
    int c2 =(i+2<n)? abs(arr[i] - arr[i + 2]) + func(i + 2, n, arr):INT_MAX;
    return min(c1,c2);
}
int main(){
    vector<int> arr = {10,20,30,10};
    int n = arr.size();
    cout << func(0, n, arr);

    return 0;
}