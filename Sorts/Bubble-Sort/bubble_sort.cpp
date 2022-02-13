#include <iostream>
#include <algorithm>

using namespace std;

void init_arr(int* arr, size_t n){
    int a;
    for(int i = 0; i < n; i++){
        cin>>a;
        arr[i] = a;
    }
}

void Bubble_Sort(int *arr, size_t _size){
    for(int i = 0; i < _size - 1; i++){
        for(int j = 0; j < _size - i - 1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }       
    }
}

void print(int* arr, size_t _size){
    for(int i = 0; i < _size; i++)
        cout << arr[i] << " ";
    cout<<endl;
}

int main(){
    int* arr;
    size_t n;
    cin>>n;
    arr = new int[n];
    init_arr(arr, n);
    Bubble_Sort(arr, n);
    print(arr, n);
}