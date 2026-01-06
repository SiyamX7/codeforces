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
	int n;
	cin >> n;
	vector<int> a(n);
	for(int &i : a) cin >> i;

	ll sum = 0;
	ll neg = 0;
	for(int i : a){
		if(i < 0) neg++;
	}

	if(neg % 2 == 0){
		for(int i : a) {
			sum += abs(i);
		}
	} else {
		int mn = INT_MAX;
		for(int &i : a) {
			i = abs(i);
			sum += abs(i);
			mn = min(mn, i);
		}

		sum -= 2*mn;
	}

	cout << sum << endl;
}

int main() {
    fast();
    int t = 1;
    cin >> t;
    while (t--) solve();
}
    