#include <bits/stdc++.h>
#include <climits>
#include <functional>
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
void uniq(vector<T>& v) {
    sort(all(v));
    v.erase(unique(all(v)), v.end());
}

template<typename T>
void rotate(vector<T>& v, int k) {
    //LEFT
    if(v.empty()) return;
    k %= sz(v);
    rotate(v.begin(), v.begin() + k, v.end());
}

template<typename T>
void remVAL(vector<T>& v, T x) {
    v.erase(remove(all(v), x), v.end());
}

template<typename T>
void remID(vector<T>& v, int i) {
    if(i >= 0 && i < sz(v))
        v.erase(v.begin() + i);
}

template<typename T>
void print(const T& x) {
    cout << x << '\n';
}

template<typename A, typename B>
void print(const pair<A,B>& p) {
    cout << p.first << " " << p.second << '\n';
}

template<typename T>
void print(const vector<T>& v) {
    for(const auto& x : v) cout << x << " ";
    cout << '\n';
}

template<typename A, typename B>
void print(const vector<pair<A,B>>& v) {
    for(const auto& [x,y] : v)
        cout << x << " " << y << '\n';
}

template<typename T>
void print(const set<T>& s) {
    for(const auto& x : s) cout << x << " ";
    cout << '\n';
}

template<typename K, typename V>
void print(const map<K,V>& mp) {
    for(const auto& [k,v] : mp)
        cout << k << " : " << v << '\n';
}

template<typename T>
void print(const vector<vector<T>>& v) {
    for(const auto& row : v) {
        for(const auto& x : row) cout << x << " ";
        cout << '\n';
    }
}

i128 read_i128() {
    string s;
    cin >> s;
    i128 x = 0;
    int sign = 1, i = 0;
    if(s[0] == '-') sign = -1, i = 1;
    for(; i < (int)s.size(); i++)
        x = x * 10 + (s[i] - '0');
    return x * sign;
}

void print(i128 x) {
    if(x == 0) {
        cout << 0 << '\n';
        return;
    }
    if(x < 0) {
        cout << "-";
        x = -x;
    }
    string s;
    while(x) {
        s.push_back('0' + x % 10);
        x /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s << '\n';
}


void solve(int t) {
    int n, g;
    cin >> n >> g;

    vector<pair<int,int>> a(n);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        a[i] = {x,i};
    }

    sort(a.begin(), a.end(), [&](pair<int,int> &x, pair<int,int> &y){
        if(x.first == y.first){
            return x.second < y.second;
        }
        return x.first < y.first;
    });

    map<int, vector<int>> mp;
    for(int i = 0; i < n; i++) {
        int color = a[i].first;
        int idx = a[i].second;

        if(i == 0 || a[i].first != a[i-1].first) {
            mp[color].pb(idx);
        } else {
            mp[color].pb(idx - a[i-1].second - 1);
        }

        if(i == n - 1 || a[i].first != a[i+1].first) {
            mp[color].pb(n - 1 - idx);
        }
    }

    int ans = n;
    for(auto &[x, vec] : mp){
        sort(rall(vec));

        int k = vec[0];
        int l = vec.size() >= 2 ? vec[1] : 0;
        int m = max(k / 2, l);

        ans = min(ans, m);
    }

    cout << ans << endl;
}

signed main() {
    fast();
    int T = 1;
    cin >> T;
    for(int t = 1; t <= T; t++){
        solve(t);
    }
    return 0;
}