#include <iostream>

using namespace std;

bool is_happy(int n) {
    int s = 0;            
    while (n > 9) {
        while (n != 0) {
            int d = n % 10;
            s += d;
            n /= 10;
        }
        n = s;
        s = 0;
    }
    return (n == 1) ? true : false;
}

int main() {
    //Test-> n = 991 -> 19 -> 10 -> 1 -> 991 is a happy number
    for(int i = 0; i< 1000;i++){
        if (is_happy(i))
            cout << i << " is a happy number" << endl;  
    }
    return 0;
}