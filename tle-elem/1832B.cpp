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

    vector<ll> v(n), pref(n+1);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    // print(v);

    for(int i = 1; i <= n; i++){
        pref[i] = pref[i-1] + v[i-1];
    }

    ll sum = 0;
    for(int x = 0; x <= k; x++){
        int y = k - x;

        ll ss = pref[n-y] - pref[2*x];
        sum = max(sum, ss);
    }

    cout << sum << endl;
    // print(pref);

}

int main() {
    fast(); 

    int t = 1;
    cin >> t; 

    while (t--) solve();
}
    