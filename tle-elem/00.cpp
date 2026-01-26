#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        int maxA = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            maxA = max(maxA, a[i]);
        }

        
        vector<int> d(n + 1, INT_MAX);

        
        unordered_set<int> s(a.begin(), a.end());
        for (int x : s) {
            if (x <= n) d[x] = 1;
        }

        
        for (int i = 1; i <= n; i++) {
            if (d[i] == INT_MAX) continue;

            for (int x : s) {
                long long prod = 1LL * i * x;
                if (prod > n) continue;
                d[prod] = min(d[prod], d[i] + 1);
            }
        }

     
        for (int i = 1; i <= n; i++) {
            if (d[i] == INT_MAX) cout << -1 << " ";
            else cout << d[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}