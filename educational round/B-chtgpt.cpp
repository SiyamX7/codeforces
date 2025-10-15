#include <bits/stdc++.h>
using namespace std;

using ll = long long;                
using vi = vector<int>;
using vb = vector<bool>;             
using vll = vector<long long>;       
using pii = pair<int, int>;          
using pll = pair<long long, long long>; 

#define pb  push_back                                 
#define endl '\n'  
#define debug(x) cerr << #x << " = " << x << endl                 

const int MOD = 1e9 + 7;            
const ll INF = 1e18;                

void fast() {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
template <typename T>
void print(const vector<T>& vec) {for (const auto& val : vec) {cout << val << " ";}cout << endl;}

void solve(){
    string s; cin >> s;
    int q; cin >> q;

    while(q--){
    	int l, r , k;
    	cin >> l >> r >> k;
    	l--, r--;

    	int sz = r - l + 1;
		k %= sz;


		s = s.substr(0,l) +
			s.substr(r - k + 1, k) +
			s.substr(l, sz-k) +
			s.substr(r+1);
	}
	
	cout << s << endl;
}

int main() {
    fast(); 

    int t; 
    t = 1;
    // cin >> t; 

    while (t--) solve();
}
    