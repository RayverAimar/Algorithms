#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

size_t n_nodes{0}, n_edges{0};

int root(int i, int* parent){ //Search for the parent whose tag is its position
    while(parent[i] != i){
        parent[i] = parent[parent[i]];
        i = parent[i];
    }
    return i;
}

void kruskal(vector<pair<int , pair<int, int>>>& edges){
    int min_weight{0}, *parent = new int[n_nodes];
    size_t N = edges.size();
    for(int i = 0; i < n_nodes; i++) parent[i] = i;
    for(int i = 0; i < N; i++){
        int start = edges[i].second.first, end = edges[i].second.second,
            root_start = root(start, parent), root_end = root(end, parent);
        if(root_start != root_end){
            min_weight += edges[i].first;
            parent[root_start] = parent[root_end];
        }
    }
    cout << "MST weight made by Kruskal Algorithm is: " << min_weight;
}

int main(){
    vector<pair<int, pair<int, int>>> edges;
    cin>>n_nodes>>n_edges;
    while(n_edges--){
        size_t start, end, weight;
        cin>>start>>end>>weight;
        start--, end--;
        edges.push_back({weight, {start, end}});
    }
    sort(edges.begin(), edges.end());
    kruskal(edges);
}