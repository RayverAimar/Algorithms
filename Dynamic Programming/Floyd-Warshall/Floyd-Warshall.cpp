#include <iostream>
#include <algorithm>

#define INF 1e9

using namespace std;

struct Graph{
    int n_vertex, **edges;
    //Constructor & Destructor
    Graph(const int N);
    ~Graph();

    //Auxiliar methods
    void InsEdge(int start, int end, int value);
};

Graph::Graph(int N){
    n_vertex = N;
    edges = new int*[N];
    for(int i = 0; i < N; i++){
        edges[i] = new int[N];
        for(int j = 0; j < N; j++) edges[i][j] = INF;
        edges[i][i] = 0;
    }
}

Graph::~Graph(){
    for(int i = 0; i < n_vertex; i++) delete[] edges[i];
    delete[] edges;
}

void Graph::InsEdge(int start, int end, int value){
    edges[start][end] = edges[end][start] =  value;
}

void print(int** edges, int n_vertex){ //Auxiliar function to print matrixes
    for(int i = 0; i < n_vertex; i++){
        for(int j = 0; j < n_vertex; j++){
            if(edges[i][j] == INF) cout<<"INF\t";
            else cout<<edges[i][j]<<"\t";
        }
        cout<<"\n";
    }
}

void FloydWarshall(Graph G){
    int N =  G.n_vertex;
    int **dist = new int*[N];
    for(int i = 0; i < N; i++){
        dist[i] = new int[N];
        for(int j = 0; j < N; j++) dist[i][j] = G.edges[i][j];
    }

    for(int k = 0; k < N; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    cout<<"\n";
    print(dist, N);
}


int main(){
    int n_vertex{0}, n_edges{0};
    cin>>n_vertex>>n_edges;
    Graph G(n_vertex);
    for(int i = 0; i < n_edges; i++){
        int start, end, value;
        cin>>start>>end>>value;
        start--, end--;
        G.InsEdge(start, end, value);
    }
    print(G.edges, G.n_vertex);
    FloydWarshall(G);
}