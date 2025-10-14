#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int parent[N], sz[N];

void make(int v){
	parent[v] = v;
	sz[v] = 1;
}

int find(int v){
	if(parent[v] == v) return v;

	return parent[v] = find(parent[v]);
}

void Union(int a, int b){
	a = find(a);
	b = find(b);

	if(a != b){
		if(sz[a] < sz[b]) swap(a,b);
		parent[b] = a; // ekhane boro a, choto b
		sz[a] += sz[b];
	}
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   	
   	int n = 6;
   	for(int i = 1; i <= n; i++) {
   		make(i);
   	}

   	Union(1, 2);
   	Union(3, 4);
   	Union(5, 6);
   	Union(1, 3);
   	Union(1 , 6);

   	for(int i = 1; i <= n; i++){
   		cout <<i << " : " << parent[i] << " " << sz[i] << endl;
   	}
}
