#include <bits/stdc++.h>
using namespace std;

static inline void fast(){ ios::sync_with_stdio(false); cin.tie(nullptr); }

#define int long long

const int INF = 4e18;
const int MOD = 1e9+7;



signed main() {
    fast();
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve(t);
    }
    return 0;
}