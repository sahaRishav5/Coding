#include<bits/stdc++.h>
using namespace std;

int fun(int i,int j,int n,int m){
    if(i==n-1 && j==m-1){
        return 1;
    }
    if(i==n || j==m){
        return 0;
    }
    return fun(i + 1, j, n, m) + fun(i, j + 1, n, m);
}

int main(){
    int n = 3, m = 2;
    cout << fun(0, 0, n, m);
    return 0;
} 