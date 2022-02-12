#include <iostream>

using namespace std;

typedef long long ll;

ll fib(int n){
    ll fibs[3];
    fibs[0] = 0;
    fibs[1] = 1;
    for(ll i = 2; i <= n; i++){
        fibs[2] = fibs[1] + fibs[0];
        fibs[0] = fibs[1];
        fibs[1] = fibs[2]; //Last current element of the sequence
    }
    return fibs[1];
}

int main(){
    int n{0};
    cin >> n;
    cout << fib(n);
}