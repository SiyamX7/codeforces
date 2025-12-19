#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<int> v {5,12,1,5};
    int n = v.size();
    int sum = 0;

    for(int &x : v) sum += x;

    if(sum % 2 == 1) {
    	cout << "Impossible" << endl;
    	return 0;
    }

    int target = sum / 2;
    vector<vector<bool>> dp(n+1, vector<bool>(target+1, false));

    for(int i = 0; i < n; i++) dp[i][0] = true;

    // i == n, j == target

    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= target; j++){
    		if(v[i-1] <= j){
    			dp[i][j] = dp[i-1][j] || dp[i-1][j - v[i-1]];
    		} else {
    			dp[i][j] = dp[i-1][j];
    		}
    	}
    }

    if(dp[n][target]) {
    	cout << "Possible" << endl;
    } else {
    	cout << "Impossible" << endl;
    }
}