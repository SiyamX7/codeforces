#include <bits/stdc++.h>
#include <cstdint>
using namespace std;

#define int long long
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
	int n;
	cin >> n;
	vector<int> v(n),pref(n);
	for(int &i : v) cin >> i;

	pref[0] = v[0];
	
	for(int i = 1; i < n; i++){
		pref[i] = pref[i-1] + v[i];
	}

	int ans = 0;
	int sum = pref[n-1];

	for(int i = 0; i < n-1; i++){
		ans = max(ans, gcd(pref[i], sum - pref[i]));
	}

	cout << ans << endl;

	//print(pref);
}

int32_t main() {
    fast();
    int t = 1;
    cin >> t;
    while (t--) solve();
}
    