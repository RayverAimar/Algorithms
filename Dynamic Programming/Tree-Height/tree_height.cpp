#include <iostream>
#include <vector>
#include <algorithm>

#define tt int testcase; cin>>testcase; while(testcase--)
#define FORN(i,m,n) for(int i = m; i < n; i++)
using namespace std;

vector<bool> visited;
vector<int> dp;
vector<vector<int>> adj;

void dfs(int u){
    visited[u] = true;
    int cur_height=1;
    for(int n : adj[u]){
        if(!visited[n])
        {
            dfs(n);
            cur_height=max(cur_height, dp[n]+1);
        }
    }
    dp[u]=cur_height;
}

int main(){
    tt{
        size_t n_nodes;
        cin>>n_nodes;
        adj=vector<vector<int>>(n_nodes+1, vector<int>());
        FORN(i,0,n_nodes-1){
            size_t start, end;
            cin>>start>>end;
            adj[start].push_back(end);
            adj[end].push_back(start);
        }
        visited = vector<bool>(n_nodes+1, 0);
        dp=vector<int>(n_nodes+1, 0);
        dfs(2);
        cout<<dp[2];
    }
}