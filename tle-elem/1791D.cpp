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
    int n; cin >> n;
    string s; cin >> s;

    vector<ll> pre(n), suf(n);
    unordered_set<char> x;

    for(ll i = 0; i < n; i++){
    	x.insert(s[i]);
    	pre[i] = x.size();
    }

    x.clear();

    for(ll i = n-1; i >= 0; --i){
    	x.insert(s[i]);
    	suf[i] = x.size();
    }

    ll ans = 0;

    for(ll i = 0; i < n-1; i++){
    	ans = max(ans, pre[i] + suf[i+1]);
    }

    cout << ans << endl;
}

int main() {
    fast(); 

    int t = 1;
    cin >> t; 

    while (t--) solve();
}
    