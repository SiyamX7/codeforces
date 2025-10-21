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
    int n, k; 
    cin >> n >> k;
    vector<ll> v(n*k);
    for(ll i = 0; i < n*k; i++){
    	cin >> v[i];
    }

    ll count = 1;
    ll ans = 0;
    
    while(count <= k){
    	ans += v[n*k - (n/2 + 1) * count];
    	count++;
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
    