#include <iostream>
#include <algorithm>
#include <vector>

#define INF 1e9
using namespace std;

const int ms = 1000;
vector<int> change;
int dp[ms];

int coins(int n){
    if(dp[n]<0){
        dp[n] = INF;
        for(int e : change)
            if(n-e>=0)
                dp[n] = min(dp[n], 1 + coins(n-e));
    }
    return dp[n];
}

int main(){
    int n, n_coins;
    cin>>n_coins;
    change = vector<int>(n_coins);
    for(int i=0; i<n_coins; i++) cin>>change[i];
    cin>>n;
    for(int i=0; i<=n; i++) dp[i]=-1;
    dp[0]=0;
    cout<<coins(n)<<endl;
}