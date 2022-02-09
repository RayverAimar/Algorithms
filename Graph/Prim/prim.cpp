//C++ program to implement Prim's Algorithm
#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

void prim(vector<vector<pair<int, int>>>& graph, int start){
    size_t N = graph.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> visited(N, 0);
    vector<int> path;
    int cost{0};
    pq.push({cost, --start});
    while(!pq.empty()){
        int cur_dist = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();
        if(visited[cur_node]) continue;
        visited[cur_node] = true;
        cost += cur_dist;
        path.push_back(cur_node);
        for(auto neighbour : graph[cur_node]){
            if(!visited[neighbour.second]) pq.push(neighbour);
        }
    }
    cout << "MST's weight from node "<< ++start << " is: "<<cost<<"\n";
    cout << "Path for MST from node "<< start << " is: ";
    for(int i = 0; i < N; i++) cout << path[i] + 1 <<" ";
}

int main(){
    size_t n_nodes{0}, n_edges{0};
    cin>>n_nodes>>n_edges;
    vector<vector<pair<int, int>>> graph(n_nodes, vector<pair<int, int>>());
    while(n_edges--){
        int start, end, weight;
        cin>>start>>end>>weight;
        --start, --end;
        graph[start].push_back({weight, end});
        graph[end].push_back({weight, start});
    }
    prim(graph, 1);
}