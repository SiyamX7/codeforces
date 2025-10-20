#include <bits/stdc++.h>
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

    for(ll i = 0; i < n; i++) cin >> v[i];
	ll count = 0;

	for(ll i = n-2; i >= 0; --i){
		while(v[i] >= v[i+1]){
			count++;
			v[i] /= 2;
			if(v[i] == 0) break;
		}

		if(v[i] == 0 && v[i+1] == 0) {
			cout << -1 << endl;
			return;
		}
	}

	cout << count << endl;
}

int main() {
    fast(); 

    int t; 
    // t = 1;
    cin >> t; 

    while (t--) solve();
}
    