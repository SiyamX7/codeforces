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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n), mx(n), pref(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    mx[0] = b[0];
    for(int i = 1; i < n; i++){
    	mx[i] = max(mx[i-1], b[i]);
    }

    pref[0] = a[0];
    for(int i = 1; i < n; i++){
    	pref[i] = pref[i-1] + a[i];
    }

    ll ans = 0;

    for(int i = 1; i <= min(n,k); i++){
    	ll sum = pref[i-1];
    	ll rem = k - i;
    	sum += rem * mx[i-1];
    	ans = max(ans, sum);
    }

    cout << ans << endl;
}

int main() {
    fast();
    int t = 1;
    cin >> t;
    while (t--) solve();
}
    