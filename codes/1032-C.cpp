#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));

    int mx = 0;
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < m; j++){
    		cin >> grid[i][j];
    		mx = max(mx,grid[i][j]);
    	}
    }

    int count = 0;
    vector<int> row(n), col(m);
    
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < m; j++){
    		if(grid[i][j] == mx){
    			count++;
    			row[i]++;
    			col[j]++;
    		}
    	}
    }
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < m; j++){
    		if(row[i] + col[j] - (grid[i][j] == mx) == count){ // (grid[i][j] == mx) je row,col select korsi tader intersect point e mx ache kina, karon shekhetre 2 bar count hobe
    			cout << mx - 1 << endl;
    			return;
    		}
    	}
    }

   	cout << mx << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) solve();
}   