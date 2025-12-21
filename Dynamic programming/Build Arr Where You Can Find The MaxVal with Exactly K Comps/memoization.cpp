#include<bits/stdc++.h>
using namespace std;
int N,M,K;
int dp[51][51][101];
int MOD=1e9 + 7;
    int solve(int idx,int search_cost,int maxSoFar){
        if(idx>=N){
            if(search_cost==K){
                return 1;
            }
            return 0;
        }
        if(dp[idx][search_cost][maxSoFar]!=-1) return dp[idx][search_cost][maxSoFar];
        int result=0;
        for(int i=1;i<=M;i++){
            if(i>maxSoFar){
                result = (result+solve(idx+1,search_cost+1,i))%MOD;
            }
            else{
                result = (result+solve(idx+1,search_cost,maxSoFar))%MOD;
            }
        }
        return dp[idx][search_cost][maxSoFar]=result%MOD;
    }

int main()
{
    int n = 2, m = 3, k = 1;
    N=n;
    M=m;
    K=k;
    memset(dp,-1,sizeof(dp));
    cout<<solve(0,0,0);
    return 0;
}
