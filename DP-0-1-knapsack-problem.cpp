#include <bits/stdc++.h>
using namespace std;

int dp[102][1002]; // dp[n][w];

int maxProfit(vector<int> &wt, vector<int> &val, int w, int n){ // ekhaner n, w er jonno dp store hobe
	if(n == 0 || w == 0)
		return 0;

	if(dp[n][w] != -1){
		return dp[n][w];
	}

	if (wt[n-1] <= w) // n - 1 is the index, and n is the number of elem
	{
		return dp[n][w] = max(val[n-1] + maxProfit(wt, val, w-wt[n-1], n-1), maxProfit(wt, val, w, n-1));
	} 

	else 
	{
		return dp[n][w] = maxProfit(wt, val, w, n-1);
	}
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
	memset(dp, -1, sizeof(dp));

    int n = 3, W = 5;
    vector<int> wt = {3, 2, 4};
    vector<int> val = {60, 100, 120};

    cout << "MAX profit is: " << maxProfit(wt, val, W, n); 
}   