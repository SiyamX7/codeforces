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
    ll n, x;
    cin >> n >> x;
    vector<ll> v(n);
    for(ll i = 0; i < n; i++) cin >> v[i];

    ll left = 0, right = 2e10;

	while(left <= right){
		ll mid = left + (right - left) / 2;
		ll total = 0;

		for(ll i = 0; i < n; i++){
			total += max(mid - v[i], 0LL);
		}

		if(total <= x){
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}

	cout << --left << endl;
}

int main() {
    fast(); 

    int t = 1;
    cin >> t; 

    while (t--) solve();
}
    