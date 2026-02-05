#include <bits/stdc++.h>
#include <climits>
#include <unordered_map>
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

unordered_map<ll,ll> mp;

int dfs(int n, int k){
    if(n == k) return 0;
    if(n < k) return INT_MAX;

    if(mp.count(n)) return mp[n];

    int a = dfs(n/2, k);
    int b = dfs(n - n/2, k);

    int ans = INT_MAX;
    if(a != INT_MAX) ans = min(ans, a+1);
    if(b != INT_MAX) ans = min(ans, b+1);

    return mp[n] = ans;
}

void solve() {
    int n, k;
    cin >> n >> k;

    mp.clear();
    int ans = dfs(n,k);
    if (ans == INT_MAX) cout << -1 << endl;
    else cout << ans << endl;
}

int main() {
    fast();
    int t = 1;
    cin >> t;
    while (t--) solve();
}
    