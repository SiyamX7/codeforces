#include <bits/stdc++.h>
#include <numeric>
using namespace std;

#define ll  long long              
#define pb  push_back
#define eb  emplace_back                                 
#define bug(x) cerr << #x << " = " << x << endl                 
 
void fast() {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
template <typename T>
void print(const vector<T>& vec) {for (const auto& val : vec) {cout << val << " ";}cout << endl;}

void solve(){
    ll n;
    cin >> n;
    ll a = 1;
    ll b = n - 1;

    for(ll i = 2; i * i <= n; i++){
        if(n % i == 0){
            a = n / i;
            b = n - a;
            break;
        }
    }

    cout << a << " " << b << endl;
}

int main() {
    fast(); 

    int t = 1;
    cin >> t; 

    while (t--) solve();
}
    