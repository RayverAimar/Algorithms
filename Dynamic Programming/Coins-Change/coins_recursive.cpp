#include <iostream>
#include <algorithm>
#include <vector>

#define INF 1e9
using namespace std;

vector<int> change;

int coins(int n){
    if (n < 0) return INF;
    if (!n) return n;
    int min = INF;
    for(int e : change){
        int ans = 1 + coins(n-e);
        if(min>ans) min = ans;
    }
    return min;
}

int main(){
    int n, n_coins;
    cin>>n_coins;
    change = vector<int>(n_coins);
    for(int i=0; i<n_coins; i++) cin>>change[i];
    cin>>n;
    cout<<coins(n)<<endl;
}