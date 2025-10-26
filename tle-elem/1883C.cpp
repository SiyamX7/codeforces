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
    ll prod = 1;
    vector<ll> v(n);

    ll mn = INT_MAX;
    ll even = 0;

    for(int i = 0; i < n; i++){
    	cin >> v[i];

    	if(v[i] % 2 == 0) even++;
    	if(v[i] % k == 0) mn = 0;
    	mn = min(mn, k - v[i] % k);
    }

    if(mn == 0){
    	cout << 0 << endl;
    	return;
    }

    if(k == 4){
    	if(even >= 2){
    		mn = min(mn, 0LL);	
    	} else if(even == 1){
    		mn = min(mn, 1LL);
    	} else if(even == 0){
    		mn = min(mn, 2LL);
    	}
    }

    cout << mn << endl;
}

int main() {
    fast(); 

    int t = 1;
    cin >> t; 

    while (t--) solve();
}