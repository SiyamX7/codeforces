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
	ll n;
	cin >> n;
	vector<pair<ll,ll>> v(n);

	ll W = 0, P = 0;

	for(ll i = 0; i < n; i++){
		ll w, p;
		cin >> w >> p;
		W += w; 
		P += p;
		v[i] = {w, p};

	}
	// cout << W << " " << P << endl;

	sort(v.begin(), v.end(), [] (pair<ll,ll> &a, pair<ll,ll> &b){
			return (a.first + a.second) > (b.first + b.second);
	});

	ll count = 0;
	ll cp = 0;
	for(ll i = 0; i < n; i++){
		cp += v[i].second;
		W -= v[i].first;

		// cout << cp << " " << W << endl;
		if(cp >= W){
			count = i + 1;
			break;
		}
	}


	// for(auto [x,y] : v){
	// 	cout << x << " " << y << endl;
	// }
	// cout << count << endl;
	cout << n - count << endl;

}

int main() {
    fast(); 

    int t = 1;
    cin >> t; 

    while (t--) solve();
}
    