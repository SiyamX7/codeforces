#include <bits/stdc++.h>
using namespace std;

#define ll  long long 
#define pb  push_back
#define eb  emplace_back                                 
#define bug(x) cerr << #x << " = " << x << endl                 
 
void fast() {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
template <typename T>
void print(const vector<T>& vec) {for (const auto& val : vec) {cout << val << " ";}cout << endl;}

void solve(){
    ll n, k;
    cin >> n >> k;

    vector<pair<ll,ll>> v(n);

    for(int i = 0; i < n; i++)	cin >> v[i].first;
    for(int i = 0; i < n; i++)	cin >> v[i].second;

    sort(v.begin(), v.end(), [](pair<ll,ll> &a, pair<ll,ll> &b) {return a.second < b.second;});

	ll ans = 0;

	if(k <= v[0].second){
		ans = n * k;
		cout << ans << endl;
		return;
	}

	ll rem = n-1;
	ans = k;

	for(ll i = 0; i < n && rem > 0 && v[i].second < k; i++){
		ll t = min(v[i].first, rem);
		ans += t * v[i].second;
		rem -= t;
	}

	if(rem > 0){
		ans += rem * k;
	}

	// for(auto [x ,y] : v) cout << x << " " << y << endl;
	// cout << "______________________________________________________" << endl;
 	cout << ans << endl;
}

int main() {
    fast(); 

    int t = 1;
    cin >> t; 

    while (t--) solve();
}
    