#include<bits/stdc++.h>
using namespace std;
int N,M,K;
int MOD=1e9 + 7;
    int solve(int idx,int search_cost,int maxSoFar){
        if(idx>=N){
            if(search_cost==K){
                return 1;
            }
            return 0;
        }
       
        int result=0;
        for(int i=1;i<=M;i++){
            if(i>maxSoFar){
                result = (result+solve(idx+1,search_cost+1,i))%MOD;
            }
            else{
                result = (result+solve(idx+1,search_cost,maxSoFar))%MOD;
            }
        }
        return result%MOD;
    }

int main()
{
    int n = 2, m = 3, k = 1;
    N=n;
    M=m;
    K=k;
    cout<<solve(0,0,0);
    return 0;
}
