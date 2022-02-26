#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define FORN(i,m,n) for(int i = (m); i < (int)n; i++)
#define INF 1e9

const int ms = 1000;
int dp[ms][ms], n_coins;
vector<int> change;

int coins(int n){
    FORN(i,1,n_coins+1)
        FORN(j,1,n+1)
            dp[i][j]=min(1+dp[i][j-change[i-1]], dp[i-1][j]);
    return dp[n_coins][n];
}

int main(){
    int n;
    cin>>n_coins;
    change = vector<int>(n_coins);
    FORN(i,0,n_coins) cin>>change[i];
    cin>>n;
    FORN(i,0,n_coins+1){
        FORN(j,0,n+1){
            if(i==0) dp[i][j]=INF;
            else if(j==0) dp[i][j]=j;
            else dp[i][j]=0;
        }
    }
    cout<<coins(n)<<endl;
}