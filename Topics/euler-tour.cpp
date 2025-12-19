#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
int in[100005], out[100005], timer=0;

void dfs(int u,int parent){
    in[u] = timer++;
    for(int v: adj[u]){
        if(v==parent) continue;
        dfs(v,u);
    }
    out[u] = timer++;
}

bool isAncestor(int u,int v){
    return in[u]<=in[v] && out[v]<=out[u];
}

int main(){
    int n; cin>>n;
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1,0); // assume root = 1

    int q; cin>>q;
    while(q--){
        int u,v; cin>>u>>v;
        if(isAncestor(u,v)) cout<<u<<" is ancestor of "<<v<<"\n";
        else cout<<u<<" is NOT ancestor of "<<v<<"\n";
    }
}
