#include <bits/stdc++.h>
#include <functional>
#include <queue>
#include <vector>
using namespace std;
#define pii pair<int,int>

struct Edge {
	int u, v, w;
};

const int N = 1e5 + 10;
const int INF = 1e9;
vector<pii> graph[N];
vector<int> dist(N,INF);

void dijkstra(int node){
	dist[node] = 0;

	priority_queue <pii, vector<pii>, greater<pii>> pq;
	pq.push({0, node}); // dist of node = 0, and the node we are working with

	while(!pq.empty()){
		int d = pq.top().first;
		int u = pq.top().second;
		pq.pop();

		if(d > dist[u]) continue; // d hoitese current weight

		for(auto [w,v] : graph[u]){
			if(dist[u] + w < dist[v]){
				dist[v] = dist[u] + w;
				pq.push({dist[v],v});
			}
		}
	}
}

vector<Edge> edges;
vector<int> bellmandist;

void bellmanFord(int v,int src, vector<Edge> &edges){
	bellmandist[src] = 0;
	for(int i = 1; i <= v-1; i++){
		for(auto e : edges){
			if(bellmandist[e.u] != INF && bellmandist[e.u] + e.w < bellmandist[e.v]){
				bellmandist[e.v] = bellmandist[e.u] + e.w; 
			}
		}
	}
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	
	int n, e;
	cin >> n >> e;

	// for(int i = 0; i < e; i++){
	// 	int x,y,w;
	// 	cin >> x >> y >> w;
	// 	graph[x].emplace_back(w,y);
	// }
	
	edges.resize(e);
	bellmandist.assign(n+1,INF);

	for(int i = 0; i < e; i++){
		cin >> edges[i].u >> edges[i].v >> edges[i].w;
	}

	// dijkstra(1);
	// for(int i = 1; i <= n; i++){
	// 	cout << "distance to node " << i << " is : " << dist[i] << endl; 
	// }

	bellmanFord(n, 1, edges);
	for(int i = 1; i <= n; i++){
		cout << bellmandist[i] << endl;
	}
}
