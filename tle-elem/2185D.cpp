#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define eb emplace_back
#define bug(x) cerr << #x << " = " << x << endl
#define endl '\n'

#define rem(v,x) (v).erase(remove((v).begin(), (v).end(), (x)), (v).end())
#define leftrotate(v,k) rotate((v).begin(), (v).begin() + ((k) % (v).size()), (v).end())

#define popcountll(x) __builtin_popcountll(x)
#define lzll(x) __builtin_clzll(x)
#define tzll(x) __builtin_ctzll(x)

void fast() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); }
template <typename T>
void print(const vector<T>& vec) { for (const auto& val : vec) cout << val << " "; cout << endl; }

void solve() {
    int n, m, h;
    cin >> n >> m >> h;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    map<int,int> mp;
	
	while (m--) {
		int x, y;
		cin >> x >> y;
		--x;

		if(a[x] + mp[x] + y <= h){
			mp[x] += y;
		} else {
			mp.clear();
		}
	}

	for(int i = 0; i < n; i++){
		if(mp.find(i) != mp.end()){
			cout << mp[i] + a[i] << " ";
		} else {
			cout << a[i] << " ";
		}
	}

	cout << endl;
}

signed main() {
    fast();
    int t = 1;
    cin >> t;
    while (t--) solve();
}
    