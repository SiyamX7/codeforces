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
    ll n, k, q;
    cin >> n >> k >> q;

    vector<ll> v(n);
    for(ll i = 0; i < n; i++) {
    	cin >> v[i];
    }

    vector<ll> s;

    for(ll i = 0; i < n; i++){
    	if(v[i] <= q){
    		ll count = 0;
    		while(i < n && v[i] <= q){
    			count++;
    			i++;
    		}
    		s.pb(count);
    		i--;
    	} 
    }

    ll ans = 0;

    for(int i = 0; i < s.size(); i++){
    	if(s[i] >= k){
    		ll diff = s[i] - k + 1;

    		ans += (diff * (diff + 1)) / 2;
    	}
    }

    cout << ans << endl;

}

int main() {
    fast(); 

    int t = 1;
    cin >> t; 

    while (t--) solve();
}
    