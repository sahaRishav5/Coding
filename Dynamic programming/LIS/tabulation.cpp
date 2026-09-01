#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {10,2,6,5,4,7,9};
    int n = arr.size();
    vector<int> res(n);
    for (int i = 0; i < n;i++){
        res[i] = 1;
        for (int j = 0; j < i;j++){
            if(arr[j]<arr[i]){
                res[i] = max(res[i], res[j] + 1);
            }
        }
    }
    int ans = 0;
    for(auto val:res){
        ans = max(ans, val);
    }
    cout << ans;
    return 0;
}