#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

bool subsetSum(vector<int> &val, int target, int n){
	if(target == 0)return true;
	if(n == 0) return false;

	if(dp[n][target] != -1) return dp[n][target];

	if(val[n-1] <= target) {
		return dp[n][target] = (subsetSum(val, target - val[n-1], n-1) || subsetSum(val, target, n-1));
	} else {
		return dp[n][target] = subsetSum(val, target, n-1);
	}
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<int> val {2,3,7,9,12};
    int sum = 34;
    int n = val.size();

    dp.assign(n+1 , vector<int>(sum+1, -1));

    bool x = subsetSum(val, sum, val.size());
    x ? (cout << "subset is there") : (cout << "No subset is there");
}   