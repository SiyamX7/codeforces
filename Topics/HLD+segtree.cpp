#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 200000;

// -------------------- SEGMENT TREE --------------------
struct SegTree {
    int n;
    int tree[4*N], lazy[4*N];

    SegTree(int _n) : n(_n) {
        memset(tree, 0, sizeof(tree));
        memset(lazy, 0, sizeof(lazy));
    }

    void push(int node, int start, int end) {
        if(lazy[node] != 0) {
            tree[node] += (end-start+1)*lazy[node];
            if(start != end) {
                lazy[2*node] += lazy[node];
                lazy[2*node+1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void update(int node, int start, int end, int l, int r, int val) {
        push(node, start, end);
        if(r < start || end < l) return;
        if(l <= start && end <= r) {
            lazy[node] += val;
            push(node, start, end);
            return;
        }
        int mid = (start+end)/2;
        update(2*node, start, mid, l, r, val);
        update(2*node+1, mid+1, end, l, r, val);
        tree[node] = tree[2*node] + tree[2*node+1];
    }

    int query(int node, int start, int end, int l, int r) {
        push(node, start, end);
        if(r < start || end < l) return 0;
        if(l <= start && end <= r) return tree[node];
        int mid = (start+end)/2;
        return query(2*node, start, mid, l, r) + query(2*node+1, mid+1, end, l, r);
    }

    // convenient wrappers
    void upd(int l, int r, int val) { update(1,1,n,l,r,val); }
    int qry(int l, int r) { return query(1,1,n,l,r); }
};

// -------------------- HLD --------------------
struct HLD {
    int n, timer;
    vector<int> adj[N+1];
    int parent[N+1], depth[N+1], heavy[N+1], head[N+1], pos[N+1], subsize[N+1];
    int value[N+1], arr[N+1];  // node values and flattened segment tree array
    SegTree st;

    HLD(int _n) : n(_n), st(_n) {  // init segtree
        timer = 0;
        memset(heavy, -1, sizeof(heavy));
        memset(subsize, 0, sizeof(subsize));
        memset(parent, 0, sizeof(parent));
        memset(depth, 0, sizeof(depth));
        memset(head, 0, sizeof(head));
        memset(pos, 0, sizeof(pos));
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int dfs(int u, int p) {
        parent[u] = p;
        subsize[u] = 1;
        int max_sz = 0;
        for(int v : adj[u]) {
            if(v == p) continue;
            depth[v] = depth[u]+1;
            int sz = dfs(v,u);
            subsize[u] += sz;
            if(sz > max_sz) {
                max_sz = sz;
                heavy[u] = v;
            }
        }
        return subsize[u];
    }

    void decompose(int u, int h) {
        head[u] = h;
        pos[u] = ++timer;
        arr[pos[u]] = value[u];  // flattening values for segment tree
        if(heavy[u] != -1) decompose(heavy[u], h);
        for(int v : adj[u]) {
            if(v != parent[u] && v != heavy[u])
                decompose(v, v);
        }
    }

    void build() {
        dfs(1,0);
        decompose(1,1);
        for(int i=1;i<=n;i++)
            st.upd(i,i,arr[i]);  // build segment tree with initial values
    }

    // Update path from u to v by val
    void updatePath(int u, int v, int val) {
        while(head[u] != head[v]) {
            if(depth[head[u]] < depth[head[v]]) swap(u,v);
            st.upd(pos[head[u]], pos[u], val);
            u = parent[head[u]];
        }
        if(depth[u] > depth[v]) swap(u,v);
        st.upd(pos[u], pos[v], val);
    }

    // Query sum on path from u to v
    int queryPath(int u, int v) {
        int res = 0;
        while(head[u] != head[v]) {
            if(depth[head[u]] < depth[head[v]]) swap(u,v);
            res += st.qry(pos[head[u]], pos[u]);
            u = parent[head[u]];
        }
        if(depth[u] > depth[v]) swap(u,v);
        res += st.qry(pos[u], pos[v]);
        return res;
    }
};

// -------------------- DEMO: solve() --------------------
void solve() {
    int n; cin >> n;
    HLD hld(n);
    for(int i=1;i<n;i++) {
        int u,v; cin>>u>>v;
        hld.addEdge(u,v);
    }
    for(int i=1;i<=n;i++) cin>>hld.value[i];  // initial node values
    hld.build();

    int q; cin >> q;
    while(q--) {
        int type; cin >> type;
        if(type==1) {  // update path
            int u,v,val; cin>>u>>v>>val;
            hld.updatePath(u,v,val);
        } else {      // query path
            int u,v; cin>>u>>v;
            cout << hld.queryPath(u,v) << "\n";
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin>>T;
    while(T--) solve();
    return 0;
}
