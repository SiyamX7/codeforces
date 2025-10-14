#include <bits/stdc++.h>
#include <queue>
using namespace std;

const int N = 1e5;
vector<int> graph[N];
vector<bool> visited(N,false);
int dist[N];

void bfs(int node){
	queue<int> q;
	q.push(node);
	dist[node] = 0;

	while(!q.empty()){
		int s = q.front(); q.pop();

		for(int x : graph[s]){
			if(visited[x]) continue;
			visited[x] = true;
			dist[x] = dist[s] + 1;
			q.push(x);
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

   	bfs(0);

   	for(int i = 0; i < n; i++){
   		cout << dist[i] << " ";
   	}
}
