#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
const int N = 1e5+10;
const int INF = 1e9;

vector<pii> graph[N];
vector<int> dist(N, INF);

void disjkstra(int src){
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	dist[src] = 0;
	pq.push({0,src}); //pushing dist of src and node src

	while(!pq.empty()){
		int d = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if(d > dist[node]) continue;// unvisited

		for(auto e : graph[node]){
			int x = e.first;
			int y = e.second;

			if(x + dist[node] < dist[y]){
				dist[y] = x + dist[node];
				pq.push({dist[y], y});
			}
		}
	}
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   	
   	int n,e;
   	cin >> n >> e;

   	for(int i = 0; i < e; i++){
   		int u,v,w;
   		cin >> u >> v >> w;
   		graph[u].push_back({w,v});
   		graph[v].push_back({w,u});
   	}

   	disjkstra(0);

   	for(int i = 1; i <= n; i++){
   		cout << "distance to node " << i << " is " << dist[i] << endl;
   	}
}
