#include <bits/stdc++.h>
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

long long rnd(long long l, long long r) {
    return uniform_int_distribution<long long>(l, r)(rng);
}

/* ===== CHANGE THIS ===== */
/*
1 -> array
2 -> permutation
3 -> string
4 -> tree
5 -> graph
*/
int TYPE = 1;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n = rnd(2, 30);   // change range when needed
    cout << n << "\n";

    /* ================= ARRAY ================= */
    if (TYPE == 1) {
        for (int i = 0; i < n; i++) {
            cout << rnd(1, 1000) << " ";
        }
        cout << "\n";
    }

    /* ================= PERMUTATION ================= */
    else if (TYPE == 2) {
        vector<int> p(n);
        iota(p.begin(), p.end(), 1);
        shuffle(p.begin(), p.end(), rng);
        for (int x : p) cout << x << " ";
        cout << "\n";
    }

    /* ================= STRING ================= */
    else if (TYPE == 3) {
        int len = rnd(1, n);
        string s;
        for (int i = 0; i < len; i++) {
            char c = char('a' + rnd(0, 25));
            s += c;
        }
        cout << s << "\n";
    }

    /* ================= TREE ================= */
    else if (TYPE == 4) {
        for (int i = 2; i <= n; i++) {
            int parent = rnd(1, i - 1);
            cout << parent << " " << i << "\n";
        }
    }

    /* ================= GRAPH ================= */
    else if (TYPE == 5) {
        int m = rnd(n - 1, n * (n - 1) / 2);
        set<pair<int,int>> edges;

        while ((int)edges.size() < m) {
            int u = rnd(1, n);
            int v = rnd(1, n);
            if (u == v) continue;
            if (u > v) swap(u, v);
            edges.insert({u, v});
        }

        cout << n << " " << m << "\n";
        for (auto [u, v] : edges) {
            cout << u << " " << v << "\n";
        }
    }

    return 0;
}
