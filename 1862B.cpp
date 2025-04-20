#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define vb vector<bool>
#define fast ios::sync_with_stdio(0); cin.tie(0);

using namespace std;                   

int main() {
    fast;
    ll t;
    cin >> t;
    while(t--){
    	ll n;
    	cin >> n;
    	vll v(n);
    	for(ll &i : v) cin >> i;

        vll vv; vv.push_back(v[0]);

        for(ll i = 1; i < n; i++){
            if(v[i - 1] <= v[i]){
                vv.push_back(v[i]);
            } else {
                ll y = v[i] - 2;
                if(y > 0){
                    vv.push_back(y);
                } else {
                    vv.push_back(v[i]);
                } 
                vv.push_back(v[i]);
            }
        }
        cout << vv.size() << endl;
        for(ll x : vv) cout << x << " ";
        cout << endl;
    }
}