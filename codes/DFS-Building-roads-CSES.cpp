#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
vector<int> graph [N];
bool visited[N];

void dfs(int start){
	visited[start] = true;

	for(int x : graph[start]){
		if(!visited[x]){
			dfs(x);
		}
	}
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int n,m;
	cin >> n >> m;

	for(int i = 0; i < m; i++){
		int x,y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	vector<int> road;

	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			road.push_back(i);
			dfs(i);
		}
	}

	cout << road.size() - 1 << endl; // koyta road banate hobe
	for(int i = 1; i < road.size(); i++){
		cout << road[i-1] << " " << road[i] << endl; //kader kader majhe road banate hobe
	}
}
