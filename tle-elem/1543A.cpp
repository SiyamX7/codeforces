#include <bits/stdc++.h>
#include <climits>
#include <cstdlib>
using namespace std;

#define ll  long long              
#define pb  push_back
#define eb  emplace_back                                 
#define bug(x) cerr << #x << " = " << x << endl                 
 
void fast() {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
template <typename T>
void print(const vector<T>& vec) {for (const auto& val : vec) {cout << val << " ";}cout << endl;}

void solve(){
    ll a, b;
    cin >> a >> b;
    if(a == b){
    	cout << 0 << " " << 0 << endl;
    	return;
    }

    ll g = llabs(a - b);
    ll x = min(b % g, g - b % g);
    // b % g     --> koto komate hobe g er multiple er kache pouchate gele
    // g - b % g --> koto barate hobe g er next multiple e pouchate
    cout << g << ' ' << x << endl;
}

int main() {
    fast(); 

    int t = 1;
    cin >> t; 

    while (t--) solve();
}
    