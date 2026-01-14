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
	ll a[n];
	for(ll &i : a) cin >> i;

	ll MAX = a[0];
	ll SUM = a[0];

	for(int i = 1; i < n; i++){
		if(a[i] & 1){ 
			if(a[i-1] & 1){
				SUM = a[i];
			} else {
				SUM = max(a[i], a[i] + SUM);
			}
		}
		else {
			if(a[i-1] & 1){
				SUM = max(a[i], a[i] + SUM);
			} else {
				SUM = a[i];
			}
		}

		MAX = max(MAX, SUM);
	}

	cout << MAX << endl;
}

int main() {
    fast();
    int t = 1;
    cin >> t;
    while (t--) solve();
}
    