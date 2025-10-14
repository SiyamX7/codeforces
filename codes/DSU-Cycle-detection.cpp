#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int parent[N];

int find(int v){
	if(parent[v] == v) return v;

	return parent[v] = find(parent[v]);
}

bool Union(int a, int b){
	a = find(a);
	b = find(b);

	if(a == b) return true;
	parent[a] = b;
	return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  	
  	int n, e;
  	cin >> n >> e;
  	for(int i = 1; i <= n; i++) parent[i] = i;

  	bool cycle = false;
  	for(int i = 0; i < e; i++){
  		int a, b;
  		cin >> a >> b;
  		if(Union(a, b)){
  			cycle = true;
  			cout << "Cycle detected at : " << a << " - " << b << endl;  			
  		}
  	} 

  	if(!cycle) {
  		cout << "No cycle detected." << endl;
  	}

}
