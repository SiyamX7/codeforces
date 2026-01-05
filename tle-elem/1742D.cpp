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
	int n; 
	cin >> n;
	vector<int> v(n), lastPos(1001, -1);

	for(int i = 0; i < n; i++){
		cin >> v[i];
		lastPos[v[i]] = i+1;
	}

	int MAX = -1;

	for(int i = 1; i < 1001; i++){
		for(int j = 1; j < 1001; j++){
			if(gcd(i,j) == 1){
				if(lastPos[i] != -1 && lastPos[j] != -1)
					MAX = max(MAX, lastPos[i]+lastPos[j]);
			}
		}
	}

	cout << MAX << endl;
}

int main() {
    fast();
    int t = 1;
    cin >> t;
    while (t--) solve();
}
