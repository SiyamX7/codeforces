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
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);

    for(ll i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end(), greater<>());

    if(*v.rbegin() > k){
        cout << n << endl;
        return;
    }

	ll count = 0;

	ll l = 0, r = n -1 ;

    while(l < r){
        ll need = k / v[l] + 1;

        if(r - l + 1 < need) break;

        count++;
        l++;
        r -= (need - 1);
    }

    cout << count << endl;
}

int main() {
    fast(); 

    int t = 1;
    // cin >> t; 

    while (t--) solve();
}
    