#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >>n;
    vector<bool> dp(n+1, 0);
    vector<int> v;
    for(int i = 1; i <= n; i++) v.push_back(i);

    dp[0] = true;
    int target = n * (n+1) / 4;
    for(int i = 1; i <= target; i++){
    	dp[i] = dp[i-1] || dp[i - v[i]];
    }

    for(int i = 0; i < n+1; i++) cout << dp[i] << " ";
}   