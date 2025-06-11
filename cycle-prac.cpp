#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> graph[N];
bool visited[N];
bool isCycle = false;

void dfs(int src, int parent){
	visited[src] = true;

	for(int ngbr : graph[src]){
		if(ngbr == parent) continue;

		if(visited[ngbr]){
			isCycle = true;
			return;
		} else {
			dfs(ngbr,src);
		}
	}
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	
	int n, e;
	cin >> n >> e;

	for(int i = 0; i < e; i++){
		int x,y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	dfs(1, -1);
	cout << (isCycle ? "Cycle" : "No Cycle");
}
