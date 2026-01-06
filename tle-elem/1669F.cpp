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
	vector<int> a(n), pref(n), suff(n);

	for(int &i : a) cin >> i;

	pref[0] = a[0];
	for(int i = 1; i < n; i++) {
		pref[i] = pref[i-1] + a[i];
	}

	suff[n-1] = a[n-1];
	for(int i = n-2; i >= 0; i--){
		suff[i] = suff[i+1] + a[i]; 
	} 

	int l = 0, r = n-1;
	int i = 0, j = n-1;
	bool ok = 0;

	while(i < j){
		if(pref[i] == suff[j]){
			ok = 1;
			l = i;
			r = j;
			i++;
			j--;
		} else if(pref[i] < suff[j]){
			i++;
		} else {
			j--;
		}
	}
	
	if(!ok) {
		cout << 0 << endl;
	} else {
		cout << (l+1) + (n-r) << endl;
	}
}

int main() {
    fast();
    int t = 1;
    cin >> t;
    while (t--) solve();
}
    