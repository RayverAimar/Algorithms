#include <iostream>

using namespace std;

size_t t;

int set_kth_bit(int n, int k_pos){
    int pos = 1 << k_pos;
    return n | pos;
}

int main(){
    cin>>t;
    while(t--){
        int n, k_pos;
        cin>>n>>k_pos;
        cout<<set_kth_bit(n, k_pos)<<"\n";
    }
}