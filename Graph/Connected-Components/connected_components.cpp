#include <iostream>
#include <vector>

using namespace std;

vector<vector<size_t>> graph;
size_t n_nodes{0}, n_edges{0};
vector<bool> visited;

void dfs(int u){
    visited[u]= true;
    for(int neighbor : graph[u]){
        if(!visited[neighbor])
            dfs(neighbor);
    }
}

int connected_components(){
    int ans{0};
    visited = vector<bool>(n_nodes, 0);
    for(int i = 0; i < n_nodes; i++){    
        if(!visited[i]){
            dfs(i);
            ans++;
        }    
    }
    return ans;
}

int main(){
    cin>>n_nodes>>n_edges;
    graph = vector<vector<size_t>>(n_nodes, vector<size_t>());
    while(n_edges--){
        size_t start, end;
        cin>>start>> end;
        start--, end--;
        graph[start].push_back(end);
        graph[end].push_back(start);
    }
    cout << connected_components();
}