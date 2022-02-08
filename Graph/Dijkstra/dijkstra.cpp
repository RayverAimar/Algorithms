#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

#define INF 1e9

namespace graph{

void InsEdge(vector<vector<pair<int,int>>> &nodes, int start, int end, int weight){
    nodes[start].push_back(make_pair(end, weight));
    nodes[end].push_back(make_pair(start, weight));
}

void dijkstra(vector<vector<pair<int,int>>> &nodes, int start, int end){
    int N = nodes.size();
    vector<pair<int, int>> dist(N, {INF, -1});
    vector<int> shortest_path;
    vector<bool> visited(N, 0);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
    dist[start].first = 0;
    pq.push(make_pair(0,start));
    while(!pq.empty()){
        int cur_node = pq.top().second;
        pq.pop();
        if(visited[cur_node]) continue;
        visited[cur_node] = 1;
        for(auto edge : nodes[cur_node]){
            if(dist[cur_node].first + edge.second < dist[edge.first].first){
                dist[edge.first].first = dist[cur_node].first + edge.second;
                dist[edge.first].second = cur_node;
                pq.push(make_pair(dist[edge.first].first, edge.first));
            }
        }
    }
    stack<int> s;
    int pos = end;
    do{
        s.push(pos);
        pos = dist[pos].second; 
    }while(pos != -1);
    while(!s.empty()){
        shortest_path.push_back(s.top() + 1);
        s.pop();
    }
    cout << "Shortest distance from "<< ++start <<" to "<< end + 1 <<" is "<<dist[end].first<<"\n";
    cout <<"Path is: ";
    for(int i = 0; i < shortest_path.size(); i++)
        cout<<shortest_path[i]<<" ";

} //dijkstra

} //namespace graph

int main(){
    int n_vertex, n_edges, a, b;
    cin>>n_vertex>>n_edges;
    vector<vector<pair<int, int>>> nodes(n_vertex, vector<pair<int, int>>());
    while(n_edges--){
        int start, end, weight;
        cin>>start>>end>>weight;
        graph::InsEdge(nodes, --start, --end, weight);
    }
    cin>>a>>b;
    graph::dijkstra(nodes, --a, --b);
}