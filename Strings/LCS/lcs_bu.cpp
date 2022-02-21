#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#define tt int testcase; cin>>testcase; while(testcase--)
#define FORN(i,m,n) for(int i = m; i < n; i++)
#define INF 1e9
using namespace std;

string A, B;
int size_A, size_B;
vector<vector<int>> dp;

void lcs(){
    FORN(i,1,size_A+1){
        FORN(j,1,size_B+1){
            if(A[i-1]==B[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    }
    int i=size_A, j=size_B, idx = dp[size_A][size_B];
    char *str = new char[idx+1];
    str[idx]='\0';
    while(i > 0 && j > 0){
        if(A[i-1]==B[j-1]){
            str[--idx]=A[i-1];
            --i, --j;
        }
        else if(dp[i-1][j]>dp[i][j-1]) --i;
        else --j;
    }
    cout<<str<<endl;
}

int main(){
    tt{
        cin>>A>>B;
        size_A=A.size(); size_B=B.size();
        dp=vector<vector<int>>(size_A+1, vector<int>(size_B+1, 0));
        lcs();
    }
}