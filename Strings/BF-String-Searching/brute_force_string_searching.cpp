#include <iostream>

using namespace std;

size_t t;

int solve(string t, string pattern){
    size_t t_size = t.size(), pattern_size = pattern.size();
    int idx = -1;
    if(pattern_size <= t_size){
        for(int i = 0; i < t_size - pattern_size + 1; i++){
            string p = t.substr(i, pattern_size);
            if(p == pattern){
                idx = i;
                break;
            }
        }
    }
    return idx;
}

int main(){
    cin>>t;
    while(t--){
        string a, b;
        cin>>a>>b;
        cout<<solve(a,b)<<endl;
    }
}