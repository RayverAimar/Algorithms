#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

#define INF 1e9

size_t n_nodes{0}, n_edges{0};
vector<vector<int>> graph;
vector<int> to_visit, path;
map<int, string> node_names;

int get_n_edges(int n){ return n == 1 ? n : n + get_n_edges(n-1); }

void TSP(int start){ // Force Brute Approach
    size_t N = n_nodes - 1;
    path.resize(N);
    for(int i = 0; i < n_nodes; i++){
        if(i != start) to_visit.push_back(i);
    }
    int min_cost = INF;
    do{
        int cur_cost{0}, cur_node{start};
        for(int neighbor : to_visit){
            cur_cost += graph[cur_node][neighbor];
            cur_node = neighbor;
        }
        cur_cost += graph[cur_node][start]; //Hamiltonian Cycle
        if(min_cost > cur_cost){
            min_cost = cur_cost;
            path.assign(to_visit.begin(), to_visit.end());
        }
    }while(next_permutation(to_visit.begin(), to_visit.end()));
    cout <<"Cost: "<< min_cost<<"\nPath is: "<<node_names[start]<<" ";
    for(int e : path) cout<<node_names[e]<<" ";
    cout<<node_names[start];
}

int main(){
    int src{0};
    cin>>n_nodes;
    n_edges = get_n_edges(n_nodes);
    graph = vector<vector<int>>(n_nodes, vector<int>(n_nodes, -1));
    for(int i = 0; i < n_nodes; i++){
        string name;
        cin >> name;
        node_names.emplace(i, name);
    }
    while(n_edges--){
        size_t start, end, weight;
        cin>>start>>end>>weight;
        start--, end--;
        graph[start][end] = weight;
        graph[end][start] = weight;
    }
    cin>>src;
    TSP(--src);
}