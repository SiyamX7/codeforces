#include <bits/stdc++.h>
#include <queue>
#include <utility>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    
    int n = 5, m = 5;
   	vector<vector<int>> g = {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0}
    };

    int sr = 0, sc = 0;
    vector<vector<int>> dist(n, vector<int>(m, -1));

    queue<pair<int,int>> q; // x, y
    q.push({sr, sc});
    dist[sr][sc] = 0;

    while (!q.empty()) {
    	auto [x, y] = q.front(); q.pop();

    	for(int i = 0; i < 4; i++){
    		int nx = x + dx[i];
    		int ny = y + dy[i];


    		if(nx >= 0 && ny >= 0 && nx < n && ny < m && g[nx][ny] == 0 && dist[nx][ny] == -1){
    			dist[nx][ny] = dist[x][y] + 1;
    			q.push({nx, ny});
    		}
    	}
    }

    int er = 4, ec = 4;
    cout << dist[er][ec] << endl;
}   

