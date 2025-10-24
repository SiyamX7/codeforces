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

   	ll sum = 0;
   	ll gg = 0;

   	for(ll i = 0; i < n; i++){
   		int x; 
   		cin >> x;
   		sum += x;
   		gg += ((x + k - 1) / k);
   	}

   	cout << (sum + k - 1)/ k << " " << gg << endl;
}

int main() {
    fast(); 

    int t = 1;
    cin >> t; 

    while (t--) solve();
}
    