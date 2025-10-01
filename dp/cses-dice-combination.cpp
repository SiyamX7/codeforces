#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    vector<int> dp(n+1, 0);
    dp[0] = 1;

    // dice combination er order matter kore, tai j outer loop e
    for(int j = 1; j <= n; j++){
    	for(int i = 1; i <= 6; i++){
    		if(j >= i)
    			dp[j] = (dp[j] + dp[j-i]) % mod;
    	}
    }

    // for(int i : dp){
    // 	cout << i << " ";
    // }

    cout << dp[n];
}   