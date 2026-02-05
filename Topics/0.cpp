#include <bits/stdc++.h>
using namespace std;

static inline void fast() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

#define int long long
#define i128  __int128_t
#define u128  __uint128_t
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define popcount(x) __builtin_popcountll(x) 
#define lz(x) __builtin_clzll(x) 
#define tz(x) __builtin_ctzll(x)
#define endl '\n'
#define yes cout << "YES\n"
#define no  cout << "NO\n"
#define test cout << "Test #" << t << ": " << endl
#define pb push_back
#define eb emplace_back
#define f first
#define s second

const int INF = 4e18;
const int MOD = 1e9 + 7;

#ifdef LOCAL
void debug() { cerr << '\n'; }
template<typename T>
void debug(const T& x) { cerr << x << '\n'; }
template<typename A, typename B>
void debug(const pair<A,B>& p) {
    cerr << "(" << p.first << ", " << p.second << ")\n";
}
template<typename T>
void debug(const vector<T>& v) {
    cerr << "[ ";
    for(const auto& x : v) cerr << x << " ";
    cerr << "]\n";
}
template<typename T>
void debug(const set<T>& s) {
    cerr << "{ ";
    for(const auto& x : s) cerr << x << " ";
    cerr << "}\n";
}
template<typename K, typename V>
void debug(const map<K,V>& mp) {
    cerr << "{ ";
    for(const auto& [k,v] : mp)
        cerr << k << ":" << v << " ";
    cerr << "}\n";
}
template<typename T, typename... Args>
void debug(const T& a, const Args&... args) {
    cerr << a << " ";
    debug(args...);
}
void debug(i128 x) {
    if(x == 0) {
        cerr << 0 << '\n';
        return;
    }
    if(x < 0) {
        cerr << "-";
        x = -x;
    }
    string s;
    while(x) {
        s.push_back('0' + x % 10);
        x /= 10;
    }
    reverse(s.begin(), s.end());
    cerr << s << '\n';
}
#else
#define debug(...)
#endif

template<typename T>
void print(const vector<T>& v) {
    for(const auto& x : v) cout << x << " ";
    cout << '\n';
}

void solve(int t) {
    int n, q;
    cin >> n >> q;

    vector<int> p(n + 1);
    p[1] = 0;
    for (int i = 2; i <= n; i++) {
        cin >> p[i];
    }

    vector<int> freq(n + 1, 0);
    int tt = 1;

    while (q--) {
        int k;
        cin >> k;
        vector<int> a(k);

        for (int i = 0; i < k; i++) {
            cin >> a[i];
            freq[a[i]] = tt;
        }

        if (k <= 1) {
            cout << "YES" << endl;
            tt++;
            continue;
        }

        int e = 0;
        for (int x : a) {
            if (p[x] && freq[p[x]] == tt)
                e++;
        }

        if (e == k - 1) cout << "YES" << endl;
        else cout << "NO" << endl;

        tt++;
    }
}

signed main() {
    fast();
    int T = 1;
    // cin >> T;
    for(int t = 1; t <= T; t++){
        solve(t);
    }
    return 0;
}