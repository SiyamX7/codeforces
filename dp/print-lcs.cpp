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
    memset(dp,0,sizeof(dp));

    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= m; j++){
    		if(x[i-1] == y[j-1]){
    			dp[i][j] = 1 + dp[i-1][j-1];
    		} else {
    			dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    		}
    	}
    }

    cout << dp[n][m] << endl;
    int i , j;
    string ans = "";
    if(dp[n][m]){
    	i = n, j = m;
    }

    while (i > 0 && j > 0) {
    	if(x[i-1] == y[j-1]) {
    		ans += x[i-1];
    		i--;
    		j--;
    	} else if (dp[i-1][j] > dp[i][j-1]){
    		i--;
    	} else {
    		j--;
    	} // if i-1 > i--
          // if j-1 > j--
    }

    reverse(begin(ans), end(ans));
    cout << ans; 

}   