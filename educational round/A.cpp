#include <bits/stdc++.h>
using namespace std;
#define  ll long long

void solve(){
    ll n; cin >> n;
    ll temp = n;
    ll count = 0;
    while(temp > 0){
        temp /= 2;
        count++;
    }

    ll x = n * (n+1) / 2;
    ll sub = (1 << count) - 1 ;
    cout << x - 2 * sub << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) solve();    
}   