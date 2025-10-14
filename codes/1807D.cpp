#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define srt(x) sort(x.begin(), x.end())
#define rsrt(x) sort(x.rbegin(), x.rend())
#define vll vector<long long>
#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define pop(x) __builtin_popcount(x) // x -> int

int main() {
    fast;
    
    int t;
    cin >> t;
    while (t--) {
    	ll n, q;
    	cin >> n >> q;
    	vll v(n);
    	for(int i = 0; i < n; i++){
    		ll x;
    		cin >> x;
    		if(i == 0){
    			v[i] = x;
    		} else {
    			v[i] = v[i-1] + x;
    		}
    	}

    	while (q--) {
    		ll l, r, x;
    		cin >> l >> r >> x;
            ll sum = (r - l + 1) * x;

            ll gg = (l > 1) ? v[l - 2] : 0;

            ll qwerty = v[n-1] - (v[r-1] - gg) + sum;

            if (qwerty % 2 == 0){
                cout << "no" << endl;
            } else {
                cout << "yes" << endl;
            }
    	}

    }
}