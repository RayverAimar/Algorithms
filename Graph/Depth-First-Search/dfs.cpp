#include <iostream>
#include <vector>

using namespace std;

namespace graph{

void InsEdge(vector<vector<size_t>>& nodes, size_t start, size_t end){
    nodes[start].push_back(end);
    //nodes[end].push_back(end);
}

void visit(const vector<vector<size_t>> &nodes, size_t cur_node, vector<bool>& visited){
    cout << cur_node + 1 << " ";
    visited[cur_node] = true;
    for(auto m_nodes : nodes[cur_node]){
        if(!visited[m_nodes])
            visit(nodes, m_nodes, visited);
    }
}

void dfs(const vector<vector<size_t>> &nodes, size_t start){
    size_t N = nodes.size();
    vector<bool> visited(N, 0);
    visit(nodes, --start, visited);
}

} //namespace graph

int main(){
    size_t n_vertex{0}, n_edges{0};
    cin >> n_vertex >> n_edges;
    vector<vector<size_t>> nodes(n_vertex, vector<size_t>());
    while(n_edges--){
        size_t start{0}, end{0};
        cin >> start >> end;
        graph::InsEdge(nodes, --start, --end);
    }
    graph::dfs(nodes, 1);
}