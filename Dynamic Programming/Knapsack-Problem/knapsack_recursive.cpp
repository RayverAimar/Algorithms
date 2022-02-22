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

int n;
vector<int> weight, profit;

int knapsack(int i, int W){
    if(i == n || W == 0) return 0;
    if(W < weight[i]) return knapsack(i+1, W);
    else return max(profit[i] + knapsack(i+1, W-weight[i]), knapsack(i+1,W));
}

int main(){
    tt{
        cin>>n;
        weight = profit = vector<int>(n);
        FORN(i,0,n) cin>>weight[i];
        FORN(i,0,n) cin>>profit[i];
        int total_weight;
        cin>>total_weight;
        cout<<knapsack(0,total_weight);
    }
}