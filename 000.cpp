#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define vb vector<bool>
#define fast ios::sync_with_stdio(0); cin.tie(0);
#define pb push_back

bool isSquare(ll x){
    ll r = sqrtl(x);
    return r * r == x;
}

using namespace std;                   

int main() {
    fast;

    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;

        if(isSquare(n * (n+1) / 2)) {
            cout << -1 << endl;
            continue;
        }

        vll v(n);
        iota(v.begin(), v.end(), 1);
        ll sum = 0;
        for(ll i = 0; i < n; i++){
            sum += v[i];
            if(isSquare(sum)){
                sum -= v[i];
                sum += v[i+1];
                swap(v[i], v[i+1]);
            } 
        }
        for(ll x : v) cout << x << " ";
        cout << endl;
    }
}