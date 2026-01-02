#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
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


const int MOD = 1E9 + 7;
void solve() {
	int n; cin >> n;
	vector<int> a(n), b(n);

	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];

	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<>());

	ll res = 1;

	for(int i = 0; i < n; i++){
		ll x = upper_bound(a.begin(), a.end(), b[i]) - a.begin();
		ll count = n - x;

		res = res * max(count - i, 0LL) % MOD;
	}

//NOTE: i মানে এখন পর্যন্ত কতটা position already fill করে ফেলেছি।
// যখন i = 0 → কিছুই বসাইনি → used = 0
// যখন i = 1 → ১টা বসানো হয়েছে → used = 1
// যখন i = 2 → ২টা বসানো হয়েছে → used = 2

	cout << res << endl;
}

int main() {
    fast();
    int t = 1;
    cin >> t;
    while (t--) solve();
}
    