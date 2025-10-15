#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<int>> vis(n, vector<int>(m, -1));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }

    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,-1,1};

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){

            if(grid[i][j] == '.' && vis[i][j] == -1){
                queue<pair<int,int>> q;
                stack<pair<int,int>> s;

                q.push({i,j});
                s.push({i,j});
                vis[i][j] = 0;
                int wall = 0;

                while(!q.empty()){
                    auto [x,y] = q.front(); q.pop();

                    for(int k = 0; k < 4; k++){
                        int nx = x + dx[k];
                        int ny = y + dy[k];

                        if(nx >= 0 && nx < n && ny >= 0 && ny < m){

                            if(vis[nx][ny] == -1 && grid[nx][ny] == '.'){
                                q.push({nx,ny});
                                s.push({nx,ny});
                                vis[nx][ny] = 0;
                            }

                            if(grid[nx][ny] == '*') {
                                wall++;
                            }
                        }
                    }
                }

                while(!s.empty()){
                    auto [x,y] = s.top(); s.pop();
                    vis[x][y] = wall;
                }
            }
        }
    }

    while(k--){
        int x, y;
        cin >> x >> y;
        x--, y--;

        cout << vis[x][y] << endl;
    }
}   