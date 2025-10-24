#include <bits/stdc++.h>
#include <functional>
using namespace std;

#define ll  long long              
#define pb  push_back
#define eb  emplace_back                                 
#define bug(x) cerr << #x << " = " << x << endl                 
 
void fast() {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
template <typename T>
void print(const vector<T>& vec) {for (const auto& val : vec) {cout << val << " ";}cout << endl;}

void solve(){
    int n, m, i, j;
    cin >> n >> m >> i >> j;
    vector<pair<int,int>> v = {{1,1}, {1,m}, {n,1}, {n,m}};
    vector<pair <int,int>> dist;

    for(int k = 0; k < 4; k++){
    	int d = abs(v[k].first - i) + abs(v[k].second - j);
    	dist.pb({d,k});
    }

    sort(dist.begin(), dist.end(), greater<>());

    cout << v[dist[0].second].first << " " << v[dist[0].second].second << " " << v[dist[1].second].first << " " << v[dist[1].second].second << endl;
}

int main() {
    fast(); 

    int t = 1;
    cin >> t; 

    while (t--) solve();
}
    