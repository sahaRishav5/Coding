#include<bits/stdc++.h>
using namespace std;
int n;
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
int solve(vector<string>& str,int prev,int idx){
    if(idx>=n) return 0;
    int take = 0;
    if(prev == -1 || checkPred(str[prev],str[idx])){
        take = 1 + solve(str, idx, idx + 1);
    }
    int skip = 0 + solve(str, prev, idx + 1);
    return max(skip, take);
}

int main()
{
    vector<string> str = {"xbc","pcxbcf","xb","cxbc","pcxbc","xc" };
    n= str.size();
    sort(str.begin(), str.end(), [](const string& a, const string& b) {
    return a.size() < b.size();
});
    cout << solve(str, -1, 0);
    return 0;
}
