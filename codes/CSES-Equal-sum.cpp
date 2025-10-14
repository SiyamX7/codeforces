#include <bits/stdc++.h>
using namespace std;
vector<int> v;
vector<vector<bool>> dp;

bool fn(int n, int target, vector<int> &subset){
	if(n == 0) return dp[n][target] = 0;
	if(target == 0) return dp[n][target] = 1;

	if(dp[n][target]) return dp[n][target];

	bool take = false, notTake = false;

	if(v[n-1] <= target){
		subset.push_back(v[n-1]);
		take = fn(n-1, target - v[n-1], subset);
		if(take == false) 
			subset.pop_back();
	} 
	
	notTake = fn(n-1,target, subset);
	
	return dp[n][target] = take || notTake;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    int sum = (n * (n + 1)) / 2;
    if(sum % 2 == 1){
    	cout << "NO" << endl;
    	return 0;
    } 

    int target = sum / 2;
    for(int i = 1; i <= n; i++){
    	v.push_back(i);
    }
    dp.assign(n+1, vector<bool>(target+1, false));
    vector<int> subset;

    if(fn(n, target, subset)){
    	cout << "YES" << endl;
    	cout << subset.size() << endl;
    	for(int x : subset) cout << x << " ";
    	cout << endl <<  n - subset.size() << endl;
    	unordered_set<int> s(subset.begin(), subset.end());
    	for(int i = 1; i <= n; i++){
    		if(!s.count(i)){
    			cout << i << " ";
    		}
    	}
    } else {
    	cout << "NO" << endl;
    }
}   