#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define INF 1e9

vector<vector<int>> distances;
size_t starting_node, N;

int get_distance(int a, int b){
    int start{1}, end{1};
    for(int i = 0; i < 4; i++){
        start <<= i;
        if(start == a){
            start = i;
            break;
        }
    }
    for(int i = 0; i < 4; i++){
        end <<= i;
        if(end == b){
            end = i;
            break;
        }
    }
    return distances[start][end];
}

int TSP(int cur_node, int to_visit){
    int cost = INF;
    if(!to_visit){
        return get_distance(cur_node, starting_node);
    }
    for(int i = 0; i < 4; i++){
        int f = 1 << i; //0001 0010 0100 1000
        cost = min(cost, get_distance(cur_node, f) + TSP(f, to_visit ^ f));
    }
    return cost;
}


int main(){
    cin >> N;
    distances = vector<vector<int>>(N, vector<int>(N,0));
    int n_edges = N * N;
    while(n_edges--){
        size_t start, end, weight;
        start--, end--;
        cin >> start >> end >> weight;
    }
    cin >> starting_node;
    cout<<TSP(starting_node, 7); //0001 - 0111;
    
}