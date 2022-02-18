#include <iostream>

using namespace std;

size_t t;

int trailing_zeros(int n){
    int ans = 0;
    for(int i = 5; n/i >= 1; i*=5)
        ans += n/i;
    return ans;
}

int main(){
    cin>>t;
    while(t--){
        size_t n;
        cin>>n;
        cout<<trailing_zeros(n)<<endl;
    }    
}

