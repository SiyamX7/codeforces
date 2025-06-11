#include <bits/stdc++.h>
#include <string>
using namespace std;

const int N = 1e5 + 10;
vector<int> graph[N];
bool visited[N];

void printAllPath(int curr, int tar, string path){
	if(curr == tar){
		cout << path << endl;
		return;
	}

	for(int ngbr : graph[curr]){
		if(!visited[ngbr]){
			visited[ngbr] = true;
			path += " " + to_string(ngbr);
			printAllPath(ngbr, tar, path);
			visited[ngbr] = false;
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

    printAllPath(1, 5, "1");
}
