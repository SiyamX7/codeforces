#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define eb emplace_back
#define bug(x) cerr << #x << " = " << x << endl

#define rem(v,x) (v).erase(remove((v).begin(), (v).end(), (x)), (v).end())
#define leftrotate(v,k) rotate((v).begin(), (v).begin() + ((k) % (v).size()), (v).end())

#define popcountll(x) __builtin_popcountll(x)
#define lzll(x) __builtin_clzll(x)
#define tzll(x) __builtin_ctzll(x)

void fast() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); }
template <typename T>
void print(const vector<T>& vec) { for (const auto& val : vec) cout << val << " "; cout << endl; }

ll calc(ll n){
	ll ans = 0;

	while(n > 0){
		ans += n % 10;
		n /= 10;
	}

	return ans;
}

void solve() {
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    set<ll> big;
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    	if(a[i] > 9){
    		big.insert(i);
    	}
    }


    while(q--){
    	ll type;
    	cin >> type;

    	if(type == 1){
    		ll l, r;
    		cin >> l >> r;
    		l--, r--;

    		auto it = big.lower_bound(l);

    		while(it != big.end() && *it <= r){
    			int index = *it;
    			a[index] = calc(a[index]);

    			if(a[index] <= 9){
    				it = big.erase(it); // shudhu erase dile kaj hobena
    			} else {
    				it++;
    			}
    		}
    	} else {
    		int x;
    		cin >> x;
    		cout << a[x-1] << endl;
    	}
    }
}

int main() {
    fast();
    int t = 1;
    cin >> t;
    while (t--) solve();
}
    