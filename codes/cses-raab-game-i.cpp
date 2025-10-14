#include <bits/stdc++.h>
using namespace std;

void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    if (a + b > n) {
        cout << "NO\n";
        return;
    }

    vector<int> p, q(n);
    for (int i = 1; i <= n; i++) {
        q[i - 1] = i;
    }

    int j = 0;

    // A wins positions
    for (int i = b + 1; i <= b + a; i++) {
        p.push_back(i);
        if (q[j] >= p[j]) {
            cout << "NO\n";
            return;
        }
        ++j;
    }

    // B wins positions
    for (int i = 1; i <= b; i++) {
        p.push_back(i);
        if (q[j] <= p[j]) {
            cout << "NO\n";
            return;
        }
        ++j;
    }

    // Draws positions
    for (int i = a + b + 1; i <= n; i++) {
        p.push_back(i);
        if (q[j] != p[j]) {
            cout << "NO\n";
            return;
        }
        ++j;
    }

    cout << "YES\n";

    for (int x : p) cout << x << " ";
    cout << "\n";
    for (int x : q) cout << x << " ";
    cout << "\n";
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
}
