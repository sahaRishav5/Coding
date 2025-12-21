#include<bits/stdc++.h>
using namespace std;
int n;
/*dp[i]-> LIS ending at index i*/

bool checkPred(string prev,string curr){
   int m=prev.length();
   int n=curr.length();
   if(m>=n || n-m!=1){
    return false;
   }
   int i=0,j=0;
   while(i<m && j<n){
    if(prev[i]==curr[j]){
        i++;
    }
    j++;
   }
   return i==m;
}
int solve(vector<string>& str){
    vector<int> dp(n+1,1);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(checkPred(str[j],str[i])){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
    }
    return *max_element(begin(dp),end(dp));
}

int main()
{
    vector<string> str = {"xbc","pcxbcf","xb","cxbc","pcxbc","xc" };
    n= str.size();
    sort(str.begin(), str.end(), [](const string& a, const string& b) {
    return a.size() < b.size();
    });
    cout<<solve(str);
    return 0;
}
