#include <iostream>

using namespace std;

void binarizar(int number) {
    int remainder, binary = 0, var = 1;
    do {
        remainder = number % 2;
        number = number / 2;
        binary = binary + (remainder * var);
        var = var * 10;
    } while (number > 0);
    cout<<binary<<endl;
}

void binarizar_2(int number) {
    int num_bits = 0;
    char bit_string[50];
    do {
        bool bit = number & 1;
        if (bit) bit_string[num_bits++] = '1';
        else bit_string[num_bits++] = '0';
        number >>= 1;
    } while (number > 0);

    while (num_bits >= 0)
        cout << bit_string[num_bits--];
    cout << endl;
}

int main() {
    int number;
    cin>>number;
    binarizar(number);
    binarizar_2(number);
    return 0;
}