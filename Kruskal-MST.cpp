#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int parent[N], sz[N];

// Find with path compression
int find(int u) {
    if (u == parent[u])
        return u;
    return parent[u] = find(parent[u]);
}

// Union by size
bool unionSet(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return false;

    if (sz[u] < sz[v]) swap(u, v); // always attach smaller to bigger
    parent[v] = u;
    sz[u] += sz[v];
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    // Initialize DSU
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }

    vector<tuple<int, int, int>> edges; // {weight, u, v}
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }

    sort(edges.begin(), edges.end()); // sort edges by weight

    int mst_cost = 0;
    vector<pair<int, int>> mst_edges;

    for (auto [w, u, v] : edges) {
        if (unionSet(u, v)) {
            mst_cost += w;
            mst_edges.push_back({u, v});
        }
    }

    cout << "Total cost of MST: " << mst_cost << "\n";
    cout << "Edges in MST:\n";
    for (auto [u, v] : mst_edges) {
        cout << u << " - " << v << "\n";
    }

    return 0;
}
