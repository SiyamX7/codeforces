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
    vector<ll> v(n);
    for(ll i = 0; i < n; i++) cin >> v[i];

    unordered_map<ll,ll> freq;
	for(ll i = 0; i < n; i++){
		freq[v[i]]++;
	}

	for(auto [x,y] : freq){
		if(y == 1){
			cout << -1 << endl;
			return;
		}
	}

	vector<ll> p(n);
	iota(p.begin(), p.end(), 1);

	ll l = 0;

	while(l < n){
		ll r = l;
		while(r < n && v[l] == v[r]) r++;

		rotate(p.begin()+l, p.begin()+ l + 1, p.begin()+ r);
		l = r;
	}

	print(p);

}

int main() {
    fast(); 

    int t = 1;
    cin >> t; 

    while (t--) solve();
}
    