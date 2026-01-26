#include <bits/stdc++.h>
using namespace std;

static inline void fast(){ ios::sync_with_stdio(false); cin.tie(nullptr); }

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define endl '\n'

const int N = 200005;
int arr[N+1];     
int seg[4*N];       
int lazy[4*N];      

void build(int node, int start, int end) {
    lazy[node] = -1; 
    if (start == end) {
        seg[node] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    build(2*node, start, mid);
    build(2*node+1, mid+1, end);
    seg[node] = seg[2*node] + seg[2*node+1];
}

void push(int node, int start, int end) {
    if (lazy[node] != -1) {
        seg[node] = (end - start + 1) * lazy[node]; 
        if (start != end) { 
            lazy[2*node] = lazy[node];
            lazy[2*node+1] = lazy[node];
        }
        lazy[node] = -1;
    }
}

void update(int node, int start, int end, int l, int r, int val) {
    push(node, start, end);
    if (r < start || end < l) return; 
    if (l <= start && end <= r) {   
        lazy[node] = val;
        push(node, start, end);
        return;
    }
    int mid = (start + end) / 2;
    update(2*node, start, mid, l, r, val);
    update(2*node+1, mid+1, end, l, r, val);
    seg[node] = seg[2*node] + seg[2*node+1];
}

int query(int node, int start, int end, int l, int r) {
    push(node, start, end);
    if (r < start || end < l) return 0;           
    if (l <= start && end <= r) return seg[node];
    int mid = (start + end) / 2;
    return query(2*node, start, mid, l, r) +
           query(2*node+1, mid+1, end, l, r);
}

void solve(int t){
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> arr[i];

    build(1,1,n);

    while(q--){
        int tt;
        cin >> tt;
        if(tt == 1){
            int ind, val;
            cin >> ind >> val;
            update(1, 1, n, ind, ind, val); 
            cout << query(1, 1, n, 1, n) << endl;
        } else {
            int val;
            cin >> val;
            update(1, 1, n, 1, n, val);  
            cout << query(1, 1, n, 1, n) << endl;            
        }
    }
}

signed main(){
    fast();
    int T=1; 
    // cin >> T;
    for(int t = 1; t <= T; t++){
        solve(t);
    }
    return 0;
}
