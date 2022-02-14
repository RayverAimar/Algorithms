#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 1e9

void TSP(int (*graph)[4], int N){
    vector< vector<int> > optimal( 1<<(N-1), vector<int>( N, INF ) ); 
    for (int visited = 1; visited < (1<<(N-1)); ++visited) { 
        for (int cur = 0; cur < (N-1); ++cur) { 
            if (!(visited & 1<<cur)) continue;
            if (visited == 1 << cur) { 
                optimal[visited][cur] = graph[N-1][cur]; 
            } else { 
                int prev_visited = visited ^ 1<<cur; 
                for (int prev = 0; prev < N-1; ++prev) { 
                    if (!(prev_visited & 1<<prev)) continue; 
                    optimal[visited][cur] = min(optimal[visited][cur], graph[cur][prev] + optimal[prev_visited][prev]);
                }
            } 
        } 
    } 
    int ans = INF; 
    for (int last=0; last<N-1; ++last) {
        ans = min(ans, graph[last][N-1] + optimal[ (1<<(N-1))-1 ][last] ); 
    }
    cout<<ans;
}

int main(){
    int arr[][4] = {{0, 10, 15, 20},
                    {5,  0,  9, 10},
                    {6, 13,  0, 12},
                    {8,  8,  9, 0}};
    TSP(arr, 4);
}