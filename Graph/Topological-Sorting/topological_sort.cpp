#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

size_t n_nodes{0}, n_edges{0};
vector<vector<int>> graph;
vector<bool> visited;
vector<int> tp_order;

void dfs(int u){
    visited[u] = true;
    for(int v : graph[u]){
        if(!visited[v]) dfs(v);
    }
    tp_order.push_back(u);
}

void topological_sort(){
    for(int i = 0; i < n_nodes; i++){
        if(!visited[i]) dfs(i);
    }
    reverse(tp_order.begin(), tp_order.end());
    for(int n : tp_order)
        cout << n + 1 << " ";

}
int main(){
    cin>>n_nodes>>n_edges;
    graph.resize(n_nodes, vector<int>());
    visited = vector<bool> (n_nodes, 0);
    while(n_edges--){
        size_t start, end;
        cin>>start>>end;
        start--, end--;
        graph[start].push_back(end);
    }
    topological_sort();
}