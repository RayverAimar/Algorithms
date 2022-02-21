//C++ program to solve 1/0 knapsack problem - greedy method
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#define tt int testcase; cin>>testcase; while(testcase--)
#define FORN(i,m,n) for(int i = m; i < n; i++)
#define INF 1e9
typedef long long ll;
using namespace std;

bool desc(pair<float, int> a, pair<float, int> b){ return a>b;}

vector<int> weight, profit;

void knapsack(int total_weight){
    float count{0};
    int n = weight.size();
    vector<pair<float,int>> opt;
    vector<bool> visited(n, 0);
    FORN(i,0,n) opt.emplace_back((float)profit[i]/weight[i], i);
    sort(opt.begin(), opt.end(), desc);
    int i = 0;
    while(total_weight-weight[opt[i].second]>=0 && i < n){
        total_weight-=weight[opt[i].second];
        visited[opt[i].second]=1;
        i++;
    }
    FORN(i,0,n) cout<<visited[i]*weight[i]<<" ";
    cout<<endl;
    FORN(i,0,n) count+=(visited[i]*profit[i]);
    cout<<count<<endl;
}

int main(){
    tt{
        int n;
        cin>>n;
        weight = profit = vector<int>(n);
        FORN(i,0,n) cin>>weight[i];
        FORN(i,0,n) cin>>profit[i];
        int total_weigth;
        cin>>total_weigth;
        knapsack(total_weigth);
    }
}