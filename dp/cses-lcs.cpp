#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<int> v(n), b(m);

    for(int &x : v) cin >> x;
    for(int &x : b) cin >> x;

    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(v[i-1] == b[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	cout << dp[n][m] << endl;
	vector<int> ans;
	int i = n, j = m;
	while(i > 0 && j > 0){
		if(v[i-1] == b[j-1]){
			ans.push_back(v[i-1]);
			i--;
			j--;
		} else if(dp[i-1][j] > dp[i][j-1]){
			i--;
		} else {
			j--;
		}
	}

	reverse(begin(ans), end(ans));
	for(int x : ans) cout << x << " ";
}   