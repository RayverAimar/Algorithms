#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

string name;
size_t n_nodes{0}, n_edges{0};
map<int, string> node_names;
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
    for(int i = 0; i < n_nodes; i++)
        cout << node_names[tp_order[i]] << " ";

}
int main(){
    cin>>n_nodes>>n_edges;
    graph.resize(n_nodes, vector<int>());
    visited = vector<bool> (n_nodes, 0);
    for(int i = 0; i < n_nodes; i++){
        cin>>name;
        node_names.insert({i, name});
    }
    while(n_edges--){
        size_t start, end;
        cin>>start>>end;
        start--, end--;
        graph[start].push_back(end);
    }
    topological_sort();
}