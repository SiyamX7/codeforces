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
    ll n, k, s, t;
    cin >> n >> k >> s >> t;
    s--, t--;
    vector<ll> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i];

    ll dist = 1LL * abs(a[s] - a[t]) + abs(b[s] - b[t]);

	ll mna = 1e18, mnb = 1e18;

	for(int i = 0; i < k; i++){
		mna = min(mna,1LL* abs(a[s] - a[i]) + abs(b[s] - b[i]));
		mnb = min(mnb,1LL* abs(a[i] - a[t]) + abs(b[i] - b[t]));
	}

	cout << min(dist, mna+mnb) << endl;
}

int main() {
    fast();
    int t = 1;
    cin >> t;
    while (t--) solve();
}
    