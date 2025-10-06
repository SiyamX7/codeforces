#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int mcm(vector<int> &v, int i , int j){
	if(i == j) return 0;

	if(dp[i][j] != -1) return dp[i][j];

	int ans = INT_MAX;

	for(int k = i; k < j; k++){
		int left  = mcm(v, i, k);
		int right = mcm(v, k+1, j); 
		int cost = v[i-1] * v[k] * v[j];
		
		int tempCost = left + right + cost;
		ans = min(tempCost, ans);
	}
	return dp[i][j] = ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp,-1,sizeof(dp));
    
    vector<int> v = {10,30,5,60};
    cout << mcm(v, 1, v.size()-1) << endl;
}