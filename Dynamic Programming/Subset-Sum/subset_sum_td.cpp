#include <iostream>
#include <vector>

using namespace std;

#define FORN(i,m,n) for(int i = (m); i < int(n); i++)
typedef long long ll;

size_t t;
int arr[100], stk[100], top=-1, n;

bool subset_sum(int i, int sum){
    if(!sum){
        FORN(i,0,top+1) cout<<stk[i]<<" ";
        cout<<"\n";
        return true;
    }
    if(i >= n) return false;
    stk[++top] = arr[i];
    bool on = subset_sum(i+1, sum-arr[i]);
    --top;
    bool off = subset_sum(i+1, sum);
    return on || off;
}

int main(){
    cin>>t;
    while(t--){
        cin>>n;
        FORN(i,0,n) cin>> arr[i];
        int sum;
        cin>>sum;
        cout<<(subset_sum(0, sum) ? "YES" : "NO")<<endl;
    }
}