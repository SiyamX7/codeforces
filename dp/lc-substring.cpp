#include <bits/stdc++.h>
#include <cstring>
using namespace std;

int dp[1001][1001];
int mx = -1;

int lcsub(string &x, string &y, int n, int m){
	if(n == 0 || m == 0) return 0;

	if(dp[n][m] != -1)
		return dp[n][m];

	if(x[n-1] == y[m-1]){
		dp[n][m] = 1 + lcsub(x,y,n-1,m-1);
		mx = max(mx, dp[n][m]);
		return dp[n][m];
	} else {
		dp[n][m] = 0;
		lcsub(x,y, n-1, m);
		lcsub(x,y, n, m-1);
		return dp[n][m];
	}
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp,-1,sizeof(dp));
    
    string x = "abcdef";
    string y = "abedef";

    int n = x.length();
    int y = y.length();
}   