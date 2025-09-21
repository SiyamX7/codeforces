#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; 
    cin >> n;
    vector<int> v(n);
    int sum = 0;
    for(int i = 0; i < n; i++){
    	cin >> v[i];
    	sum += v[i];
    }
    
    vector<bool> dp(sum + 1, false);
	dp[0] = 1;
	
	int count = 0;

	for(int i = 0; i < n; i++){
		for(int j = sum; j >= v[i]; j--){
			dp[j] = dp[j] || dp[j - v[i]];
		}
	}

	for(int i = 1; i < dp.size(); i++){
		if(dp[i])
			count++;
	}
	
	cout << count << endl;

	for(int i = 1; i < dp.size(); i++){
		if(dp[i])
			cout << i << " ";
	}
}   