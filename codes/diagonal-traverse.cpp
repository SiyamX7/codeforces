#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int mat[3][3] = {
    				{1,2,3}, 
    				{4,5,6},
    				{7,8,9}
				    };

	vector<vector<bool>> visited(3, vector<bool>(3, false));

	queue<pair<int,int>> q;
	q.push({2,2});
	visited[2][2] = true;

	int dx[4] = {0,0,1,-1};
	int dy[4] = {1,-1,0,0};

	int count = 1;

    while(!q.empty()){
    	int sz = q.size();
    	vector<int> temp;

    	while (sz--) {
    		auto [x,y] = q.front(); q.pop();
    		

    		temp.push_back(mat[x][y]);
    		for(int i = 0; i < 4; i++){
    			int nx = x + dx[i];
    			int ny = y + dy[i];

    			if(nx >= 0 && ny >= 0 && nx < 3 && ny < 3){
    				if(!visited[nx][ny]){
    					visited[nx][ny] = true;
    					q.push({nx, ny});
    				}
    			}
    		}
    	}

    	if(count % 2 == 1){
    		reverse(begin(temp), end(temp));
    	}

    	for(int x : temp) {
    		cout << x << " ";
    	}
    	cout << endl;

    	count++;
    }
}   