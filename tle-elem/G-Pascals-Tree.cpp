#include <bits/stdc++.h>
using namespace std;

const int LOG = 20;
vector<vector<int>> adj;
vector<vector<int>> up;
vector<int> depth;

void dfs(int node, int parent) {
  up[node][0] = parent;
  for (int i = 1; i < LOG; i++) up[node][i] = up[up[node][i - 1]][i - 1];

  for (int child : adj[node]) {
    if (child == parent) continue;
    depth[child] = depth[node] + 1;
    dfs(child, node);
  }
}

int kthAncestor(int node, int k) {
  for (int i = 0; i < LOG; i++)
    if (k & (1 << i)) node = up[node][i];
  return node;
}

int lca(int a, int b) {
  if (depth[a] < depth[b]) swap(a, b);
  int diff = depth[a] - depth[b];
  a = kthAncestor(a, diff);
  if (a == b) return a;
  for (int i = LOG - 1; i >= 0; i--) {
    if (up[a][i] != up[b][i]) {
      a = up[a][i];
      b = up[b][i];
    }
  }
  return up[a][0];
}

void solve() {
  int n;
  cin >> n;

  adj.assign(n + 1, vector<int>());
  up.assign(n + 1, vector<int>(LOG));
  depth.assign(n + 1, 0);

  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];

  depth[1] = 0;
  dfs(1, 1);

  long long sum0 = accumulate(v.begin(), v.end(), 0LL);
  cout << sum0 << " ";

  vector<int> cur = v;

  while (cur.size() > 1) {
    vector<int> next;
    long long s = 0;
    for (int i = 0; i + 1 < cur.size(); i++) {
      int x = lca(cur[i], cur[i + 1]);
      next.push_back(x);
      s += x;
    }
    if (next.empty()) break;
    cout << s << " ";
    cur = next;
  }

  cout << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) solve();
}
