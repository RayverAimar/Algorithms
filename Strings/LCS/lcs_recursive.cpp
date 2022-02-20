#include <iostream>
#include <string>
#include <algorithm>

#define tt int testcase; cin>>testcase; while(testcase--)
#define FORN(i,m,n) for(int i = m; i < n; i++)
using namespace std;

string A, B;
int size_A, size_B;

int lcs(int i, int j){
    if(i == size_A || j == size_B) return 0;
    if(A[i]==B[j]) return 1 + lcs(i+1,j+1);
    return max(lcs(i+1,j), lcs(i,j+1));
}

int main(){
    tt{
        cin>>A>>B;
        size_A = A.size(); size_B = B.size();
        cout<<lcs(0,0)<<"\n";
        A.clear(); B.clear();
    }
}