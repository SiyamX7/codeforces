#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    
    if (n == 1) {
        cout << 0 << "\n";
        return;
    }

    vector<int> max_radius(n, 1e9);
    for (int i = 1; i < n; i++) {
        int d = x[i] - x[i - 1];
        max_radius[i] = min(max_radius[i], d);
        max_radius[i - 1] = min(max_radius[i - 1], d);
    }

    long long lower = 0;
    long long upper = max_radius[0];
    cout << upper << " ";
    int ans = n - 1;

    for (int i = 1; i < n; i++) {
        int d = x[i] - x[i - 1];

        // update interval WITHOUT tie
        long long new_upper = d - lower;
        long long new_lower = d - upper;

        lower = max(new_lower, 0LL);
        upper = min(new_upper, (long long)max_radius[i]);

        if (lower >= upper) {
            ans--;
            lower = 0;
            upper = max_radius[i];
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
