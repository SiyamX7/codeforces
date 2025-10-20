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
	int n; cin >> n;
    string s; cin >> s;
    int mx = 1, count = 1;

    for(int i = 0; i < n; i++){
    	if(s[i] == s[i+1]){
    		count++;
    		mx = max(mx, count);
    	} else {
    		count = 1;
    	}
    }

    cout << ++mx << endl;
}

int main() {
    fast(); 

    int t; 
    // t = 1;
    cin >> t; 

    while (t--) solve();
}
    