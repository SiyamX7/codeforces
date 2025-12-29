#include <algorithm>
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
    int n; cin >> n;
    string s; cin >> s;

    vector<int> v(n,0);
    for(int i = 0; i < n; i++){
    	v[i] = s[i] - 'a';
    }

    if(is_sorted(v.begin(), v.end())){
    	cout << "NO" << endl;
    	return;
    } 
    
    for(int i = 0; i < n-1; i++){
    	if(v[i] > v[i+1]){
    		cout << "YES" << endl;
    		cout << i+1 << " " << i+2 << endl;
    		return;
    	}
    }
}

int main() {
    fast(); 

    int t = 1;
    // cin >> t; 

    while (t--) solve();
}
    