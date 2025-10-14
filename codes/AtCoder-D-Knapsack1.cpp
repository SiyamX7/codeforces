#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<ll>> dp;

ll maxProfit(vector<ll> &wt, vector<ll> &val, ll w, ll n){
    if(n == 0 || w == 0) return 0;

    if(dp[n][w] != -1) 
        return dp[n][w];

    if(wt[n-1] <= w){
        return dp[n][w] = max(val[n-1] + maxProfit(wt,val, w - wt[n-1],n-1), maxProfit(wt, val, w, n-1)); 
    } else {
        return dp[n][w] = maxProfit(wt, val, w, n-1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<ll> wt, val;

    ll N, W;
    cin >> N >> W;
    ll t = N;
    while (t--) {
        ll x, y;
        cin >> x >> y;
        wt.push_back(x);
        val.push_back(y);
    }

    dp.assign(N+1, vector<ll>(W+1, -1));
    cout << maxProfit(wt, val, W, N);
}   