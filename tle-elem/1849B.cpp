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

    vector<pair<ll, ll>> v(n);

    for(ll i = 0; i < n; i++){
    	cin >> v[i].first;
    	v[i].first %= k;
    	v[i].second = i+1;
    }

    for(auto [x,y] : v){
    	if(x == 0) {
    		cout << y << " ";
    	}
    }

    sort(v.begin(), v.end(), [&](pair<ll,ll> &a, pair<ll,ll> &b){
    	if(a.first == b.first){
    		return a.second < b.second;
    	}
    	return a.first > b.first;
    });

    for(auto [x,y] : v){
    	if(x != 0){
    		cout << y << " ";
    	}
    }

    cout << endl;
}

int main() {
    fast(); 

    int t = 1;
    cin >> t; 

    while (t--) solve();
}
    