#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<int> v = {3,1,5,6,4,2};
    int n = v.size();
    vector<int> dp(n,1);

    for(int i = 0; i < n; i++){
    	for(int j = 0; j < i; j++){
    		if(v[i] >= v[j] && 1 + dp[j] >= dp[i]){
    			dp[i] = 1 + dp[j];
    		}
    	}
    }

    for(int i = 0; i < n; i++){
    	cout << dp[i] << " ";
    }
}   