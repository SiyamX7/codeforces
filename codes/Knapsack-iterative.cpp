#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& wt, vector<int> &val, int capacity, int n){
	if(n == 0 || capacity == 0)
		return 0;

	if(wt[n-1] <= capacity){
		return max(val[n-1] + maxProfit(wt,val, capacity - wt[n-1], n-1)   , 
				maxProfit(wt, val, capacity, n-1)); 
	} 
	
	else { 
		return maxProfit(wt, val, capacity, n-1);
	}
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> wt = {1, 3, 4, 5}; 
    vector<int> val = {15, 20, 30, 50}; 
    int N = 4;
    int W = 10;
	vector<vector<int>> dp;
    dp.assign(N+1, vector<int>(W+1, 0));

    // recursive to iterative rules: 
    // 1. function er jaygay dp[][] use kora
    // 2. joto gula variable change hoy, toto dimension er dp[][] banano. ekta hole ekta, duita hole duita
    // 3. function call er variable change er shomoy ja likhi ta dp[...][...] ekhane likhte hobe
    // 4. recursion er base case diye initialize korte hobe dp[][].


    for(int n = 1; n <= N; n++){
    	for(int w = 1; w <= W; w++){
    		if(wt[n-1] <= w) {
    			dp[n][w] = max(
    				val[n-1] + dp[n-1][w-wt[n-1]], 
    				dp[n-1][w]
    				);
    		} else {
    			dp[n][w] = dp[n-1][w];
    		}
    	}
    }

    cout << "MAX profit [recursive]: " << maxProfit(wt, val, 10, wt.size()) << endl;
    cout << "MAX profit [iterative]: " << dp[N][W] << endl;
}   