#include <bits/stdc++.h>
using namespace std;

#define ll  long long              
#define pb  push_back
#define eb  emplace_back                                 
#define bug(x) cerr << #x << " = " << x << endl                 
 
void fast() {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
template <typename T>
void print(const vector<T>& vec) {for (const auto& val : vec) {cout << val << " ";}cout << endl;}

const int N = 2e5+10;

vector<ll> tree[N];
unordered_map<ll,ll> parent;
unordered_map<ll,set<ll> > seen;

void dfs(ll par, ll curr){
	parent[curr] = par;

	for(ll ngbr : tree[curr]){
		dfs(curr, ngbr);
	} 
}

void create(ll n){
	for(ll i = 1; i <= n; i++){
		ll temp = i;
		   while(parent[temp] != -1){
		   		seen[temp].insert(parent[temp]);
		   }
	}
}

void pr(){
	    ll u, v;
    	cin >> u >> v;

    	if(u == v) {
    		cout << "NO" << endl;
    		return;
    	}

    	if(seen[v] == u){
    		cout << "YES" << endl; 
    		// cout << seen[v] << endl;
    		return;
    	}

    	while(parent[v] != -1){
    		if(parent[v] == u){
    			cout << "YES" << endl;
    			seen[v] = u;
    			return;
    		} else {
    			v = parent[v];
    		}
    	}

    	cout << "NO" << endl;
}

void solve(){
    ll n;
    cin >> n;
    for(int i = 0; i < n-1; i++){
    	ll x,y;
    	cin >> x >> y;
    	tree[x].pb(y);
    }

    dfs(-1, 1);


    // for(auto [x,y] : parent){
    // 	cout << x << " " << y << endl;
    // }
    ll q; cin >> q;

    while(q--){
    	pr();
    }
}

int main() {
    fast(); 

    int t = 1;
    // cin >> t; 

    while (t--) solve();
}
    