#include <bits/stdc++.h>
using namespace std;

template <typename T>
void print(const vector<T>& vec) {
    for (const auto& val : vec) {
        cout << val << " ";
    }
    cout << endl;
}
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define ll long long                
#define vi vector<int> 
#define vb vector<bool>             
#define vll vector<long long>       
#define pii pair<int, int>          
#define pll pair<long long, long long> 
#define pb push_back                
#define mp make_pair                
#define all(v) v.begin(), v.end()  
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x.size())      
#define ff first                     
#define ss second                    
#define endl '\n'  
#define debug(x) cerr << #x << " = " << x << endl                 

const int MOD = 1e9 + 7;            
const ll INF = 1e18;                



int main() {
    fast; 
    int t;
    cin >> t;
    while(t--){
    	int n; cin >> n;
    	vll v(n); 
    	for(ll &val : v) cin >> val;

    	vll vv;
    	int i = 0;

    	while(i < n){
    		ll sum = 0;
    		if(v[i] < 0){
    			while(i < n && v[i] < 0){
    				sum += v[i];
    				i++;
    			}
    		}

    		else {
    			while (i < n && v[i] > 0) {
    				sum += v[i];
    				i++;
    			}
    		}
    		vv.push_back(sum);
    	}

    	ll total = 0;
    	ll mx = 0;
    	for(ll &val : vv){
    		if(abs(val) > mx) mx = abs(val);
    	}

    	int sz = vv.size() - 1;

    	if(vv[0] < 0 and vv[sz] > 0) {
            ll x = 
    		total = abs(v[0]) + abs(v[sz]) +
    	}

    }

    return 0;
}
    