#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr);
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

#define popcount(x) __builtin_popcount(x)         // Count 1s in x (int)
#define popcountll(x) __builtin_popcountll(x)     // Count 1s in x (ll)
#define ctz(x) __builtin_ctz(x)                   // Count trailing 0s
#define clz(x) __builtin_clz(x)                   // Count leading 0s

template <typename T>
void print(const vector<T>& v) {
    for (const auto& x : v) {
        cout << x << ' ';
    }
    cout << '\n';
}

#define debug(x) cerr << #x << " = " << (x) << endl;

int main() {
    fast;

    int t;
    cin >> t;

    while(t--){
    	string s, sub;
    	cin >> s >> sub;

    	int last = s.length() - 1;
    	int pos = sub.length() - 1;
    	int count = 0;

    	while (last >= 0){
    		if(s[last] == sub[pos]){
    			pos--;
    		} else {
    			last--;
    		}
    	}

    }
}