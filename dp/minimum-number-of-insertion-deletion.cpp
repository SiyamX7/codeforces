#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string a = "heap";
    string b = "pea";
    // convert a to b
    // deletion = a.length() - lcs
    // insertion = b.length - lcs
    // ans = insertion + deletion
    int n = a.length();
    int m = b.length();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= m; j++){
    		if(a[i-1] == b[j-1]){
    			dp[i][j] = 1 + dp[i-1][j-1];
    		} else {
    			dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    		}
    	}
    }

	int ans = n + m - 2 * dp[n][m];
	cout << ans;
}   