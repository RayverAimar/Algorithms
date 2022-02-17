//C++ program to count how many bits we need to flip to convert A into B
#include <iostream>

using namespace std;

size_t t;

int counting_bits(int a, int b){
    int ans = 0;
    a = a ^ b;
    while(a){
        ans++;
        a = a & (a - 1);
    }
    return ans;
}

int main(){
    cin>>t;
    while(t--){
        int a, b;
        cin>>a>>b;
        cout<<counting_bits(a, b)<<"\n";
    }
}