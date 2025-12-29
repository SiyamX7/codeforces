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
    vector<ll> a(n), b(n), c(n);

    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < n; i++) cin >> b[i];
    for(ll i = 0; i < n; i++) cin >> c[i];

    ll count = 0;

	
	ll ab = 0;
	for(ll i = 0; i < n; i++){
		bool gg = false;

		for(ll j = 0; j < n; j++){
			if(a[j] >= b[(i+j) % n]){
				gg = true;
				break;
			}
		}


		if(!gg) ab++;
	}



	ll bc = 0;
	for(ll i = 0; i < n; i++){
		bool gg = false;

		for(ll j = 0; j < n; j++){
			if(b[j] >= c[(i+j) % n]){
				gg = true;
				break;
			}
		}


		if(!gg) bc++;
	}

	cout << n *  ab * bc << endl;
}

int main() {
    fast(); 

    int t = 1;
    cin >> t; 

    while (t--) solve();
}
    