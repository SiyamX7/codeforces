#include <bits/stdc++.h>
#include <iterator>
using namespace std;

#define ll unsigned long long              
#define pb  push_back
#define eb  emplace_back                                 
#define bug(x) cerr << #x << " = " << x << endl                 
 
void fast() {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
template <typename T>
void print(const vector<T>& vec) {for (const auto& val : vec) {cout << val << " ";}cout << endl;}

void solve(){
    ll n;
    cin >> n;

    ll ans = 0;

    while(n % (ans + 1) == 0) ans++;

    // 1 theke shuru korle shob cheye boro interval pawa jabe

    cout << ans << endl;
}

int main() {
    fast(); 

    int t; 
    // t = 1;
    cin >> t; 

    while (t--) solve();
}
    