#include <iostream>

using namespace std;

typedef long long ll;

ll *fibs;

void init_arr(const int n){
    fibs = new ll[n];
    for(int i = 0; i <= n; i++) fibs[i] = -1;
}

ll fib(int n){
    if(fibs[n] == -1){
        if(n == 0 || n == 1){
            fibs[n] = n;
        }
        else{
            fibs[n] = fib(n - 1) + fib(n - 2);
        }
    }
    return fibs[n];
}

int main(){
    int n;
    cin>>n;
    init_arr(n);
    cout<<fib(n);
}