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
	ll n;
	cin >> n;
	vector<ll> a(n), b(n);

	for(ll &i : a) cin >> i;
	for(ll &i : b) cin >> i;

	int l = 0, r = n-1;

	for(l = 0; l < n; l++){
		if(a[l] != b[l]) break;
	}

	for(r = n-1; r >= l; r--){
		if(a[r] != b[r]) break;
	}

	while(l-1 >= 0 && b[l-1] <= b[l]) l--;
	while(r+1 <= n-1 && b[r] <= b[r+1]) r++;

	cout << l+1 << " " << r+1 << endl;
}

int main() {
    fast();
    int t = 1;
    cin >> t;
    while (t--) solve();
}
    