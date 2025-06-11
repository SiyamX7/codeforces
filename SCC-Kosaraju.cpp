#include <bits/stdc++.h>
#include <stack>
#include <vector>
using namespace std;

const int N = 1e5;
vector<int> graph[N];
vector<int> rev[N];
vector <bool> vistop(N,false);
vector <bool> vis(N,false);
stack<int> s;
vector<vector<int>> sccs;

/*
	SCC Kosaraju algo te 3 ta kaj korte hobe.
	1. Topological Sorting -> node push
	2. Transpose matrix banate hobe
	3. Then DFS chalate hobe rev/transpose matrix e
*/

void topsort(int node){
	vistop[node] = true;
	for(int ngbr : graph[node]){
		if(!vistop[ngbr]){
			topsort(ngbr);
		}
	}
	s.push(node);
}

void dfs(int node,vector<int> &scc){
	scc.push_back(node);
	vis[node] = true;
	for(int ngbr : rev[node]){
		if(!vis[ngbr]){
			dfs(ngbr,scc);
		}
	}
}

void Kosaraju(int n){
	for(int i = 0; i < n; i++){
		if(!vistop[i]) topsort(i);
	}

	while(!s.empty()){
		vector<int> scc;
		int x = s.top();
		s.pop();
		if(!vis[x]){
			dfs(x, scc);
			sccs.push_back(scc);
		}
	}

	cout << "Total number of SCC is: " << sccs.size() << endl;
	int count = 1;
	for(auto scc : sccs){
		cout << count++ << " : ";
		for(auto x : scc){
			cout << x << " ";
		}
		cout << endl;
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
   		rev[y].push_back(x);
   }

    Kosaraju(n);
}
