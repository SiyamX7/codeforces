#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<int> v {2,4,6,3,9,13,18};
    int sum = 21;
    int n = v.size();

    vector<vector<bool>> dp(n+1, vector<bool> (sum+1, false));

    for(int i = 0; i <= n; i++) dp[i][0] = true;

    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= sum; j++){ // i = n, j = sum
    		if(v[i-1] <= j) {
    			dp[i][j] = (dp[i-1][j - v[i-1]] || dp[i-1][j]);
    		} else {
    			dp[i][j] = dp[i-1][j];
    		}
    	}
    }

    cout << dp[n][sum];
}