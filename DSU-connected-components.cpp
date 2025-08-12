#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int parent[N];

int find(int v){
	if(parent[v] == v) return v;

	return parent[v] = find(parent[v]);
}

bool Union(int u, int v){
	u = find(u);
	v = find(v);

	if(u == v){
		return false;
	} // duijoner parent same, mane duijon same
	//component er under e;

	parent[u] = v;
	return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   
   	int n, e;
   	cin >> n >> e;

   	for(int i = 1; i <= n; i++) parent[i] = i;
   	int components = n;

   	for(int i = 0; i < e; i++){
   		int u, v;
   		cin >> u >> v;

   		if(Union(u, v)){
   			components--;
   			//jehetu same comp, tai 
   			// component komiye dilam
   		}
   	}

   	cout << "No. of components: " << components << endl;
}
