#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    vector<int> v(n);

    int sum = 0;
    for(int &i : v) cin >> i, sum +=i;

    if(sum & 1) {
        cout << "NO" << endl;
        return 0;
    }

    vector<int> dp(k+1, 0);
    dp[0] = 1;

    for(int i = 0; i < n; i++){
        if(v[i] > k) continue;
        for(int j = k; j >= v[i]; j--){
            dp[j] = dp[j] + dp[j - v[i]];
        }
    }

    cout << dp[k];
}   