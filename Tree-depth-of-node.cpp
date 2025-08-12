#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> tree[N];
// vector<bool> visited(N,false);
int depth[N];

void dfs(int curr, int parent){
	// visited[curr] = true;
	depth[curr] = 1 + depth[parent];

	for(int ngbr : tree[curr]){
		if(ngbr == parent) continue;
		dfs(ngbr, curr);
	}
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   	
   	int n;
   	cin >> n;
   	for(int i = 0; i < n-1; i++){
   		int x,y;
   		cin >> x >> y;
   		tree[x].push_back(y);
   		tree[y].push_back(x);
   	}

   	dfs(1,0); //root, parent
   	for(int i = 1; i <= n; i++){
   		cout << "Depth of " << i << " : " << depth[i] << endl;
   	}
}
