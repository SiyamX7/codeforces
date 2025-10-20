#include <bits/stdc++.h>
using namespace std;

#define ll long long              
#define pb  push_back
#define eb  emplace_back                                 
#define bug(x) cerr << #x << " = " << x << endl                 
 
void fast() {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
template <typename T>
void print(const vector<T>& vec) {for (const auto& val : vec) {cout << val << " ";}cout << endl;}

void solve(){
    int n ; cin >> n;
    vector<int> v(n);
    int count = 0;
    for(int i = 0; i < n; i++) {
    	cin >> v[i];
    	if(v[i] == 1) v[i]++;
    }

    for(int i = 0; i < n-1; i++){
    	if(v[i+1] % v[i] == 0){
    		v[i+1]++;
    	}
    }

    for(int i : v) cout << i << " ";
    cout << endl;
}

int main() {
    fast(); 

    int t; 
    // t = 1;
    cin >> t; 

    while (t--) solve();
}
    