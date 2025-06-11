#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void floydWarshall(vector<vector<int>> &dist, int n){
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				dist[i][j] = min(dist[i][j] ,dist[i][k]+dist[k][j]);
			}
		}
	}
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int n, e;
	cin >> n >> e;
	vector<vector<int>> dist(n+1, vector<int>(n+1,INF));

	for(int i = 0; i < e; i++){
		int u,v,w;
		cin >> u >> v >> w;
		dist[u][v] = w;
		dist[v][u] = w;
	}

	for(int i = 1; i <= n; i++){
		dist[i][i] = 0;
	}

	floydWarshall(dist, n);

	cout << "distance from 3 to 5 is : ";
	cout << dist[3][5] << endl;
}
