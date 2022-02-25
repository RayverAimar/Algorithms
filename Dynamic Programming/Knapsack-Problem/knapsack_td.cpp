#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#define tt int testcase; cin>>testcase; while(testcase--)
#define FORN(i,m,n) for(int i = m; i < n; i++)
#define INF 1e9
typedef long long ll;
using namespace std;

bool desc(pair<float, int> a, pair<float, int> b){ return a>b;}

const int ms = 500;
int n, dp[ms][ms];
vector<int> weight, profit;

int kp(int i, int w){
    if(i<0 || w==0) return 0;
    if(dp[i][w] != -1) return dp[i][w];
    if(w < weight[i]){
         dp[i][w] = kp(i-1, w);
         return dp[i][w];
    }
    dp[i][w]=max(profit[i]+kp(i-1, w-weight[i]), kp(i-1,w));
    return dp[i][w];
}

int main(){
    tt{
        cin>>n;
        weight.resize(n); profit.resize(n);
        FORN(i,0,n) cin>>weight[i];
        FORN(i,0,n) cin>>profit[i];
        int w;
        cin>>w;
        FORN(i,0,n) FORN(j,0,w+1) dp[i][j]=-1;
        cout<<kp(n-1,w)<<endl;
        weight.clear(); profit.clear();
    }
}