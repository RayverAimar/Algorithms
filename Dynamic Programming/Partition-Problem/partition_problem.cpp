#include <iostream>
#include <vector>

using namespace std;
#define tt int testcase; cin>>testcase; while(testcase--)
#define FORN(i,m,n) for(int i = m; i < n; i++)
typedef long long ll;
int arr[100], n;


void print(int bm){
    vector<int> s1, s2;
    FORN(i,0,n) 
        bm&1<<i ? s1.push_back(arr[i]) : s2.push_back(arr[i]);
    for(int a : s1) cout<<a<<" ";
    cout<<"- ";
    for(int a : s2) cout<<a<<" ";
    cout<<"\n";
}

bool partition(int sum){
    bool ans=false;
    int total_sum{0};
    FORN(i,0,n) total_sum+=arr[i];
    if(total_sum%2) return 0;
    FORN(bm,1,1<<n){
        int s1{0}, s2{0};
        FORN(i,0,n){
            if(bm & 1<<i) s1+=arr[i];
            else s2+=arr[i];
        }
        if(s1 == s2){
            print(bm);
            ans = true;
        }
    }
    return ans;
}

int main(){
    tt{
        cin>>n;
        FORN(i,0,n) cin>>arr[i];
        int sum;
        cin>>sum;
        if(partition(sum)) cout<<"YES";
        cout<<"\n";
    }
}