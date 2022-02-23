#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 1e9

const int ms = 1000;
int dp[ms];
vector<int> change;

int coins(int n){
    dp[0]=0;
    dp[2]=1;
    dp[3]=1;
    dp[4]=2;
    for(int i = 5; i <= n; i++)
        for(int e : change)
            dp[i]= 1 + min(dp[i], dp[i-e]);
    return dp[n];
}

int main(){
    int n, n_coins;
    cin>>n_coins;
    change = vector<int>(n_coins);
    for(int i=0; i<n_coins; i++) cin>>change[i];
    cin>>n;
    for(int i=0; i<=n; i++) dp[i]=INF;
    cout<<coins(n)<<endl;
}