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
    ll x, n;
    cin >> x >> n;

    ll r = n % 4;
    ll ans = x;

    if(r == 0){
    	ans = x;
    } 

    if(r == 1) {
    	if(x % 2 == 0){
    		ans = x - n;
    	} else {
    		ans = x + n;
    	}
    }

    if(r == 2) {
    	if(x % 2 == 0){
    		ans = x + 1;
    	} else {
    		ans = x - 1;
    	}
    }

    if(r == 3){
    	if(x % 2 == 0){
    		ans = x + n + 1;
    	} else {
    		ans = x - n - 1;
    	}    	
    }

    cout << ans << endl;

}

int main() {
    fast(); 

    int t = 1;
    cin >> t; 

    while (t--) solve();
}
    