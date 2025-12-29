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
    ll n, x, k;
    cin >> n >> x >> k;
    string s;
    cin >> s;

    ll count = 0;

    ll j = 0;
    for(ll i = 0; i < k; i++){
    	
    	if(j == n){
    		break;
    	} else if(s[j] == 'L'){
    		x--;
    		j++;
    	} else if(s[j] == 'R'){
    		x++;
    		j++;
    	}

    	if(x == 0) {
    		count++;
    		break;
    	}
    }

    bug(j);
   	if(!count){
   		cout << 0 << endl;
   	} else {
   		k -= j;

   		ll lc = 0, rc = 0;
   		ll need = 0;

   		for(int i = 0; i < n; i++){
   			if(s[i] == 'L') lc++;
   			else rc++;

   			if(lc > 0 && lc == rc){
   				need = lc + rc;
   				break;
   			}	
   		}

   		if(!need) 
   			cout << 1 << endl;
   		else 
   			cout << 1 + k / need << endl;
   	}
}

int main() {
    fast(); 

    int t = 1;
    cin >> t; 

    while (t--) solve();
}
    