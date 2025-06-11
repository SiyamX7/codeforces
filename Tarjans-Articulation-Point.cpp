#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> graph[N];
vector<bool> visited(N,false);
int dis[N], low[N], timer = 0;
set<int> ap;


//shob shomoy current ke update korbo, onner ta
// kn update korte jabo.
// shudhu unvisited node ke children bolte parbo

void dfs(int curr, int parent){
	visited[curr] = true;
	dis[curr] = low[curr] = ++timer;
	int children = 0;

	for(int dest : graph[curr]){
		if(dest == parent) continue;

		if(!visited[dest]){
			dfs(dest,curr);
			low[curr] = min(low[curr], low[dest]);
			children++;

			if(parent != -1 && low[curr] <= dis[dest]){
				ap.insert(curr);
			}

		} else {
			low[curr] = min(low[curr], dis[dest]);
		}
	}

	if(parent == -1 && children > 1) {
		ap.insert(curr);
	}
}

void ArticulationPoint(int n){
	for(int i = 0; i < n; i++){
		if(!visited[i]){
			dfs(i,-1);
		}
	}

	cout << "ArticulationPoints: " << endl;
	for(int x : ap){
		cout << x << " ";
	}
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, e;
    cin >> n >> e;
    for(int i = 0; i < e; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    ArticulationPoint(n);
}
