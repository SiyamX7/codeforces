#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int lis(vector<int> &a, int i, int prev){
	if(i == a.size()) return 0;

	if(dp[i][prev+1] != -1) return dp[i][prev+1];
	int notTake = lis(a,i+1,prev);

	int take = 0;
	if(prev == -1 || a[i] > a[prev]){
		take = 1 + lis(a, i+1, i);
	}

	return dp[i][prev+1] = max(take, notTake);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<int> a = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = a.size();

    dp.assign(n, vector<int>(n+1, -1));
    cout << lis(a, 0, -1);
}   