#include <bits/stdc++.h>
using namespace std;
#define  ll long long 

int gg(vector<vector<int>> &dp, vector<int> &v, int target, int n){
	if(target == 0) return 1;
	if(n == 0) return 0;

	if(dp[n][target] != -1) return dp[n][target];

	if(v[n-1] > target){
		return dp[n][target] = gg(dp, v, target, n-1);
	} else {
		return dp[n][target] = (gg(dp, v, target, n-1) || gg(dp, v, target- v[n-1], n-1));
	}
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n ; cin >> n;

    if(n % 2 == 0) {
    	cout << "NO";
    } else {
    	ll sum = 0;
    	sum = n * (n + 1) / 2;
    	vector<int> v;
    	for(int i = 1; i <= n; i++){
    		v.push_back(i);
    	}

    	int target = sum / 2;

    	vector<vector<int>> dp(n+1, vector<int> (target+1, -1));
    	gg(dp, v, target, n);

    	for(int i = 0; i <= n; i++){
    		for(int j = 0; j <= target; j++){
    			cout << dp[i][j] << " ";

    		} cout << endl;
    	}
    }
}   