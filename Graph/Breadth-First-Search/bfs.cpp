#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

size_t n_nodes{0}, n_edges{0}; 
vector<vector<int>> graph;
vector<bool> visited;

void bfs(int start){
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()){
        int cur_node = q.front();
        q.pop();
        cout << cur_node + 1 <<" ";
        for(auto neighbour : graph[cur_node]){
            if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour] = true;                       
            }
        }
    }
}

int main(){
    int starting_node{-1};
    cin>>n_nodes>>n_edges;
    graph = vector<vector<int>>(n_nodes);
    visited = vector<bool>(n_nodes, 0);
    while(n_edges--){
        int start, end;
        cin>>start>>end;
        start--, end--;
        graph[start].emplace_back(end);
        graph[end].emplace_back(start);
    }
    cin>>starting_node;
    bfs(--starting_node);
}