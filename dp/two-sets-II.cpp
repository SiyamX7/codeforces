#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9 + 7;

void solve(){
	int n; 
	cin >> n;
	int sum = (n * (n+1)) / 2;

	if(sum % 2 != 0){
		cout << 0 ;
		return;
	}

	int t = sum / 2;

	vector<int> dp(t+1, 0);
	dp[0] = 1;


	for(int i = 1; i <= n; i++){
		if(i > t) continue;
		for(int j = t; j >= i; j--){
			dp[j] = (dp[j] + dp[j - i]) % mod;
		}
	}

	int ans = dp[t];
	int inverse2 = (mod + 1) / 2; // 2^-1 using fermats little theorem

	ans = (ans * inverse2) % mod;  

	cout << ans;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
}   