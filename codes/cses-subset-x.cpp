#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;

int count(vector<int> &v, int n, int target){
	if(target == 0) return 1;
	if(n == 0) return 0;

	if(dp[n][target] != -1) return dp[n][target];

	int take = 0;
	if(v[n-1] <= target){
		take = count(v, n-1, target - v[n-1]);
	}

	int notTake = count(v, n-1, target);

	return dp[n][target] = take + notTake;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for(int &i : v) cin >> i;

    dp.assign(n+1, vector<int> (x+1, -1));
	cout << count(v, n, x);
	
}   