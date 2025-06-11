#include <bits/stdc++.h>
#include <functional>
#include <queue>
#include <vector>
using namespace std;
#define pii pair<int,int>
const int N = 1e5 + 10;
vector<pii> graph[N];
vector<int> dist(N,1e9);

void dijkstra(int src){
	priority_queue<pii, vector<pii>, greater<pii>> pq;

	dist[src] = 0;
	pq.push({0,src});

	while(!pq.empty()){
		int d = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if(d < dist[node]) continue;

		for(auto ngbr : graph[node]){
			int wt = ngbr.first;
			int n = ngbr.second;

			if(wt + dist[node] < dist[n]){
				dist[n] = wt + dist[node];
				pq.push({dist[n],n});
			}
		}
	}
}

 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	
	int n, e;
	cin >> n >> e;

	for(int i = 0; i < e; i++){
		int x,y,w;
		cin >> x >> y >> w;
		graph[x].push_back({w,y});
		graph[y].push_back({w,x});
	}   

	dijkstra(1);
	for(int i = 1; i <= n; i++){
		cout << i << " = " << dist[i] << endl;
	}
}
