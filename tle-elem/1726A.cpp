#include <bits/stdc++.h>
#include <climits>
using namespace std;

#define ll long long              
#define pb  push_back
#define eb  emplace_back                                 
#define bug(x) cerr << #x << " = " << x << endl                 
 
void fast() {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
template <typename T>
void print(const vector<T>& vec) {for (const auto& val : vec) {cout << val << " ";}cout << endl;}

void solve(){
    ll n; cin >> n;
    vector<ll> v(n);
    for(ll &x : v) cin >> x;

    ll ans = -1e9;

	for(ll i = 0; i < n; i++){
		ans = max(ans, v[n-1] - v[i]);
	}

	for(ll i = 0; i < n; i++){
		ans = max(ans, v[i] - v[0]);
	}


	for(ll i = 0; i < n-1; i++){
		ans = max(ans, v[i] - v[i+1]);
	}

	cout << ans << endl;
}

int main() {
    fast(); 

    int t; 
    // t = 1;
    cin >> t; 

    while (t--) solve();
}
    