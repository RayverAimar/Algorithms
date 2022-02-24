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

int n;
vector<int> weight, profit;

void kp(int w){
    int w_size = weight.size()+1;
    vector<vector<int>> dp(w_size, vector<int>(w+1, 0));
    FORN(i,1,w_size){
        FORN(j,1,w+1){
            if(j<weight[i-1]){
                dp[i][j]=dp[i-1][j]; continue;
            };
            dp[i][j]=max(dp[i-1][j], dp[i-1][j-weight[i-1]]+profit[i-1]);
        }
    }
    int ans{0};
    int p = w_size-1, j = w;
    while(p){
        bool found=false;
        for(int i=0; i<j+1; i++)
            if(dp[p-1][i]==dp[p][j]) found = true;
        if(!found){
            ans+=profit[p-1];
            j-=weight[p-1];
        } 
        p--;
    }
    cout<<"Max Profit: "<<ans<<endl;
}

int main(){
    tt{
        cin>>n;
        weight.resize(n); profit.resize(n);
        FORN(i,0,n) cin>>weight[i];
        FORN(i,0,n) cin>>profit[i];
        int w;
        cin>>w;
        kp(w);
        weight.clear(); profit.clear();
    }
}