#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define INF 1e9

vector<vector<int>> distances;
size_t starting_node, N;

int get_distance(int a, int b){
    int start{1}, end{1};
    for(int i = 0; i < N; i++){
        if(start << i == a){
            start = i; break;
        }
    }
    for(int i = 0; i < N; i++){
        if(end << i == b){
            end = i; break;
        }
    }
    return distances[start][end];
}

int TSP(int cur, int _set){
    int cost =INF;
    if(!_set) return get_distance(cur, starting_node);
    for(int i = 0; i < N; i++){
        int bm = 1 << i;
        if(bm & _set)
            cost = min(cost, get_distance(cur, bm) + TSP(bm, _set ^ bm));
    }
    return cost;
}

int main(){
    cin >> N;
    distances = vector<vector<int>>(N, vector<int>(N, INF));
    int n_edges = N * N;
    while(n_edges--){
        size_t start, end, weight;
        cin >> start >> end >> weight;
        start--, end--;
        distances[start][end] = weight;
    }
    cin >> starting_node;
    cout << TSP(1 << (starting_node-1), ((1 << N)-1)^1 << (starting_node-1));
}