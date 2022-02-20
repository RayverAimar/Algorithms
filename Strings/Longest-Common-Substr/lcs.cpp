//C++ program to look for the longest common substring between 2 strings - dp approach
#include <iostream>
#include <vector>
#include <string>

using namespace std;
#define tt int testcase; cin>>testcase; while(testcase--)
#define FORN(i,m,n) for(int i = m; i < n; i++)
typedef long long ll;

void lcs(string a, string b){
    int y = a.size()+1, x = b.size()+1;
    vector<vector<int>> arr(y, vector<int>(x, 0));
    FORN(i,0,y){
        FORN(j,0,x){
            if(i==0 || j ==0) continue;
            if(a[i-1] == b[j-1]) arr[i][j] = arr[i-1][j-1]+1;
        }
    }
    int max_len = -1, pos;
    FORN(i,0,y){
        FORN(j,0,x){
            if(arr[i][j]>max_len){
                max_len = arr[i][j];
                pos=i;
            }
        }
    }
    cout<<"Longest Common Substring length is "<<max_len<<"\n";
    FORN(i,pos-max_len,pos) cout<<a[i];
    cout<<"\n";
}   

int main(){
    tt{
        string a, b;
        cin>>a>>b;
        lcs(a,b);
    }    
}