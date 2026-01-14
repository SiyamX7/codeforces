#include <bits/stdc++.h>
#include <climits>
using namespace std;

#define ll long long
#define pb push_back
#define eb emplace_back
#define bug(x) cerr << #x << " = " << x << endl

#define rem(v,x) (v).erase(remove((v).begin(), (v).end(), (x)), (v).end())
#define leftrotate(v,k) rotate((v).begin(), (v).begin() + ((k) % (v).size()), (v).end())
#define rightrotate(v,k) rotate((v).begin(), (v).end() - ((k) % (v).size()), (v).end())
#define popcount(x) __builtin_popcount(x)
#define popcountll(x) __builtin_popcountll(x)
#define lz(x) __builtin_clz(x)
#define lzll(x) __builtin_clzll(x)
#define tz(x) __builtin_ctz(x)
#define tzll(x) __builtin_ctzll(x)

void fast() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); }
template <typename T>
void print(const vector<T>& vec) { for (const auto& val : vec) cout << val << " "; cout << endl; }

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), pref(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    for(int i = 0; i < n; i++) {
    	if(!i){
    		pref[i] = a[i];
    	} else {
    		pref[i] = pref[i-1] + a[i];
    	}
    }    

    vector<ll> div;
    for(int i = 1; i * i <= n; i++){
    	if(n % i == 0){
    		div.pb(i);

    		if(i != n/i && n/i != n){
    			div.pb(n/i);
    		}
    	}
    }

    ll mxdiff = LLONG_MIN;

    for(ll i : div){
    	ll mx = pref[i-1];
    	ll mn = pref[i-1];

    	for(int j = i; j + i <= n; j+=i){
    		ll diff = pref[j+i-1] - pref[j-1]; 
    		mx = max(mx, diff);
    		mn = min(mn, diff);
    	}

    	mxdiff = max(mxdiff, mx - mn);
    }

    cout << mxdiff << endl;

    // print(div);
}

int main() {
    fast();
    int t = 1;
    cin >> t;
    while (t--) solve();
}
    