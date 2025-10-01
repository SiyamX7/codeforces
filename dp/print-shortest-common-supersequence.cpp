#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string x = "AXTGY";
    string y = "TGYBF";

    int n = x.length();
    int m = y.length();

    int dp[1001][1001];
    memset(dp, 0, sizeof(dp));

    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= m; j++){
    		if(x[i-1] == y[j-1]){
    			dp[i][j] = 1 + dp[i-1][j-1];
    		} else {
    			dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    		}
    	}
    }

    cout << n + m - dp[n][m] << endl;

    int i = n, j = m;
    string ans = "";
    while(i > 0 && j > 0){
    	if(x[i-1] == y[j-1]){
    		ans += x[i-1];
    		i--;
    		j--;
    	} else if(dp[i-1][j] > dp[i][j-1]){
    		ans += x[i-1];
    		i--;
    	} else {
    		ans += y[j-1];
    		j--;
    	}
    }

    while(i > 0){
    	ans += x[i-1];
    	i--;
    } 

    while(j > 0){
    	ans += y[j-1];
    	j--;
    }
    reverse(begin(ans), end(ans));
    cout << ans << endl;
}