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
    int n, m;
    cin >> n >> m;
    vector<int> a(m), gaps;
    for(int &x : a) cin >> x;

    sort(all(a));

    for(int i = 1; i < m; i++){
        int g = a[i] - a[i - 1] - 1;
        if (g > 0) gaps.pb(g);
    }

    int g = a[0] + n - a[m-1] - 1;

    if(g > 0) gaps.pb(g);

    sort(rall(gaps));
    // test;

    int d = 0;
    int ans = 0;

    for(int x : gaps){
    	int rem = x - 2*d;

    	if(rem <= 0){
    		break;
    	} else if(rem == 1){
    		ans++;
    		d++;
    	} else {
    		ans += rem - 1;
    		d+=2;
    	}
    }

    cout << n - ans << endl;
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

    