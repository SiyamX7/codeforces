#include <bits/stdc++.h>
#include <numeric>
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

	ll x = 0, y = 0;

	for(int i = 0; i < n;  i++){
		if(i&1) 
			y = gcd(y, a[i]); 
		else 	
			x = gcd(x, a[i]); 
	}


	for(int i = 0; i < n;  i += 2){
		if(a[i] % y == 0){
			y = 1;
		}
	}

	for(int i = 1; i < n; i+=2){
		if(a[i] % x == 0){
			x = 1;
		}
	}

	if(x == y){
		cout << 0 << endl;
	} else {
		cout << max(x,y) << endl;
	}
}

int main() {
    fast();
    int t = 1;
    cin >> t;
    while (t--) solve();
}
    