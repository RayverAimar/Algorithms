#include <iostream>

using namespace std;

size_t t;

int counting_set_bits(int n){
    int ans = 0;
    while(n){
        ans++;
        n&=(n-1);
    }
    return ans;
}

int hamming_distance(int a, int b){
    return counting_set_bits(a^b);
}

int hamming_distance(string a, string b){
    int n = a.size();
    if(n != b.size()) return -1;
    int ans = 0;
    for(int i = 0; i < n; i++)
        ans += (a[i] != b[i]);
    return ans;
}

int main(){
    cin>>t;
    while(t--){
        int a, b;
        cin>>a>>b;
        cout<<hamming_distance(a,b)<<"\n";
    }
    cin>>t;
    while(t--){
        string a, b;
        cin>>a>>b;
        cout<<hamming_distance(a,b)<<"\n";
    }
}