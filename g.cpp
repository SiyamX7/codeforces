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
    ll n, m; 
    cin >> n >> m;
    vector<vector<ll>> v(n, vector<ll>(m));

    ll r = 0, c = 0;
    ll mxr = 0, mxc = 0;

    for(int i = 0; i < n; i++){
    	for(int j = 0; j < m; j++){
    		cin >> v[i][j];
    	}
    }

    vector<ll> rows(n), cols(m);
    for(int i = 0; i < n; i++){
    	ll val = 0;
    	for(int j = 0; j < m; j++){
    		val ^= v[i][j];
    	}
    	rows[i] = val;
    	if(val > mxr){
    		mxr = val;
    		r = i;
    	}
    }

    for(int j = 0; j < m; j++){
    	ll val = 0;
    	for(int i = 0; i < n; i++){
    		val ^= v[i][j];
    	}
    	cols[j] = val;
    	if(val > mxc){
    		mxc = val;
    		c = j;
    	}
    }

    // ll prev = accumulate(rows.begin(), rows.end(), 0);
    // prev += ac

    ll intersect = v[r][c];

    ll change1 = (mxr ^ intersect) ;
    ll change2 = (mxc ^ intersect);
    
    // cout << change1 << " " << change2 << endl;

    ll ans1 = 0;
    v[r][c] = change1;

    for(int i = 0; i < n; i++){
        ll val = 0;
        for(int j = 0; j < m; j++){
            val ^= v[i][j];
        }
        ans1 += val;
    }    

    for(int j = 0; j < m; j++){
        ll val = 0;
        for(int i = 0; i < n; i++){
            val ^= v[i][j];
        }
        ans1 += val;
        }

    ll ans2 = 0;
    v[r][c] = change2;

    for(int i = 0; i < n; i++){
        ll val = 0;
        for(int j = 0; j < m; j++){
            val ^= v[i][j];
        }
        ans2 += val;
    }    

    for(int j = 0; j < m; j++){
        ll val = 0;
        for(int i = 0; i < n; i++){
            val ^= v[i][j];
        }
        ans2 += val;
        }
    // for(int i = 0; i < n; i++){
    // 	if(i == r){
    // 		ll x = (rows[i] ^ change ^ intersect);
    // 		ans += x;
    // 	} else {
    // 		ans += rows[i];
    // 	}
    // }

    // for(int i = 0; i < m; i++){
    // 	if(i == c){
    // 		ll x = (cols[i] ^ change ^ intersect);
    // 		ans += cols[i];
    // 	}
    // }

    // cout <<  change << endl;
        // cout << "ans1 : " << ans1 << " ans2 : " << ans2 << endl;
    cout <<  min(ans1, ans2) << endl;

}

int main() {
    fast(); 

    int t = 1;
    cin >> t; 

    while (t--) solve();
}
    