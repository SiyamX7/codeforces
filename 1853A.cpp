#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define vb vector<bool>
#define fast ios::sync_with_stdio(0); cin.tie(0);

using namespace std;                   

int main() {
    fast;
 	ll t; cin >> t;
 	while(t--){
 		ll n; cin >> n;
 		vll v(n);
 		for(ll &i : v) cin >> i;

 		if(! is_sorted(v.begin(), v.end())){
 			cout << 0 << endl;
 		} else {
 			ll mn = INT_MAX;
 			for(ll i = 1; i < n; i++){
 				ll diff = abs(v[i] - v[i-1]);
 				mn = min(mn, diff);
 			}
 			cout << mn / 2 + 1 << endl;
 		}
 	}   
}