#include <bits/stdc++.h>
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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), b(k);
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    }

    for(int i = 0; i < k; i++) cin >> b[i];

    ll prev = 31;

	for(int i = 0; i < k; i++){
		if(b[i] >= prev) continue;
		ll x = (1ll << b[i]);
		
		for(int j = 0; j < n; j++){
			if(a[j] % x == 0){
				a[j] += (1ll << (b[i]-1));
			}
		}

		prev = b[i];
	}

	print(a);
}

int main() {
    fast();
    int t = 1;
    cin >> t;
    while (t--) solve();
}
    