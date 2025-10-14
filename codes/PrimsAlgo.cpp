#include <bits/stdc++.h>
#include <functional>
#include <queue>
#include <vector>
using namespace std;
#define pii pair<int,int>

//FOR DENSE GRAPH
// EDGE BESHI, NODES KOM

const int N = 1e5 + 10;
const int INF = 1e9;

vector<pii> graph[N];
vector<bool> visited(N, false);
vector<int> parent(N, -1);
vector<int> dist(N,INF);

int Prims(int src){
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	
	pq.push({0,src});
	dist[src] = 0;

	int cost = 0;
	while(!pq.empty()){
		int c = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if(visited[node]) continue;

		visited[node] = true;
		cost += c;
		// cout << cost << endl;

		for(auto [w,dest] : graph[node]){
			if(!visited[dest] && w < dist[dest]){
				pq.push({w,dest});
				parent[dest] = node;
			}
		}
	}
	return cost;
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

    // for(int i = 0; i < n; i++){
    // 	cout << "for " << i << " : " ;
    // 	for(int j = 0; j < graph[i].size(); j++){
    // 		cout << graph[i][j].second << "\t";
    // 	}
    // 	cout << endl;
    // }
    cout << Prims(1) << endl;

    // for(int i = 0; i < n; i++){
    // 	cout << visited[i] << " ";
    // }

        cout << "Edges in MST:\n";
    	for(int i = 0; i < n; i++){
        // i এর parent কে MST তে edge গঠন করে
       		if(parent[i] != -1)
            	cout << parent[i] << " - " << i << "\n";
    }
}
