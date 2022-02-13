#include <iostream>

using namespace std;

void init_arr(int* arr, size_t n){
    int a;
    for(int i = 0; i < n; i++){
        cin>>a;
        arr[i] = a;
    }
}

void insertion_sort(int* arr, size_t n){
    for(int i = 0; i < n; i++){
        int key = arr[i], j = i - 1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
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
    insertion_sort(arr, n);
    print(arr, n);
}