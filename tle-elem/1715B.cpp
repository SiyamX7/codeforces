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
    ll n, k, b, s;
    cin >> n >> k >> b >> s;

    ll poss = (k * (b+1) - 1) + (k - 1) * (n - 1);
    if(s > poss || s < k * b){
    	cout << -1 << endl;
    	return;
    }

   	ll rem = s;

   	ll mxf = k * (b+1) - 1;

   	vector<ll> ans(n,0);

   	if(s <= mxf){
   		ans[0] = s;
   	} else {

   		ans[0] = mxf;
   		rem -= mxf;
   		for(ll i = 1; i < n; i++){
   			if(rem >= k){
   				ans[i] = k-1;
   				rem -= k-1;
   			} else {
   				ans[i] = rem;
   				break;
   			}
   		}

   	}

   	print(ans);
}

int main() {
    fast(); 

    int t = 1;
    cin >> t; 

    while (t--) solve();
}
    