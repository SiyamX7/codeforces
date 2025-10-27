#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define ll  long long              
#define pb  push_back
#define eb  emplace_back                                 
#define bug(x) cerr << #x << " = " << x << endl                 
 
void fast() {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
template <typename T>
void print(const vector<T>& vec) {for (const auto& val : vec) {cout << val << " ";}cout << endl;}

void solve(){
    ll n; cin >> n;
    vector<ll> x;
    vector<ll> y;

    for(int i = 0; i < n; i++){
    	int m; cin >> m;
    	vector<ll> temp(m);

    	for(int i = 0; i < m; i++) cin >> temp[i];
    	sort(temp.begin(), temp.end());
    	x.pb(temp[0]);
    	y.pb(temp[1]);
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    ll ans = 0;
    ans += x[0];

    for(int i = 1; i < y.size(); i++) ans += y[i];

    cout << ans << endl;
}

int main() {
    fast(); 

    int t = 1;
    cin >> t; 

    while (t--) solve();
}
    