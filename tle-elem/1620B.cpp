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
    ll w, h;
    cin >> w >> h;

    ll h1mn, h1mx, h2mn, h2mx, v1mn, v1mx, v2mn, v2mx;

    ll k; cin >> k;
    for(int i = 0; i < k; i++){
    	ll x; cin >> x;

    	if(i == 0){
    		h1mn = x;
    	}

    	if(i == k-1){
    		h1mx = x;
    	}
    }

  	cin >> k;
    for(int i = 0; i < k; i++){
    	ll x; cin >> x;

    	if(i == 0){
    		h2mn = x;
    	}

    	if(i == k-1){
    		h2mx = x;
    	}
    }    

    cin >> k;
    for(int i = 0; i < k; i++){
    	ll x; cin >> x;

    	if(i == 0){
    		v1mn = x;
    	}

    	if(i == k-1){
    		v1mx = x;
    	}
    }    

    cin >> k;
    for(int i = 0; i < k; i++){
    	ll x; cin >> x;

    	if(i == 0){
    		v2mn = x;
    	}

    	if(i == k-1){
    		v2mx = x;
    	}
    }

    cout << max({(h1mx-h1mn)* h, (h2mx-h2mn)* h, (v1mx-v1mn) * w, (v2mx-v2mn) * w}) << endl;
}

int main() {
    fast(); 

    int t = 1;
    cin >> t; 

    while (t--) solve();
}
    