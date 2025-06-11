#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
vector<int> graph[N];
bool visited[N];
bool isCycle = false;

void dfs(int node, int parent){
	visited[node] = true;

	for(int ngbr : graph[node]){
		if(ngbr == parent) continue;

		if(visited[ngbr]){
			isCycle = true;
			return;
		} else {
			dfs(ngbr, node);
		}
	}
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	
	int m, n;
	cin >> m >> n;

	for(int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	for(int i = 1; i <= m; i++){
		if(!visited[i]){
			dfs(i,-1);
		}
	}

	cout << (isCycle ? "yes" : "no") << endl;

}
