#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5;
vector<vector<int>> graph;
vector<vector<bool>> visited;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

void dfs(int x,int y, int n, int e){
	visited[x][y] = true;
	for(int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx < n && ny < e && nx >= 0 && ny >= 0 && graph[nx][ny] == 1 && !visited[nx][ny])
		dfs(nx,ny, n, e);
	}
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	
    int n, e;
    cin >> n >> e;
    graph.assign(n,vector<int>(e));
    visited.assign(n,vector<bool>(e));

    for(int i = 0; i < n; i++){
    	for(int j = 0; j < e; j++){
    		cin >> graph[i][j];
    	}
    }
    int count = 0;
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < e; j++){
    		if(!visited[i][j] && graph[i][j] == 1){
    			dfs(i, j, n, e);
    			count++;
    		}
    	}
    }

    cout << count << endl;

}
