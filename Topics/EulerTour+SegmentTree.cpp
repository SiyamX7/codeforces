#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 200000;

struct EulerTour {
    int n;
    vector<vector<int>> adj;
    vector<int> tin, tout, flat, value;
    int timer;

    EulerTour(int _n) {
        n = _n;
        adj.assign(n + 1, vector<int>());
        tin.assign(n + 1, 0);
        tout.assign(n + 1, 0);
        flat.assign(n + 1, 0);
        value.assign(n + 1, 0);
        timer = 0;
    }

    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int node, int parent){
        tin[node] = ++timer;
        flat[timer] = node;

        for(int child : adj[node]){
            if(child == parent) continue;
            dfs(child, node);
        }

        tout[node] = timer;
    }

    void build(int root = 1){
        timer = 0;
        dfs(root, 0);
    }

    pair<int,int> subtreeRange(int u){
        return {tin[u], tout[u]};
    }
};

// ---------------- Segment Tree ----------------
struct SegTree {
    int n;
    vector<int> tree, lazy;

    SegTree(int size){
        n = size;
        tree.assign(4*n, 0);
        lazy.assign(4*n, 0);
    }

    void push(int node, int l, int r){
        if(lazy[node] != 0){
            tree[node] += (r - l + 1) * lazy[node];
            if(l != r){
                lazy[2*node] += lazy[node];
                lazy[2*node+1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void update(int node, int l, int r, int ql, int qr, int val){
        push(node,l,r);
        if(qr < l || r < ql) return;
        if(ql <= l && r <= qr){
            lazy[node] += val;
            push(node,l,r);
            return;
        }
        int mid = (l + r)/2;
        update(2*node, l, mid, ql, qr, val);
        update(2*node+1, mid+1, r, ql, qr, val);
        tree[node] = tree[2*node] + tree[2*node+1];
    }

    int query(int node, int l, int r, int ql, int qr){
        push(node,l,r);
        if(qr < l || r < ql) return 0;
        if(ql <= l && r <= qr) return tree[node];
        int mid = (l + r)/2;
        return query(2*node,l,mid,ql,qr) + query(2*node+1,mid+1,r,ql,qr);
    }
};

// ---------------- Solve Function ----------------
void solve(){
    int n, q;
    cin >> n >> q;

    EulerTour et(n);

    for(int i = 1; i < n; i++){
        int u,v; cin >> u >> v;
        et.addEdge(u,v);
    }

    for(int i = 1; i <= n; i++){
        cin >> et.value[i]; // initial node value
    }

    et.build(1);

    // Build segment tree using Euler Tour
    SegTree st(n);
    for(int i = 1; i <= n; i++){
        int idx = et.tin[i];
        st.update(1,1,n,idx,idx,et.value[i]); // point update for initial values
    }

    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            // Add val to entire subtree
            int u, val;
            cin >> u >> val;
            auto [L,R] = et.subtreeRange(u);
            st.update(1,1,n,L,R,val);
        }
        else if(type == 2){
            // Query sum of subtree
            int u;
            cin >> u;
            auto [L,R] = et.subtreeRange(u);
            int ans = st.query(1,1,n,L,R);
            cout << ans << "\n";
        }
    }
}

// ---------------- Main ----------------
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin >> t;  // multiple testcases
    while(t--) solve();
    return 0;
}
