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

    vector<ll> v(n);
    for(ll i = 0; i < n; i++){
    	cin >> v[i];
    }

    vector<pair<ll,ll>> range(n);
    for(ll i = 0; i < n; i++){
    	range[i].first = v[i] - k;
    	range[i].second = v[i] + k;
    }

    ll count = 0;
    ll l = range[0].first;
    ll r = range[0].second;

    for(ll i = 1; i < n; i++){
    	l = max(l, range[i].first);
    	r = min(r, range[i].second);

    	if(l > r){
    		count++;
    		l = range[i].first;
    		r = range[i].second;
    	}
    }

    cout << count << endl;
}

int main() {
    fast(); 

    int t = 1;
    cin >> t; 

    while (t--) solve();
}