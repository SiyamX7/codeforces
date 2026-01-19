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
    int n;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        s.insert(x);
    }

    vector<int> v(s.begin(), s.end());
    int k = v.size();

    int ans = 1;
    int curr = 1;

    for (int i = 1; i < k; i++) {
        if (v[i] == v[i - 1] + 1) {
            curr++;
        } else {
            curr = 1;
        }
        ans = max(ans, curr);
    }
    cout << ans << endl;
}

signed main() {
    fast();
    int t = 1;
    cin >> t;
    while (t--) solve();
}
