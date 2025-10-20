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
    for(ll &x : v) cin >> x;

    int count = 0;

	for(int x : v) if(x == 0) count++;

	if(count == n) {
		cout << 0 << endl;
		return;
	}

	int l = 0, r = n-1;
	
	while(v[l] == 0 && l < n) l++;
	while(v[r] == 0 && r >= 0) r--;

	for(int i = l; i < r; i++){
		if(v[i] == 0){
			cout << 2 << endl;
			return;
		}
	}

	cout << 1 << endl;
}

int main() {
    fast(); 

    int t; 
    // t = 1;
    cin >> t; 

    while (t--) solve();
}
    