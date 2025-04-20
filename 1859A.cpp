#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define vb vector<bool>
#define fast ios::sync_with_stdio(0); cin.tie(0);

using namespace std;                   

int main() {
    fast;
    ll t;
    cin >> t;
    while (t--) {
    	ll n;
    	cin >> n;
    	vll v(n);
    	unordered_map<ll, ll> mp;

    	ll mx = INT_MIN;
    	for(ll &i : v){
    		cin >> i;
    		if(i > mx) mx = i;
    		mp[i]++;
    	}

    	if(mp.size() == 1){
    		cout << -1 << endl;
    	} else {
    		cout << n - mp[mx] << " " << mp[mx] << endl;
    		for(ll i = 0; i < n; i++){
    			if(v[i] != mx){
    				cout << v[i] << " ";
    			}
    		}
    		cout << endl;
    		while(mp[mx]--) cout << mx << " ";
    		cout << endl;
    	}
    }
}