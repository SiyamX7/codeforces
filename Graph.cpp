#include <bits/stdc++.h>
#include <functional>
#include <queue>
#include <vector>
#define pii pair<int,int>
using namespace std;

const int N = 1e5 + 10;
const int INF = 1e9;
vector <int> graph[N];
bool visited[N];
stack <int> st; // for topological sort

vector <pii> djk[N];
vector<int> dist(N,INF); //for dijkstra

// Custom comparator that we can use in priority queue.
struct comp {
    bool operator()(const pair<int,int> &a, const pair<int,int> &b){
        return a.second > b.second;
    }
};

/*
	Steps of DFS:
		1. print
		2. visited = true
		3. run DFS on neighbour
*/

void DFS(int node){
	visited[node] = true;
	cout << node << " ";

	for(int ngbr : graph[node]){ //neighbour of current node
		if(!visited[ngbr]){
			DFS(ngbr);
		}
	}
}

/* 
	Steps of BFS-->
		1. make a queue
		2. add the given node
		3. run untill q.empty()
		4. if q.front() is not visited, 
			--> print it
			--> mark as visited
			--> add all the neighbours of q.front()
*/
void BFS(int node){
	queue<int> q;
	q.push(node);

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		if(!visited[curr]){
			cout << curr << " ";
			visited[curr] = true;

			for(int ngbr : graph[curr]){
				q.push(ngbr);
			}
		}
	}
}

/*
	Steps of Topological Sorting:
		1. make a dfs code
		2. add the node to a stack
		3. print the whole stack, which is topologically sorted
*/

void TopologicalSort(int node){
	visited[node] = true;

	for(int ngbr : graph[node]){ //neighbour of current node
		if(!visited[ngbr]){
			TopologicalSort(ngbr);
		}
	}
	st.push(node); // stack tai sorted graph
}

/* Cycle in Graph:
	
	Directed Graph-->
		1. DFS
		2. BFS
		3. DSU

	Undirected Graph-->
		1. DFS
		2. BFS
		3. Topological Sort (Kahn's Algorithm)
*/

bool isCycle = false;

void DFS_Cycle(int node, int parent){
	visited[node] = true;

	for(int ngbr : graph[node]){
		if(ngbr == parent) continue;

		if(visited[ngbr]){
			isCycle = true;
			return;
		} else {
			DFS_Cycle(ngbr, node);
		}
	}
}

void dijkstra(int src){
	// priority_queue<data_type, container, comparator> pq;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	dist[src] = 0;

	pq.push({0,src}); // dist, node

	while(!pq.empty()){
		int dis = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		// new dist ager dist theke beshi hole skip, karon 
		//amra optimize kortesi ekhane
		if(dis > dist[node]) continue;

		for(auto edge : djk[node]){
			int d = edge.first;
			int n = edge.second;

			if(d + dist[node] < dist[n]){
				dist[n] = d + dist[node]; //relaxation
				pq.push({dist[n],n}); //update
			}
		}
	}
}

struct Edge{
	int u, v, w;
};

vector<Edge> ed; // From, To, Weight.
vector<int> dis;

/*
	vertices - 1 bar relaxation kora lagbe.
	pore jodi aro komano jay, tahole negative cycle ache.
	--> JEKHANE DIJKSTRA PARENA (NEGATIVE WEIGHT ER JONNO), shekhane 
		Bellman Ford algo valovabe kaj kore.
	--> Boro graph er jonno na, karon time complexity beshi O(V*E).
*/

bool BellmanFord(int src, int vertices, vector<Edge> &ed){
	dis[src] = 0;

	for(int i = 1; i <= vertices - 1; i++){
		for(auto [u,v,w] : ed){
			if(dis[u] != INF && dis[u] + w < dis[v]){
				dis[v] = dis[u] + w;
			}
		}
	}

	bool isNeg = false;

	for(auto [u,v,w] : ed){
		if(dis[u] != INF && dis[u] + w < dis[v]){
			isNeg = true;
			return isNeg;
		}
	}
	return isNeg;
}

/*
💡 Extra Tips:
1.Prim’s algorithm শুধুমাত্র connected undirected weighted graph এর জন্য কাজ করে। Disconnected hole MST possible না।

2.যদি MST বানিয়ে পুরো graph এর edge গুলো বের করতে চাও, তাহলে parent[] array রাখো।

3.MST তে সবসময় n-1 টা edge থাকবে।

*/

vector<pii> primsGraph[N];
vector<int> parent(N, -1);
vector<int> distt(N, INF);

int Prims(int src){
	priority_queue<pii, vector<pii>, greater<pii>> pq;

	distt[0] = 0;
	pq.push({0,src});

	int cost = 0;

	/* 
		'u' theke 'v' te jay, weight holo 'w'.
	*/

	while(!pq.empty()){
		auto[c,node] = pq.top();
		pq.pop();

		if(visited[node]) continue;

		visited[node] = true;
		cost += c;

		for(auto [w,dest] : primsGraph[node]){

			if(!visited[dest] && w < distt[dest]){
				
				distt[dest] = w; 
				parent[dest] = node;
				// new weight old weight er cheye kom hole 
				// weight update hobe ar tokhon e shudhu pq
				// te add hobe. ete priority queue te unnecessary
				// element add hobena.
				pq.push({w,dest});
			}
		}
	}
	return cost;
}

// #include <bits/stdc++.h>
// #include <stack>
// #include <vector>
// using namespace std;

// const int N = 1e5;
// vector<int> graph[N];
// vector<int> rev[N];
// vector <bool> vistop(N,false);
// vector <bool> vis(N,false);
// stack<int> s;
// vector<vector<int>> sccs;

// /*
// 	SCC Kosaraju algo te 3 ta kaj korte hobe.
// 	1. Topological Sorting -> node push
// 	2. Transpose matrix banate hobe
// 	3. Then DFS chalate hobe rev/transpose matrix e
// */

// void topsort(int node){
// 	vistop[node] = true;
// 	for(int ngbr : graph[node]){
// 		if(!vistop[ngbr]){
// 			topsort(ngbr);
// 		}
// 	}
// 	s.push(node);
// }

// void dfs(int node,vector<int> &scc){
// 	scc.push_back(node);
// 	vis[node] = true;
// 	for(int ngbr : rev[node]){
// 		if(!vis[ngbr]){
// 			dfs(ngbr,scc);
// 		}
// 	}
// }

// void Kosaraju(int n){
// 	for(int i = 0; i < n; i++){
// 		if(!vistop[i]) topsort(i);
// 	}

// 	while(!s.empty()){
// 		vector<int> scc;
// 		int x = s.top();
// 		s.pop();
// 		if(!vis[x]){
// 			dfs(x, scc);
// 			sccs.push_back(scc);
// 		}
// 	}

// 	cout << "Total number of SCC is: " << sccs.size() << endl;
// 	int count = 1;
// 	for(auto scc : sccs){
// 		cout << count++ << " : ";
// 		for(auto x : scc){
// 			cout << x << " ";
// 		}
// 		cout << endl;
// 	}
// }

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
   
//    int n, e;
//    cin >> n >> e;
//    for(int i = 0; i < e; i++){
//    		int x, y;
//    		cin >> x >> y;
//    		graph[x].push_back(y);
//    		rev[y].push_back(x);
//    }

		// or to make a rev graph from given graph
		// for(int i = 0; i < n; i++){
		// 	for(int v : graph[u]){
		// 		rev[v].push_back(u);
		// 	}
		// }

//     Kosaraju(n);
// }



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   	
   	// int n, m;
   	// cin >> n >> m;

   	// for(int i = 1; i <= m; i++){
   	// 	int x, y;
   	// 	cin >> x >> y;
   	// 	graph[x].push_back(y);
   	// 	graph[y].push_back(x);
   	// }

   	// cout << "BFS is: ";
   	// BFS(1);
   	// cout << endl;

   	// cout << "TopologicalSort is: ";
   	// TopologicalSort(1);
   	// while(!st.empty()){
   	// 	cout << st.top() << " ";
   	// 	st.pop();
   	// }
   	// cout << endl;

   	// int n, e;
   	// cin >> n >> e;

   	// vector<vector<pair<int,int>>> adj;
   	// for(int i = 0; i < e; i++){
   	// 	int x,y,w;
   	// 	cin >> x >> y >> w;
   	// 	adj[x].push_back({y,w});
   	// }

   	int n, e;
   	cin >> n >> e;
   	ed.resize(e);
   	dis.assign(n+1 , INF);

   	for(int i = 0; i < e; i++){
   		cin >> ed[i].u >> ed[i].v >> ed[i].w;
   	}

   	bool negativeCycle = BellmanFord(1, n , ed);
	cout << (negativeCycle ? "negativeCycle" : "no negativeCycle") << endl;

	for(int i = 1; i <= n; i++){
		cout << dis[i] << endl;
	}   	
}