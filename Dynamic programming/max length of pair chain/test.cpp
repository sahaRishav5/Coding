#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<string> words = {"a", "bca", "bda", "bdca", "b", "ba"};
    sort(begin(words), end(words));
    for(auto it: words){
        cout << it<<endl;
    }
    return 0;
}
