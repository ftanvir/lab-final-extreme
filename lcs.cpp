#include <bits/stdc++.h>
using namespace std;


int lcs(string a, string b, int i, int j, vector<vector<int>>& dp) {

    if(i<=0 || j<=0) {
        return 0;
    }

    if(a[i]==b[j]) {
        return dp[i][j] = 1+lcs(a, b, i-1, j-1, dp);
    }
    if(dp[i][j]!=-1) {
        return dp[i][j];
    }

    return dp[i][j] = max(lcs(a, b, i, j-1, dp), lcs(a, b, i-1, j, dp));
}


int main()
{
    string a, b;
    cin>>a>>b;

    int alen = a.size();
    int blen = b.size();

    vector <vector<int>> dp(alen, vector<int>(blen,-1));

    cout<<"Length of LCS is "<<lcs(a, b, alen-1, blen-1, dp);


    return 0;
}