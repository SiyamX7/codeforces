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
    int n; 
    cin >> n;
    vector<pair<ll,ll>> v(n+1);

    for(int i = 1; i <= n; i++){
    	int x; cin >> x;
    	v[i] = {x, i};
    }

    sort(v.begin() + 1, v.end(), greater<>());

    vector<ll> x(n+1);
    x[0] = 0;

    ll d = 1;
    ll cost = 0;

    for(int i = 1; i <= n; i++){
    	if(i % 2 == 1){
    		x[v[i].second] = d;
    	} else {
    		x[v[i].second] = -d;
    		d++;
    	}

    	cost += 2 * llabs(x[v[i].second]) * v[i].first;
    }

 
    cout << cost << endl;
    for(auto g : x) cout << g << " ";
    cout << endl;
}

int main() {
    fast(); 

    int t = 1;
    cin >> t; 

    while (t--) solve();
}
    