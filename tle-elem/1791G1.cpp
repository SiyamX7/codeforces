#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define eb emplace_back
#define bug(x) cerr << #x << " = " << x << endl

#define rem(v,x) (v).erase(remove((v).begin(), (v).end(), (x)), (v).end())
#define leftrotate(v,k) rotate((v).begin(), (v).begin() + ((k) % (v).size()), (v).end())

#define popcountll(x) __builtin_popcountll(x)
#define lzll(x) __builtin_clzll(x)
#define tzll(x) __builtin_ctzll(x)

void fast() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); }
template <typename T>
void print(const vector<T>& vec) { for (const auto& val : vec) cout << val << " "; cout << endl; }

void solve() {
    ll n, c;
    cin >> n >> c;
    vector<ll> a(n),b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    	
    for(int i = 0; i < n; i++){
    	b[i] = a[i] + i + 1;
    }

    sort(b.begin(), b.end());

    ll count = 0;

    for(int i = 0; i < n; i++){
    	if(c >= b[i]){
    		count++;
    		c -= b[i];
    	} else {
    		break;
    	}
    }

    cout << count << endl;
}

int main() {
    fast();
    int t = 1;
    cin >> t;
    while (t--) solve();
}
    