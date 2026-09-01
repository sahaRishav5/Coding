#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    string str = "aabacabx";

    int n = str.size();
    int k = 3;
    int low = 0, high = 0;
    int res = INT_MIN;
    unordered_map<char, int> mp;
    while(high<n){
        mp[str[high]]++;
        while(mp.size()>k){//shrink
            mp[str[low]]--;
            low++;
            if(mp[str[low-1]]==0){
                mp.erase(str[low - 1]);
            }
        }
        if(mp.size()==k){
            int len = high - low + 1;
            res = max(res, len);
        }
        high++;
    }
    cout << res;

    return 0;
}