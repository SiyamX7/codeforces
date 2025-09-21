#include <bits/stdc++.h>
using namespace std;
using  ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<int> v = {1,2,7};
    int n = size(v);
    int sum = 0;
    for(int i : v) {
    	sum += i;
    }

    vector<int> dp(sum+1, 0);
    dp[0] = 1;

    for(int i = 0; i < n; i++){
    	for(int j = sum; j >= v[i]; j--){
    		dp[j] = dp[j] + dp[j - v[i]];
    	}
    }

    // there are 2 sum, s1 and s2. s1 + s2 = sum;
    // s2 = sum - s1
    // we have to minimize s2 - s1
    //
    // now s2 - s1 = (sum - s1) - s1
    // 			= sum - 2*s1

    int mn = INT_MAX;
    for(int i = 0; i <= sum / 2; i++){
    	if(dp[i] != 0)
    		mn = min(mn, (sum - 2 * i));
    }

    cout << mn;
}   