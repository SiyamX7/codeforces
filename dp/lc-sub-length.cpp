#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string x = "abcdef";
    string y = "abedef";

    int n = x.length();
    int m = y.length();

    int dp[n+1][m+1];
    memset(dp,-1,sizeof(dp));

    for(int i = 0; i <= n; i++) 
    	dp[i][0] = 0;

    for(int j = 0; j <= m; j++)
    	dp[0][j] = 0;

    int mx = -1;
    int last = -1;

    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= m; j++){
    		if(x[i-1] == y[j-1]){
    			dp[i][j] = 1 + dp[i-1][j-1];
    			mx = max(dp[i][j], mx);
                last = i;
    		} else {
    			dp[i][j] = 0;
    		}
    	}
    }  

    cout << mx << endl;
    cout << x.substr(last-mx, mx) << endl;
}   