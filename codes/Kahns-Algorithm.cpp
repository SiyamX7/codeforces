#include <bits/stdc++.h>
#include <queue>
using namespace std;

vector<int> KahnsTopoSort(vector<vector<int>> &adj){
	int n = adj.size();

	vector<int> inDegree(n, 0);

	for(int i = 0; i < n; i++){
		for(int v : adj[i]){
			inDegree[v]++;
		}
	}

	queue<int> q;
	for(int i = 0; i < n; i++){
		if(inDegree[i] == 0) 
			q.push(i);
	}

	vector<int> topo;

	while(!q.empty()){
		int u = q.front(); q.pop();
		topo.push_back(u);

		for(int v : adj[u]){
			inDegree[v]--;
			if(inDegree[v] == 0) 
				q.push(v);
		}
	}

	if(topo.size() != adj.size()){
		cout << "Graph contains cycle." << endl;
		return {};
	}

	return topo;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<vector<int>> adj(4);

    adj[0] = {1,2};
    adj[1] = {3};
    adj[2] = {3};

    vector<int> topo = KahnsTopoSort(adj);

    for(auto x : topo) cout << x << " ";
}   

			1
		   / \
		  /   \
		 2	   3