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
	string s;
	cin >> s;
	int n = s.size();

	s += s;

	int MAX = 0;

	int j = 0;
	for(int i = 0; i < 2*n; ){
		if(s[i] == '1'){
			j = i;
			int count = 0;
			while(j < 2*n && s[j] == '1') j++, count++;
			MAX = max(MAX,count);
			i = j;
		} else {
			i++;
		}
	}

	ll ans = 0;

	if(MAX == 2*n){
		ans = 1LL * n * n;
	} else {
		ll x = 1, y = MAX;
		while(x <= y){
			ans = max(ans, x*y);
			x++, y--;
		}
	}
	cout << ans << endl;
	// cout << MAX << endl;
}

int main() {
    fast();
    int t = 1;
    cin >> t;
    while (t--) solve();
}
    