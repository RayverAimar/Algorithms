#include <iostream>

using namespace std;

size_t t;

int num_of_set_bits(int n){
    int ans{0};
    while(n){
        ans++;
        n = n & (n - 1);
    }
    return ans;
}

int main(){
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<num_of_set_bits(n)<<"\n";
    }
}