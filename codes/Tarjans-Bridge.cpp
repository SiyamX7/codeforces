#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector <int> graph[N];
vector <bool> visited(N,false);
int dis[N], low[N];

void dfs(int curr, int parent, int time){
	visited[curr] = true;
	dis[curr] = low[curr] = ++time;

	for(int ngbr : graph[curr]){
		if(ngbr == parent) continue;

		if(!visited[ngbr]){
			dfs(ngbr,curr,time);
			low[curr] = min(low[curr], low[ngbr]);

			if(dis[curr] < low[ngbr]){
				cout << "bridge : " << curr << " <> " << ngbr << endl;
			}

		} else {
			low[curr] = min(low[curr], dis[ngbr]);
		}

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
   	for(int i = 0; i < n; i++){
   		if(!visited[i]){
   			dfs(0,-1,0);
   		}
   	}
}
