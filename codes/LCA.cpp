#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int> tree[N];
vector<int> parent(N);
stack<int> st;

void dfs(int curr, int par){
	parent[curr] = par;

	for(int ngbr : tree[curr]){
		if(ngbr != par){
			dfs(ngbr,curr);
		}
	}
}

void path(int node,stack<int> &st){
	if(parent[node] == -1) return;
	path(parent[node],st);
	st.push(node);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++){
    	int x, y;
    	cin >> x >> y;
    	tree[x].push_back(y);
    	tree[y].push_back(x);
    }
    
    dfs(1,-1);
    stack<int> a, b;
    path(3,a);
    path(5,b);
    vector<int> aa,bb;
    while(!a.empty()){
    	aa.push_back(a.top());
    	a.pop();
    }
    while(!b.empty()){
    	bb.push_back(b.top());
    	b.pop();
    }

    sort(aa.begin(), aa.end());
    sort(bb.begin(), bb.end());

    int ans = 0;
    for(int i = 0; i < aa.size(); i++){
    	if(aa[i] != bb[i]){
    		ans = aa[i-1];
    	}
    }

    cout << ans;
}   