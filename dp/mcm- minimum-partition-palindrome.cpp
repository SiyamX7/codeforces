#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp, pal;

int solve(string s, int i, int j){
	if(i >= j) return 0;
	if(pal[i][j] == 1) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int ans = INT_MAX;
    for(int k = i; k < j; k++){
        if(pal[i][k] == 1){
            int cut = 1 + solve(s,k+1,j); 
            ans = min(ans,cut);
        }
    }

    return dp[i][j] = ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s = "ababu";
    int n = s.size();

    dp.assign(n, vector<int> (n, -1));
    pal.assign(n, vector<int> (n,0));

    for(int len = 1; len <= n; len++){
    	for(int i = 0; i + len - 1 < n; i++){
    		int j = i + len - 1;

    		if(len == 1) pal[i][j] = 1;
    		else if(len == 2 && s[i] == s[j]) pal[i][j] = 1;
    		else {
    			if(s[i] == s[j] && pal[i+1][j-1] == 1) pal[i][j] = 1;
    		}
    	}
    }

    cout << solve(s, 0, n-1);

}   