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

int lcs(int i, int j){
    if(i==size_A || j==size_B) return 0;
    if(dp[i][j]) return dp[i][j];
    else if (A[i]==B[j]) {dp[i][j]=1+lcs(i+1,j+1); return dp[i][j];}
    dp[i][j] = max(lcs(i+1,j),lcs(i,j+1));
    return dp[i][j];
}

int main(){
    tt{
        cin>>A>>B;
        size_A=A.size(); size_B=B.size();
        dp=vector<vector<int>>(size_A+1, vector<int>(size_B+1,0));
        cout<<lcs(0,0)<<"\n";
        A.clear(); B.clear();
    }
}